%% Simulation paras
SampleTime=0.0001;
RefSpeed=400;

Q0_DC_MPC=[0.01 40000 40000 10];
R0_DC_MPC=0.01; 

%% DC motor physical parameters
R=2;         %Resistor
L=0.5;       %Inductor
Km=0.1;      %Torque Constant
Kemf=0.1;    %Back EMF Voltage Constant
Kf=0.2;      %Viscous Friction Constant
J=0.02;      %Inertial Load

%% Select a file to run
run('M_DCMotor_MPC.slx');
