/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: EKF_Matrix_Cal_MPC.h
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

#ifndef RTW_HEADER_EKF_Matrix_Cal_MPC_h_
#define RTW_HEADER_EKF_Matrix_Cal_MPC_h_
#include <string.h>
#include <stddef.h>
#ifndef EKF_Matrix_Cal_MPC_COMMON_INCLUDES_
# define EKF_Matrix_Cal_MPC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* EKF_Matrix_Cal_MPC_COMMON_INCLUDES_ */

#include "EKF_Matrix_Cal_MPC_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T DC_Paras_in[7];               /* '<Root>/DC_Paras_in' */
} ExtU_EKF_Matrix_Cal_MPC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T A_d4[16];                     /* '<Root>/A_d4' */
  real_T B_d4[4];                      /* '<Root>/B_d4' */
  real_T C_d4[4];                      /* '<Root>/C_d4' */
  real_T A_d3[9];                      /* '<Root>/A_d3' */
  real_T B_d3[6];                      /* '<Root>/B_d3' */
} ExtY_EKF_Matrix_Cal_MPC_T;

/* Real-time Model Data Structure */
struct tag_RTM_EKF_Matrix_Cal_MPC_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_EKF_Matrix_Cal_MPC_T EKF_Matrix_Cal_MPC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_EKF_Matrix_Cal_MPC_T EKF_Matrix_Cal_MPC_Y;

/* Model entry point functions */
extern void EKF_Matrix_Cal_MPC_initialize(void);
extern void EKF_Matrix_Cal_MPC_step(void);
extern void EKF_Matrix_Cal_MPC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_EKF_Matrix_Cal_MPC_T *const EKF_Matrix_Cal_MPC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('M_DCMotor_MPC/EKF_Matrix_Cal_MPC')    - opens subsystem M_DCMotor_MPC/EKF_Matrix_Cal_MPC
 * hilite_system('M_DCMotor_MPC/EKF_Matrix_Cal_MPC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M_DCMotor_MPC'
 * '<S1>'   : 'M_DCMotor_MPC/EKF_Matrix_Cal_MPC'
 */
#endif                                 /* RTW_HEADER_EKF_Matrix_Cal_MPC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
