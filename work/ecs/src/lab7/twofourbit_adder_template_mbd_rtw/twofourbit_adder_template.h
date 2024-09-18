/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twofourbit_adder_template.h
 *
 * Code generated for Simulink model 'twofourbit_adder_template'.
 *
 * Model version                   : 1.6
 * Simulink Coder version          : 9.3 (R2020a) 18-Nov-2019
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Wed Sep 18 11:38:02 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_twofourbit_adder_template_h_
#define RTW_HEADER_twofourbit_adder_template_h_
#ifndef twofourbit_adder_template_COMMON_INCLUDES_
# define twofourbit_adder_template_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#endif                          /* twofourbit_adder_template_COMMON_INCLUDES_ */

#include "twofourbit_adder_template_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T Digital_Input;             /* '<S3>/Digital_Input' */
  boolean_T Digital_Input1;            /* '<S3>/Digital_Input1' */
  boolean_T Digital_Input2;            /* '<S3>/Digital_Input2' */
  boolean_T Digital_Input3;            /* '<S3>/Digital_Input3' */
  boolean_T Digital_Input_e;           /* '<S2>/Digital_Input' */
  boolean_T Digital_Input1_g;          /* '<S2>/Digital_Input1' */
  boolean_T Digital_Input2_h;          /* '<S2>/Digital_Input2' */
  boolean_T Digital_Input3_p;          /* '<S2>/Digital_Input3' */
  boolean_T DataTypeConversion;        /* '<S4>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S4>/Data Type Conversion1' */
  boolean_T DataTypeConversion2;       /* '<S4>/Data Type Conversion2' */
  boolean_T DataTypeConversion3;       /* '<S4>/Data Type Conversion3' */
  boolean_T DataTypeConversion4;       /* '<S4>/Data Type Conversion4' */
} B_twofourbit_adder_template_T;

/* Real-time Model Data Structure */
struct tag_RTM_twofourbit_adder_temp_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_twofourbit_adder_template_T twofourbit_adder_template_B;

/* Model entry point functions */
extern void twofourbit_adder_template_initialize(void);
extern void twofourbit_adder_template_step(void);
extern void twofourbit_adder_template_terminate(void);

/* Real-time Model object */
extern RT_MODEL_twofourbit_adder_tem_T *const twofourbit_adder_template_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S3>/Shift Arithmetic' : Eliminated trivial shift
 */

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
 * '<Root>' : 'twofourbit_adder_template'
 * '<S1>'   : 'twofourbit_adder_template/Adder Task'
 * '<S2>'   : 'twofourbit_adder_template/Adder Task/Read DIP 10-13'
 * '<S3>'   : 'twofourbit_adder_template/Adder Task/Read DIP 6-9'
 * '<S4>'   : 'twofourbit_adder_template/Adder Task/Write 5 Bits'
 */
#endif                             /* RTW_HEADER_twofourbit_adder_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
