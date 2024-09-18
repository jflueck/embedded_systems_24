/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main.c
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

#include "main.h"
#include "main_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_main_T main_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_main_T main_Y;

/* Real-time model */
RT_MODEL_main_T main_M_;
RT_MODEL_main_T *const main_M = &main_M_;

/* Model step function */
void main_step(void)
{
  /* Outport: '<Root>/Output' incorporates:
   *  ArithShift: '<S1>/Shift Arithmetic1'
   *  ArithShift: '<S1>/Shift Arithmetic2'
   *  ArithShift: '<S1>/Shift Arithmetic3'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Inport: '<Root>/Input'
   *  Sum: '<S1>/Add'
   */
  main_Y.Output = ((((uint32_T)main_U.Input[1] << 8) + main_U.Input[0]) +
                   ((uint32_T)main_U.Input[2] << 16)) + ((uint32_T)main_U.Input
    [3] << 24);
}

/* Model initialize function */
void main_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void main_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
