/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: EKF_Matrix_Cal_MPC.c
 *
 * Code generated for Simulink model 'EKF_Matrix_Cal_MPC'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Jun 16 10:43:28 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EKF_Matrix_Cal_MPC.h"

/* External inputs (root inport signals with default storage) */
ExtU_EKF_Matrix_Cal_MPC_T EKF_Matrix_Cal_MPC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_EKF_Matrix_Cal_MPC_T EKF_Matrix_Cal_MPC_Y;

/* Real-time model */
RT_MODEL_EKF_Matrix_Cal_MPC_T EKF_Matrix_Cal_MPC_M_;
RT_MODEL_EKF_Matrix_Cal_MPC_T *const EKF_Matrix_Cal_MPC_M =
  &EKF_Matrix_Cal_MPC_M_;

/* Model step function */
void EKF_Matrix_Cal_MPC_step(void)
{
  real_T A_4x4[16];
  real_T B_4x1[4];
  real_T A_3x3[9];
  real_T B_3x2[6];
  int8_T b_I[16];
  int8_T c_I[9];
  static const int8_T tmp[4] = { 1, 0, 0, 0 };

  int32_T i;
  int32_T i_0;
  real_T a_tmp;
  real_T A_4x4_tmp;
  real_T A_4x4_tmp_0;
  real_T A_4x4_tmp_1;
  real_T A_4x4_tmp_2;
  int32_T A_d4_tmp;
  int32_T A_d4_tmp_0;

  /* MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC' incorporates:
   *  Inport: '<Root>/DC_Paras_in'
   */
  A_4x4_tmp = -EKF_Matrix_Cal_MPC_U.DC_Paras_in[1] /
    EKF_Matrix_Cal_MPC_U.DC_Paras_in[2];
  A_4x4[0] = A_4x4_tmp;
  A_4x4_tmp_0 = -EKF_Matrix_Cal_MPC_U.DC_Paras_in[4] /
    EKF_Matrix_Cal_MPC_U.DC_Paras_in[2];
  A_4x4[4] = A_4x4_tmp_0;
  A_4x4[8] = 0.0;
  A_4x4[12] = 0.0;
  A_4x4_tmp_1 = EKF_Matrix_Cal_MPC_U.DC_Paras_in[3] /
    EKF_Matrix_Cal_MPC_U.DC_Paras_in[6];
  A_4x4[1] = A_4x4_tmp_1;
  A_4x4_tmp_2 = -EKF_Matrix_Cal_MPC_U.DC_Paras_in[5] /
    EKF_Matrix_Cal_MPC_U.DC_Paras_in[6];
  A_4x4[5] = A_4x4_tmp_2;
  A_4x4[9] = -1.0 / EKF_Matrix_Cal_MPC_U.DC_Paras_in[6];
  A_4x4[13] = 0.0;
  A_4x4[2] = 0.0;
  A_4x4[3] = 0.0;
  A_4x4[6] = 0.0;
  A_4x4[7] = 1.0;
  A_4x4[10] = 0.0;
  A_4x4[11] = 0.0;
  A_4x4[14] = 0.0;
  A_4x4[15] = 0.0;
  B_4x1[0] = 1.0 / EKF_Matrix_Cal_MPC_U.DC_Paras_in[2];
  B_4x1[1] = 0.0;
  B_4x1[2] = 0.0;
  B_4x1[3] = 0.0;
  for (i = 0; i < 16; i++) {
    b_I[i] = 0;
  }

  b_I[0] = 1;
  b_I[5] = 1;
  b_I[10] = 1;
  b_I[15] = 1;
  a_tmp = 0.5 * EKF_Matrix_Cal_MPC_U.DC_Paras_in[0] *
    EKF_Matrix_Cal_MPC_U.DC_Paras_in[0];
  A_3x3[0] = A_4x4_tmp;
  A_3x3[3] = A_4x4_tmp_0;
  A_3x3[6] = 0.0;
  A_3x3[1] = A_4x4_tmp_1;
  A_3x3[4] = A_4x4_tmp_2;
  A_3x3[7] = 0.0;
  A_3x3[2] = 0.0;
  A_3x3[5] = 1.0;
  A_3x3[8] = 0.0;
  B_3x2[0] = 1.0 / EKF_Matrix_Cal_MPC_U.DC_Paras_in[2];
  B_3x2[3] = 0.0;
  B_3x2[1] = 0.0;
  B_3x2[4] = -1.0 / EKF_Matrix_Cal_MPC_U.DC_Paras_in[6];
  B_3x2[2] = 0.0;
  B_3x2[5] = 0.0;
  for (i = 0; i < 9; i++) {
    c_I[i] = 0;
  }

  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;

  /* Outport: '<Root>/A_d4' incorporates:
   *  Inport: '<Root>/DC_Paras_in'
   *  MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC'
   */
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      /* MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC' */
      A_d4_tmp = i << 2;
      A_d4_tmp_0 = A_d4_tmp + i_0;
      EKF_Matrix_Cal_MPC_Y.A_d4[A_d4_tmp_0] = (((A_4x4[i_0 + 4] * a_tmp *
        A_4x4[A_d4_tmp + 1] + a_tmp * A_4x4[i_0] * A_4x4[A_d4_tmp]) + A_4x4[i_0
        + 8] * a_tmp * A_4x4[A_d4_tmp + 2]) + A_4x4[i_0 + 12] * a_tmp *
        A_4x4[A_d4_tmp + 3]) + (A_4x4[A_d4_tmp_0] *
        EKF_Matrix_Cal_MPC_U.DC_Paras_in[0] + (real_T)b_I[A_d4_tmp_0]);
    }
  }

  /* End of Outport: '<Root>/A_d4' */
  for (i = 0; i < 3; i++) {
    /* Outport: '<Root>/A_d3' incorporates:
     *  Inport: '<Root>/DC_Paras_in'
     *  MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC'
     */
    for (i_0 = 0; i_0 < 3; i_0++) {
      /* MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC' */
      A_d4_tmp = 3 * i_0 + i;
      EKF_Matrix_Cal_MPC_Y.A_d3[A_d4_tmp] = ((A_3x3[i + 3] * a_tmp * A_3x3[3 *
        i_0 + 1] + a_tmp * A_3x3[i] * A_3x3[3 * i_0]) + A_3x3[3 * i_0 + 2] *
        (a_tmp * 0.0)) + (A_3x3[A_d4_tmp] * EKF_Matrix_Cal_MPC_U.DC_Paras_in[0]
                          + (real_T)c_I[A_d4_tmp]);
    }

    /* End of Outport: '<Root>/A_d3' */

    /* Outport: '<Root>/B_d3' incorporates:
     *  Inport: '<Root>/DC_Paras_in'
     *  MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC'
     */
    for (i_0 = 0; i_0 < 2; i_0++) {
      /* MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC' */
      A_d4_tmp = 3 * i_0 + i;
      EKF_Matrix_Cal_MPC_Y.B_d3[A_d4_tmp] = ((A_3x3[i + 3] * a_tmp * B_3x2[3 *
        i_0 + 1] + a_tmp * A_3x3[i] * B_3x2[3 * i_0]) + B_3x2[3 * i_0 + 2] *
        (a_tmp * 0.0)) + B_3x2[A_d4_tmp] * EKF_Matrix_Cal_MPC_U.DC_Paras_in[0];
    }

    /* End of Outport: '<Root>/B_d3' */
  }

  for (i = 0; i < 4; i++) {
    /* Outport: '<Root>/B_d4' incorporates:
     *  Inport: '<Root>/DC_Paras_in'
     *  MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC'
     */
    EKF_Matrix_Cal_MPC_Y.B_d4[i] = (((A_4x4[i + 4] * a_tmp * 0.0 + a_tmp *
      A_4x4[i] * B_4x1[0]) + A_4x4[i + 8] * a_tmp * 0.0) + A_4x4[i + 12] * a_tmp
      * 0.0) + EKF_Matrix_Cal_MPC_U.DC_Paras_in[0] * B_4x1[i];

    /* Outport: '<Root>/C_d4' incorporates:
     *  MATLAB Function: '<Root>/EKF_Matrix_Cal_MPC'
     */
    EKF_Matrix_Cal_MPC_Y.C_d4[i] = tmp[i];
  }
}

/* Model initialize function */
void EKF_Matrix_Cal_MPC_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(EKF_Matrix_Cal_MPC_M, (NULL));

  /* external inputs */
  (void)memset(&EKF_Matrix_Cal_MPC_U, 0, sizeof(ExtU_EKF_Matrix_Cal_MPC_T));

  /* external outputs */
  (void) memset((void *)&EKF_Matrix_Cal_MPC_Y, 0,
                sizeof(ExtY_EKF_Matrix_Cal_MPC_T));
}

/* Model terminate function */
void EKF_Matrix_Cal_MPC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
