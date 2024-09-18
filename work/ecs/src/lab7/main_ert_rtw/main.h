/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main.h
 *
 * Code generated for Simulink model 'main'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Sep 18 10:29:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_main_h_
#define RTW_HEADER_main_h_
#ifndef main_COMMON_INCLUDES_
# define main_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* main_COMMON_INCLUDES_ */

#include "main_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T Input[4];                    /* '<Root>/Input' */
} ExtU_main_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint32_T Output;                     /* '<Root>/Output' */
} ExtY_main_T;

/* Real-time Model Data Structure */
struct tag_RTM_main_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_main_T main_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_main_T main_Y;

/* Model entry point functions */
extern void main_initialize(void);
extern void main_step(void);
extern void main_terminate(void);

/* Real-time Model object */
extern RT_MODEL_main_T *const main_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S2>/Bitwise AND' : Unused code path elimination
 * Block '<S2>/Bitwise AND1' : Unused code path elimination
 * Block '<S2>/Bitwise AND2' : Unused code path elimination
 * Block '<S2>/Bitwise AND3' : Unused code path elimination
 * Block '<S2>/Data Type Conversion' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Unused code path elimination
 * Block '<S2>/Data Type Conversion2' : Unused code path elimination
 * Block '<S2>/Data Type Conversion4' : Unused code path elimination
 * Block '<S2>/Shift Arithmetic' : Unused code path elimination
 * Block '<S2>/Shift Arithmetic1' : Unused code path elimination
 * Block '<S2>/Shift Arithmetic2' : Unused code path elimination
 * Block '<S2>/Shift Arithmetic3' : Unused code path elimination
 * Block '<S1>/Shift Arithmetic' : Eliminated trivial shift
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
 * '<Root>' : 'main'
 * '<S1>'   : 'main/Subsystem'
 * '<S2>'   : 'main/Subsystem Reference'
 */
#endif                                 /* RTW_HEADER_main_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
