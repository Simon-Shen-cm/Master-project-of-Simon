% 自动更改Q，R矩阵并且画出三维图程序，适用于v4

filename_QQ = 'data_QR_Error_vQQ.xlsx';     % 定义生成文件名字
            % 不同的参数，请修改文件名以保存不同参数下的数据
if 1
    if exist(filename_QQ,'file')       % 如果存在旧文件，就删掉
        delete(filename_QQ); 
    end
end

head_col={'Q0_2','Q0_3','Speed MSE','LTorque MSE'};
writecell(head_col,filename_QQ,'Sheet',1,'Range','A1');

% ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ Set Parameters ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
n_Qx=25;              % for循环参数 x为第一个，y为第二个
n_Qy=30;

num_Qx=2;                % 改第几个Q呢？
num_Qy=3; 
Q0_v4=diag([0.01 3e5 0.1]);    % 赋Q0初值[0.001 2e4 5e6]
R0_v4=0.001;                % 赋R0初值

Q0x_v4_max=5e5;         % Q1 3;  Q2 5e5;  Q3 5e6
Q0y_v4_max=2e6;
% ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

step_Qx=(Q0x_v4_max-Q0_v4(num_Qx,num_Qx))/n_Qx;     %  ← ← ← ← ← ←进步系数
step_Qy=(Q0y_v4_max-Q0_v4(num_Qy,num_Qy))/n_Qy; 

SpeedMSE=zeros(n_Qy,n_Qx);
LTorqueMSE=zeros(n_Qy,n_Qx);
Q0_Y=zeros(1,n_Qy);
Q0_X=zeros(1,n_Qx);
col=2;

for i=1:n_Qx
    
    for j=1:n_Qy
         DC_v4_data=sim('M_DCMotor_v4.slx');
         Q0_Y(j)=Q0_v4(num_Qy,num_Qy);     
         SpeedMSE(j,i)=DC_v4_data.Errors_simu(end,1);
         LTorqueMSE(j,i)=DC_v4_data.Errors_simu(end,3);
         
         col_data=num2str(col);
         writematrix(Q0_v4(num_Qx,num_Qx),filename_QQ,'Sheet',1,'Range',['A',col_data]);  
         writematrix(Q0_v4(num_Qy,num_Qy),filename_QQ,'Sheet',1,'Range',['B',col_data]);
         writematrix(DC_v4_data.Errors_simu(end,1),filename_QQ,'Sheet',1,'Range',['C',col_data]);
         writematrix(DC_v4_data.Errors_simu(end,3),filename_QQ,'Sheet',1,'Range',['D',col_data]);
         col=col+1;
    
         Q0_v4(num_Qy,num_Qy)=Q0_v4(num_Qy,num_Qy)+step_Qy;   
    end
    
    col=col+1;   
    Q0_v4(num_Qy,num_Qy)=1e4;       % Reset ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← Qy 
    Q0_X(i)=Q0_v4(num_Qx,num_Qx);    
    Q0_v4(num_Qx,num_Qx)=Q0_v4(num_Qx,num_Qx)+step_Qx; 
end
figure(1);
[Q_xx,Q_yy]=meshgrid(Q0_X,Q0_Y);
surf(Q_xx,Q_yy,SpeedMSE);
xlabel('X-Q2');ylabel('Y-Q3');zlabel('SpeedMSE');

figure(2);
surf(Q_xx,Q_yy,LTorqueMSE);  
xlabel('X-Q2');ylabel('Y-Q3');zlabel('LTorqueMSE');



