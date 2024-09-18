/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: addersfunc.h
 *
 * Code generated for Simulink model 'addersfunc'.
 *
 * Model version                   : 1.8
 * Simulink Coder version          : 9.3 (R2020a) 18-Nov-2019
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Wed Sep 18 11:34:13 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_addersfunc_h_
#define RTW_HEADER_addersfunc_h_
#ifndef addersfunc_COMMON_INCLUDES_
# define addersfunc_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#endif                                 /* addersfunc_COMMON_INCLUDES_ */

#include "addersfunc_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T Digital_Input;             /* '<S1>/Digital_Input' */
  boolean_T Digital_Input1;            /* '<S1>/Digital_Input1' */
  boolean_T Digital_Input2;            /* '<S1>/Digital_Input2' */
  boolean_T Digital_Input3;            /* '<S1>/Digital_Input3' */
  boolean_T Digital_Input4;            /* '<S1>/Digital_Input4' */
  boolean_T Digital_Input5;            /* '<S1>/Digital_Input5' */
  boolean_T Digital_Input6;            /* '<S1>/Digital_Input6' */
  boolean_T Digital_Input7;            /* '<S1>/Digital_Input7' */
  boolean_T TmpSignalConversionAtSFunctionB[8];
  boolean_T SFunctionBuilder[5];       /* '<S1>/S-Function Builder' */
} B_addersfunc_T;

/* Real-time Model Data Structure */
struct tag_RTM_addersfunc_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_addersfunc_T addersfunc_B;

/* Model entry point functions */
extern void addersfunc_initialize(void);
extern void addersfunc_step(void);
extern void addersfunc_terminate(void);

/* Real-time Model object */
extern RT_MODEL_addersfunc_T *const addersfunc_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'addersfunc'
 * '<S1>'   : 'addersfunc/Adder Task'
 */
#endif                                 /* RTW_HEADER_addersfunc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
