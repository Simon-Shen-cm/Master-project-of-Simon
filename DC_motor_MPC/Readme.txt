This folder contains the simulation files for MPC control of a DC motor.

This is a "processor in loop" project. 

**File "M_DCMotor_MPC.slx" is the simulink file, in which there are 2 parts.
The first part(upper part),is a complete model with both controller and motor. The second part is the model of motor and blocks for serial communication. These two parts are mainly for results comparison.

**File "Startfile_M_DCMotor_MPC.m" should be put into the same folder as "M_DCMotor_MPC.slx". Run this m file in oder to load the necessary parameters to run the .slx file.

**Folder "STM32F7_DCMotor_MPC" contains codes for MCU, which is generated from Simulink, please use the file "F7_test_v1.ioc" to load configurations.

2020-0710: Add file "DC_MPC_blocking_mode.m". It is a transformed version of "M_DCMotor_MPC.slx" into matlab code. File "Startfile_M_DCMotor_MPC.m" is needed for this. Just connect the STM32 board with PC and set your serial port information, and run this file.
