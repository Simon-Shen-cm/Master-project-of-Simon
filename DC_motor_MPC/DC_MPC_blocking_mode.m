% Blocking mode for DC motor MPC controller on STM32
%% Set serial port configuration
delete(instrfindall('Type','serial')); % clear all serial com info,otherwise it might fail to open serial port
stm_port=serial('/dev/tty.usbmodem141303','BaudRate',921600); 
%%
fclose(stm_port);
run('Startfile_M_DCmotor_MPC.m');

%!!!!!!!!!!!!!! Set t as a parameter!!!!!!!!!!!!!!!!!!!!!
t=18;       % how much time(s) do u want to simulate
%!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

points=t/SampleTime;    % amount of data points
i_old=0;        % old and initial values
w_old=0;
Vol_in=0;
DC_ia=zeros(1,points);  % current storage
DC_w=zeros(1,points);  % speed storage
Da=zeros(18,points); % data storage

fopen(stm_port);
Initial_Input=single([RefSpeed,Vol_in,i_old,Q0_DC_MPC,R0_DC_MPC,1]);
fwrite(stm_port,Initial_Input,'single');    %send the first data
    
for i=1:points          % main loop
    i
    ReBuf=fread(stm_port,9,'single');   % read triggers from STM32

    Input_32=single([RefSpeed,Vol_in,i_old,Q0_DC_MPC,R0_DC_MPC,1]); % next data to STM32
        
    Vol_in=H_Bridge(ReBuf(1:4));    % output voltage of H bridge
    LT= LTorqueGe(SampleTime,i);   % LoadTorque calulation
    [DC_ia(1,i),DC_w(1,i)]=DCMotor(Vol_in,LT,i_old,w_old); % motor model

    i_old=DC_ia(1,i);   % storage the values at this moment as the input for next time step
    w_old=DC_w(1,i);

    fwrite(stm_port,Input_32,'single');  % send motor states into STM32
    Da(10:18,i)=ReBuf;     % data stm 2 matlab
    Da(1:9,i)=Input_32;    % data matlab 2 stm
    
    clc;
end
 
fclose(stm_port);

t_p=1:points;           % generate figures
figure(1);
plot(t_p,DC_ia);        % current
legend('Current');
figure(2);
plot(t_p,DC_w*30/pi);   % speed
legend('Speed rmp');

function Voltage=H_Bridge(Trigger_in)   % output voltage of H bridge based on different triggers
Forward_V_drop=1;
if Trigger_in(1)==1
    if Trigger_in(3)==1
        Voltage=0;
    else
        Voltage=400-2*Forward_V_drop;
    end
else
    if Trigger_in(3)==1
        Voltage=-(400-2*Forward_V_drop);
    else
        Voltage=0;
    end
end
end

function [ia,w] = DCMotor(U_in,LTorque_in,ia_old,w_old) % motor state space function

A_d =[0.9996 -1.9986e-5;4.9965e-4 0.999];   % please recalculate the matrix if Motor parameters change
B_d =[1.9996e-4 5e-8;5e-8 -0.005];
U=[U_in;LTorque_in];
Xo=[ia_old;w_old];

X   = A_d*Xo + B_d*U;
ia=X(1);
w=X(2);

end

function LTorque= LTorqueGe(SampleTime,point_in)  % LoadTorque calulation
    t=(point_in-1)*SampleTime; % t（s）
        if t<4                  
            LTorque=0;
        elseif t<8
            LTorque=3;
        elseif t<12
            LTorque=4;
        else
            LTorque=8;
        end

end

