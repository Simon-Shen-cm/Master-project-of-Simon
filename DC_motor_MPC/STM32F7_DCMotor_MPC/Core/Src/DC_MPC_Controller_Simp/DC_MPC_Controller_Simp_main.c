/*
 * DC_MPC_Controller_Simp_main.c
 *
 *  Created on: Jun 23, 2020
 *      Author: simon
 */


#include "DC_MPC_Controller_Simp_main.h"
#include "tim.h"

float ReBuf[9];
float SendBuf[9];



void DC_MPC_Simp_Step(void)
{
	TIM6->CNT=0x0000;
	DC_MPC_Controller_U.RefSpeed=ReBuf[0];
	DC_MPC_Controller_U.Voltage_in=ReBuf[1];
	DC_MPC_Controller_U.ia_in=ReBuf[2];
	DC_MPC_Controller_U.Q0_1x4[0]=ReBuf[3];
	DC_MPC_Controller_U.Q0_1x4[1]=ReBuf[4];
	DC_MPC_Controller_U.Q0_1x4[2]=ReBuf[5];
	DC_MPC_Controller_U.Q0_1x4[3]=ReBuf[6];
	DC_MPC_Controller_U.R0_1=ReBuf[7];
	SendBuf[8]=2*ReBuf[8];

	DC_MPC_Controller_step();

	SendBuf[0]=DC_MPC_Controller_Y.TriggerSignal[0];
	SendBuf[1]=DC_MPC_Controller_Y.TriggerSignal[1];
	SendBuf[2]=DC_MPC_Controller_Y.TriggerSignal[2];
	SendBuf[3]=DC_MPC_Controller_Y.TriggerSignal[3];
	SendBuf[4]=TIM6->CNT;
	SendBuf[5]=HAL_GetTick();
	SendBuf[6]=1;
	SendBuf[7]=1;
	SendBuf[8]=1;
}

void EKF_MPC_Cal(void)
{
	  EKF_Matrix_Cal_MPC_initialize();

	  EKF_Matrix_Cal_MPC_U.DC_Paras_in[0]=0.0001;	// Motor parameters
	  EKF_Matrix_Cal_MPC_U.DC_Paras_in[1]=2;
	  EKF_Matrix_Cal_MPC_U.DC_Paras_in[2]=0.5;
	  EKF_Matrix_Cal_MPC_U.DC_Paras_in[3]=0.1;
	  EKF_Matrix_Cal_MPC_U.DC_Paras_in[4]=0.1;
	  EKF_Matrix_Cal_MPC_U.DC_Paras_in[5]=0.2;
	  EKF_Matrix_Cal_MPC_U.DC_Paras_in[6]=0.02;

	  EKF_Matrix_Cal_MPC_step();
	  int i;
	for(i=0;i<16;i++)
	{
		DC_MPC_Controller_U.A_d4[i]=EKF_Matrix_Cal_MPC_Y.A_d4[i];
	}
	for(i=0;i<4;i++)
	{
		DC_MPC_Controller_U.B_d4[i]=EKF_Matrix_Cal_MPC_Y.B_d4[i];
		DC_MPC_Controller_U.C_d4[i]=EKF_Matrix_Cal_MPC_Y.C_d4[i];
	}
	for(i=0;i<9;i++)
		{
			DC_MPC_Controller_U.A_d3[i]=EKF_Matrix_Cal_MPC_Y.A_d3[i];
		}
	for(i=0;i<6;i++)
		{
			DC_MPC_Controller_U.B_d3[i]=EKF_Matrix_Cal_MPC_Y.B_d3[i];
		}
}

