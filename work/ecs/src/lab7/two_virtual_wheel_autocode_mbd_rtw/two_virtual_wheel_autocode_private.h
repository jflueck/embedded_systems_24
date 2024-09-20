/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: two_virtual_wheel_autocode_private.h
 *
 * Code generated for Simulink model 'two_virtual_wheel_autocode'.
 *
 * Model version                   : 1.13
 * Simulink Coder version          : 9.3 (R2020a) 18-Nov-2019
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Thu Sep 19 13:33:53 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_two_virtual_wheel_autocode_private_h_
#define RTW_HEADER_two_virtual_wheel_autocode_private_h_
#include "rtwtypes.h"
#include "two_virtual_wheel_autocode.h"
#if defined(__MWERKS__)

double fmod (double x, double y);
double fabs (double);

#endif

extern void fast_subsystem_Enable(DW_fast_subsystem_T *localDW);
extern void fast_subsystem(RT_MODEL_two_virtual_wheel_au_T * const
  two_virtual_wheel_autocode_M, real32_T rtu_Input, real32_T *rty_Out1,
  DW_fast_subsystem_T *localDW);
extern void slow_subsystem_Enable(DW_slow_subsystem_T *localDW);
extern void slow_subsystem(RT_MODEL_two_virtual_wheel_au_T * const
  two_virtual_wheel_autocode_M, real32_T rtu_In1, real32_T *rty_Out1,
  DW_slow_subsystem_T *localDW);

#endif                    /* RTW_HEADER_two_virtual_wheel_autocode_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
