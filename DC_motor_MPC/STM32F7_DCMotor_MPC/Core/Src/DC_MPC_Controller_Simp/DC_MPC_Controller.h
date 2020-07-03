/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DC_MPC_Controller.h
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

#ifndef RTW_HEADER_DC_MPC_Controller_h_
#define RTW_HEADER_DC_MPC_Controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef DC_MPC_Controller_COMMON_INCLUDES_
# define DC_MPC_Controller_COMMON_INCLUDES_
#include "../DC_MPC_Controller_Simp/rtwtypes.h"
#endif                                 /* DC_MPC_Controller_COMMON_INCLUDES_ */

#include "../DC_MPC_Controller_Simp/DC_MPC_Controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[4];          /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[16];      /* '<S3>/Unit Delay1' */
  real_T UnitDelay_DSTATE_l[4];        /* '<S3>/Unit Delay' */
  real_T Trigger[16];                  /* '<S1>/CostFunction1' */
} DW_DC_MPC_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T RefSpeed;                     /* '<Root>/RefSpeed' */
  real_T A_d4[16];                     /* '<Root>/A_d4' */
  real_T B_d4[4];                      /* '<Root>/B_d4' */
  real_T C_d4[4];                      /* '<Root>/C_d4' */
  real_T A_d3[9];                      /* '<Root>/A_d3' */
  real_T B_d3[6];                      /* '<Root>/B_d3' */
  real_T Voltage_in;                   /* '<Root>/Voltage_in' */
  real_T ia_in;                        /* '<Root>/ia_in' */
  real_T Q0_1x4[4];                    /* '<Root>/Q0_1x4' */
  real_T R0_1;                         /* '<Root>/R0_1' */
} ExtU_DC_MPC_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T TriggerSignal[4];             /* '<Root>/TriggerSignal' */
} ExtY_DC_MPC_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_DC_MPC_Controller_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_DC_MPC_Controller_T DC_MPC_Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_DC_MPC_Controller_T DC_MPC_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DC_MPC_Controller_T DC_MPC_Controller_Y;

/* Model entry point functions */
extern void DC_MPC_Controller_initialize(void);
extern void DC_MPC_Controller_step(void);
extern void DC_MPC_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DC_MPC_Controller_T *const DC_MPC_Controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Assignment' : Unused code path elimination
 */

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
 * hilite_system('M_DCMotor_MPC/DC_MPC_Controller')    - opens subsystem M_DCMotor_MPC/DC_MPC_Controller
 * hilite_system('M_DCMotor_MPC/DC_MPC_Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M_DCMotor_MPC'
 * '<S1>'   : 'M_DCMotor_MPC/DC_MPC_Controller'
 * '<S2>'   : 'M_DCMotor_MPC/DC_MPC_Controller/CostFunction1'
 * '<S3>'   : 'M_DCMotor_MPC/DC_MPC_Controller/Estimator1'
 * '<S4>'   : 'M_DCMotor_MPC/DC_MPC_Controller/Iter.Predicter1'
 * '<S5>'   : 'M_DCMotor_MPC/DC_MPC_Controller/MATLAB Function'
 * '<S6>'   : 'M_DCMotor_MPC/DC_MPC_Controller/Estimator1/EKF'
 * '<S7>'   : 'M_DCMotor_MPC/DC_MPC_Controller/Iter.Predicter1/3U_H'
 * '<S8>'   : 'M_DCMotor_MPC/DC_MPC_Controller/Iter.Predicter1/DCMotor_StateSpace'
 */
#endif                                 /* RTW_HEADER_DC_MPC_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
