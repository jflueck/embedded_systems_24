/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: addersfunc_private.h
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

#ifndef RTW_HEADER_addersfunc_private_h_
#define RTW_HEADER_addersfunc_private_h_
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern void AdderFunction_Start_wrapper(void);
  extern void AdderFunction_Outputs_wrapper(const boolean_T *u0,
    boolean_T *y0);
  extern void AdderFunction_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#if defined(__MWERKS__)

double fmod (double x, double y);
double fabs (double);

#endif
#endif                                 /* RTW_HEADER_addersfunc_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
