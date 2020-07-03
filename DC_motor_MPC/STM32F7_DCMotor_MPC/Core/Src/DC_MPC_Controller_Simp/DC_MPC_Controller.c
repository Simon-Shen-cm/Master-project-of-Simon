/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DC_MPC_Controller.c
 *
 * Code generated for Simulink model 'DC_MPC_Controller'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Jun 17 11:09:18 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "../DC_MPC_Controller_Simp/DC_MPC_Controller.h"

/* Block states (default storage) */
DW_DC_MPC_Controller_T DC_MPC_Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_DC_MPC_Controller_T DC_MPC_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_DC_MPC_Controller_T DC_MPC_Controller_Y;

/* Real-time model */
RT_MODEL_DC_MPC_Controller_T DC_MPC_Controller_M_;
RT_MODEL_DC_MPC_Controller_T *const DC_MPC_Controller_M = &DC_MPC_Controller_M_;

/* Model step function */
void DC_MPC_Controller_step(void)
{
  int32_T Trigger_num;
  real_T J;
  real_T P_star[16];
  real_T rtb_estiSpeed;
  int8_T s4_iter;
  real_T rtb_X[3];
  real_T rtb_Assignment1[4];
  real_T rtb_Assignment2[4];
  real_T rtb_Q0[16];
  real_T tmp[16];
  int32_T U_idx_0;
  real_T rtb_Assignment1_e;
  int32_T P_star_tmp;
  int32_T UnitDelay1_DSTATE_c_tmp;

  /* Gain: '<S1>/Gain2' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_estiSpeed = 9.5492965855137211 * DC_MPC_Controller_DW.UnitDelay_DSTATE[1];

  /* Outputs for Iterator SubSystem: '<S1>/Iter.Predicter1' incorporates:
   *  ForIterator: '<S4>/For Iterator'
   */
  for (s4_iter = 1; s4_iter < 5; s4_iter++) {
    /* MATLAB Function: '<S4>/3U_H' */
    switch (s4_iter) {
     case 1:
      /* MATLAB Function: '<S4>/DCMotor_StateSpace' */
      U_idx_0 = 400;
      break;

     case 2:
      /* MATLAB Function: '<S4>/DCMotor_StateSpace' */
      U_idx_0 = -400;
      break;

     case 3:
      /* MATLAB Function: '<S4>/DCMotor_StateSpace' */
      U_idx_0 = 0;
      break;

     default:
      /* MATLAB Function: '<S4>/DCMotor_StateSpace' */
      U_idx_0 = 0;
      break;
    }

    /* End of MATLAB Function: '<S4>/3U_H' */

    /* SignalConversion: '<S8>/TmpSignal ConversionAt SFunction Inport3' incorporates:
     *  Gain: '<S4>/Gain2'
     *  MATLAB Function: '<S4>/DCMotor_StateSpace'
     */
    J = 0.10471975511965977 * rtb_estiSpeed;

    /* MATLAB Function: '<S4>/DCMotor_StateSpace' incorporates:
     *  Inport: '<Root>/A_d3'
     *  Inport: '<Root>/B_d3'
     *  SignalConversion: '<S8>/TmpSignal ConversionAt SFunction Inport3'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    for (Trigger_num = 0; Trigger_num < 3; Trigger_num++) {
      rtb_X[Trigger_num] = (DC_MPC_Controller_U.A_d3[Trigger_num + 6] *
                            DC_MPC_Controller_DW.UnitDelay_DSTATE[3] +
                            (DC_MPC_Controller_U.A_d3[Trigger_num + 3] * J +
        DC_MPC_Controller_U.A_d3[Trigger_num] *
        DC_MPC_Controller_DW.UnitDelay_DSTATE[0])) +
        (DC_MPC_Controller_U.B_d3[Trigger_num + 3] *
         DC_MPC_Controller_DW.UnitDelay_DSTATE[2] +
         DC_MPC_Controller_U.B_d3[Trigger_num] * (real_T)U_idx_0);
    }

    /* Assignment: '<S4>/Assignment1' incorporates:
     *  Assignment: '<S4>/Assignment2'
     *  Gain: '<S4>/Gain1'
     */
    if (s4_iter == 1) {
      rtb_Assignment1[0] = 0.0;
      rtb_Assignment1[1] = 0.0;
      rtb_Assignment1[2] = 0.0;
      rtb_Assignment1[3] = 0.0;
    }

    Trigger_num = s4_iter - 1;
    rtb_Assignment1[Trigger_num] = 9.5492965855137211 * rtb_X[1];

    /* End of Assignment: '<S4>/Assignment1' */

    /* Assignment: '<S4>/Assignment2' incorporates:
     *  Gain: '<S4>/Gain3'
     */
    if (s4_iter == 1) {
      rtb_Assignment2[0] = 0.0;
      rtb_Assignment2[1] = 0.0;
      rtb_Assignment2[2] = 0.0;
      rtb_Assignment2[3] = 0.0;
    }

    rtb_Assignment2[Trigger_num] = 9.5492965855137211 * rtb_X[2];
  }

  /* End of Outputs for SubSystem: '<S1>/Iter.Predicter1' */

  /* MATLAB Function: '<S1>/CostFunction1' incorporates:
   *  Constant: '<S1>/K_theta1'
   *  Constant: '<S1>/K_trigger1'
   *  Constant: '<S1>/Ref Theta1'
   *  Inport: '<Root>/RefSpeed'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  rtb_estiSpeed = 100000.0;
  Trigger_num = 0;
  for (U_idx_0 = 0; U_idx_0 < 4; U_idx_0++) {
    J = DC_MPC_Controller_U.RefSpeed - rtb_Assignment1[U_idx_0];
    J = (((fabs(DC_MPC_Controller_DW.Trigger[U_idx_0 + 4] -
                DC_MPC_Controller_Y.TriggerSignal[1]) + fabs
           (DC_MPC_Controller_DW.Trigger[U_idx_0] -
            DC_MPC_Controller_Y.TriggerSignal[0])) + fabs
          (DC_MPC_Controller_DW.Trigger[U_idx_0 + 8] -
           DC_MPC_Controller_Y.TriggerSignal[2])) + fabs
         (DC_MPC_Controller_DW.Trigger[U_idx_0 + 12] -
          DC_MPC_Controller_Y.TriggerSignal[3])) * 0.0 + ((1000.0 -
      rtb_Assignment2[U_idx_0]) * (1000.0 - rtb_Assignment2[U_idx_0]) * 0.0 + J *
      J);
    if (J < rtb_estiSpeed) {
      rtb_estiSpeed = J;
      Trigger_num = U_idx_0;
    }
  }

  DC_MPC_Controller_Y.TriggerSignal[0] =
    DC_MPC_Controller_DW.Trigger[Trigger_num];
  DC_MPC_Controller_Y.TriggerSignal[1] =
    DC_MPC_Controller_DW.Trigger[Trigger_num + 4];
  DC_MPC_Controller_Y.TriggerSignal[2] =
    DC_MPC_Controller_DW.Trigger[Trigger_num + 8];
  DC_MPC_Controller_Y.TriggerSignal[3] =
    DC_MPC_Controller_DW.Trigger[Trigger_num + 12];

  /* End of MATLAB Function: '<S1>/CostFunction1' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Q0_1x4'
   */
  memset(&rtb_Q0[0], 0, sizeof(real_T) << 4U);
  rtb_Q0[0] = DC_MPC_Controller_U.Q0_1x4[0];
  rtb_Q0[5] = DC_MPC_Controller_U.Q0_1x4[1];
  rtb_Q0[10] = DC_MPC_Controller_U.Q0_1x4[2];
  rtb_Q0[15] = DC_MPC_Controller_U.Q0_1x4[3];

  /* MATLAB Function: '<S3>/EKF' incorporates:
   *  Inport: '<Root>/A_d4'
   *  Inport: '<Root>/B_d4'
   *  Inport: '<Root>/C_d4'
   *  Inport: '<Root>/R0_1'
   *  Inport: '<Root>/Voltage_in'
   *  Inport: '<Root>/ia_in'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  for (Trigger_num = 0; Trigger_num < 4; Trigger_num++) {
    rtb_Assignment1[Trigger_num] = (((DC_MPC_Controller_U.A_d4[Trigger_num + 4] *
      DC_MPC_Controller_DW.UnitDelay_DSTATE_l[1] +
      DC_MPC_Controller_U.A_d4[Trigger_num] *
      DC_MPC_Controller_DW.UnitDelay_DSTATE_l[0]) +
      DC_MPC_Controller_U.A_d4[Trigger_num + 8] *
      DC_MPC_Controller_DW.UnitDelay_DSTATE_l[2]) +
      DC_MPC_Controller_U.A_d4[Trigger_num + 12] *
      DC_MPC_Controller_DW.UnitDelay_DSTATE_l[3]) +
      DC_MPC_Controller_U.B_d4[Trigger_num] * DC_MPC_Controller_U.Voltage_in;
  }

  for (Trigger_num = 0; Trigger_num < 4; Trigger_num++) {
    DC_MPC_Controller_DW.UnitDelay_DSTATE_l[Trigger_num] =
      rtb_Assignment1[Trigger_num];
    for (U_idx_0 = 0; U_idx_0 < 4; U_idx_0++) {
      P_star_tmp = U_idx_0 << 2;
      UnitDelay1_DSTATE_c_tmp = Trigger_num + P_star_tmp;
      tmp[UnitDelay1_DSTATE_c_tmp] = 0.0;
      tmp[UnitDelay1_DSTATE_c_tmp] +=
        DC_MPC_Controller_DW.UnitDelay1_DSTATE_c[P_star_tmp] *
        DC_MPC_Controller_U.A_d4[Trigger_num];
      tmp[UnitDelay1_DSTATE_c_tmp] +=
        DC_MPC_Controller_DW.UnitDelay1_DSTATE_c[P_star_tmp + 1] *
        DC_MPC_Controller_U.A_d4[Trigger_num + 4];
      tmp[UnitDelay1_DSTATE_c_tmp] +=
        DC_MPC_Controller_DW.UnitDelay1_DSTATE_c[P_star_tmp + 2] *
        DC_MPC_Controller_U.A_d4[Trigger_num + 8];
      tmp[UnitDelay1_DSTATE_c_tmp] +=
        DC_MPC_Controller_DW.UnitDelay1_DSTATE_c[P_star_tmp + 3] *
        DC_MPC_Controller_U.A_d4[Trigger_num + 12];
    }

    for (U_idx_0 = 0; U_idx_0 < 4; U_idx_0++) {
      P_star_tmp = (U_idx_0 << 2) + Trigger_num;
      P_star[P_star_tmp] = (((tmp[Trigger_num + 4] *
        DC_MPC_Controller_U.A_d4[U_idx_0 + 4] + tmp[Trigger_num] *
        DC_MPC_Controller_U.A_d4[U_idx_0]) + tmp[Trigger_num + 8] *
        DC_MPC_Controller_U.A_d4[U_idx_0 + 8]) + tmp[Trigger_num + 12] *
                            DC_MPC_Controller_U.A_d4[U_idx_0 + 12]) +
        rtb_Q0[P_star_tmp];
    }
  }

  rtb_estiSpeed = 0.0;
  for (Trigger_num = 0; Trigger_num < 4; Trigger_num++) {
    U_idx_0 = Trigger_num << 2;
    J = P_star[U_idx_0 + 3] * DC_MPC_Controller_U.C_d4[3] + (P_star[U_idx_0 + 2]
      * DC_MPC_Controller_U.C_d4[2] + (P_star[U_idx_0 + 1] *
      DC_MPC_Controller_U.C_d4[1] + P_star[U_idx_0] * DC_MPC_Controller_U.C_d4[0]));
    rtb_estiSpeed += J * DC_MPC_Controller_U.C_d4[Trigger_num];
    J = P_star[Trigger_num + 12] * DC_MPC_Controller_U.C_d4[3] +
      (P_star[Trigger_num + 8] * DC_MPC_Controller_U.C_d4[2] +
       (P_star[Trigger_num + 4] * DC_MPC_Controller_U.C_d4[1] +
        P_star[Trigger_num] * DC_MPC_Controller_U.C_d4[0]));
    rtb_Assignment2[Trigger_num] = J;
  }

  J = 1.0 / (rtb_estiSpeed + DC_MPC_Controller_U.R0_1);
  rtb_estiSpeed = 0.0;
  for (Trigger_num = 0; Trigger_num < 4; Trigger_num++) {
    rtb_Assignment1_e = rtb_Assignment2[Trigger_num] * J;
    rtb_Q0[Trigger_num] = rtb_Assignment1_e * DC_MPC_Controller_U.C_d4[0];
    rtb_Q0[Trigger_num + 4] = rtb_Assignment1_e * DC_MPC_Controller_U.C_d4[1];
    rtb_Q0[Trigger_num + 8] = rtb_Assignment1_e * DC_MPC_Controller_U.C_d4[2];
    rtb_Q0[Trigger_num + 12] = rtb_Assignment1_e * DC_MPC_Controller_U.C_d4[3];
    for (U_idx_0 = 0; U_idx_0 < 4; U_idx_0++) {
      P_star_tmp = U_idx_0 << 2;
      UnitDelay1_DSTATE_c_tmp = P_star_tmp + Trigger_num;
      DC_MPC_Controller_DW.UnitDelay1_DSTATE_c[UnitDelay1_DSTATE_c_tmp] =
        P_star[UnitDelay1_DSTATE_c_tmp] - (((P_star[P_star_tmp + 1] *
        rtb_Q0[Trigger_num + 4] + P_star[P_star_tmp] * rtb_Q0[Trigger_num]) +
        P_star[P_star_tmp + 2] * rtb_Q0[Trigger_num + 8]) + P_star[P_star_tmp +
        3] * rtb_Q0[Trigger_num + 12]);
    }

    rtb_estiSpeed += DC_MPC_Controller_U.C_d4[Trigger_num] *
      DC_MPC_Controller_DW.UnitDelay_DSTATE_l[Trigger_num];
    rtb_Assignment1[Trigger_num] = rtb_Assignment1_e;
  }

  rtb_estiSpeed = DC_MPC_Controller_U.ia_in - rtb_estiSpeed;
  DC_MPC_Controller_DW.UnitDelay_DSTATE_l[0] += rtb_Assignment1[0] *
    rtb_estiSpeed;

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DC_MPC_Controller_DW.UnitDelay_DSTATE[0] =
    DC_MPC_Controller_DW.UnitDelay_DSTATE_l[0];

  /* MATLAB Function: '<S3>/EKF' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DC_MPC_Controller_DW.UnitDelay_DSTATE_l[1] += rtb_Assignment1[1] *
    rtb_estiSpeed;

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DC_MPC_Controller_DW.UnitDelay_DSTATE[1] =
    DC_MPC_Controller_DW.UnitDelay_DSTATE_l[1];

  /* MATLAB Function: '<S3>/EKF' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DC_MPC_Controller_DW.UnitDelay_DSTATE_l[2] += rtb_Assignment1[2] *
    rtb_estiSpeed;

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DC_MPC_Controller_DW.UnitDelay_DSTATE[2] =
    DC_MPC_Controller_DW.UnitDelay_DSTATE_l[2];

  /* MATLAB Function: '<S3>/EKF' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DC_MPC_Controller_DW.UnitDelay_DSTATE_l[3] += rtb_Assignment1[3] *
    rtb_estiSpeed;

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DC_MPC_Controller_DW.UnitDelay_DSTATE[3] =
    DC_MPC_Controller_DW.UnitDelay_DSTATE_l[3];
}

/* Model initialize function */
void DC_MPC_Controller_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(DC_MPC_Controller_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&DC_MPC_Controller_DW, 0,
                sizeof(DW_DC_MPC_Controller_T));

  /* external inputs */
  (void)memset(&DC_MPC_Controller_U, 0, sizeof(ExtU_DC_MPC_Controller_T));

  /* external outputs */
  (void) memset(&DC_MPC_Controller_Y.TriggerSignal[0], 0,
                4U*sizeof(real_T));

  {
    static const int8_T tmp[16] = { 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0,
      1 };

    int32_T i;

    /* SystemInitialize for MATLAB Function: '<S1>/CostFunction1' */
    for (i = 0; i < 16; i++) {
      DC_MPC_Controller_DW.Trigger[i] = tmp[i];
    }

    /* End of SystemInitialize for MATLAB Function: '<S1>/CostFunction1' */
  }
}

/* Model terminate function */
void DC_MPC_Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
