/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MyWallModel.h
 *
 * Code generated for Simulink model 'MyWallModel'.
 *
 * Model version                   : 1.16
 * Simulink Coder version          : 9.3 (R2020a) 18-Nov-2019
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Thu Sep 19 10:28:53 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MyWallModel_h_
#define RTW_HEADER_MyWallModel_h_
#ifndef MyWallModel_COMMON_INCLUDES_
# define MyWallModel_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "ftm_qd_driver.h"
#include "clock_manager.h"
#include "pcc_hw_access.h"
#include "ftm_hw_access.h"
#include "pins_port_hw_access.h"
#include "ftm_pwm_driver.h"
#include "ftm3_pwm_params.h"
#include "ftm0_pwm_params.h"
#endif                                 /* MyWallModel_COMMON_INCLUDES_ */

#include "MyWallModel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T FTM_PWM_Config;             /* '<S2>/FTM_PWM_Config' */
  real32_T Saturation;                 /* '<S6>/Saturation' */
  real32_T FTM_PWM_Config_c;           /* '<S6>/FTM_PWM_Config' */
  real32_T torque;                     /* '<S3>/Chart' */
  uint16_T Quadrature_Decoder_o1;      /* '<S5>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o2;     /* '<S5>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o3;     /* '<S5>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o4;     /* '<S5>/Quadrature_Decoder' */
} B_MyWallModel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S5>/Unit Delay1' */
  uint32_T previousTicks;              /* '<S3>/Chart' */
  uint16_T UnitDelay_DSTATE;           /* '<S5>/Unit Delay' */
  uint8_T is_c1_MyWallModel;           /* '<S3>/Chart' */
  uint8_T temporalCounter_i1;          /* '<S3>/Chart' */
} DW_MyWallModel_T;

/* Real-time Model Data Structure */
struct tag_RTM_MyWallModel_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_MyWallModel_T MyWallModel_B;

/* Block states (default storage) */
extern DW_MyWallModel_T MyWallModel_DW;

/* Model entry point functions */
extern void MyWallModel_initialize(void);
extern void MyWallModel_step(void);
extern void MyWallModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MyWallModel_T *const MyWallModel_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'MyWallModel'
 * '<S1>'   : 'MyWallModel/Simulate Virtual Wall'
 * '<S2>'   : 'MyWallModel/Simulate Virtual Wall/Subsystem'
 * '<S3>'   : 'MyWallModel/Simulate Virtual Wall/Triggered Subsystem'
 * '<S4>'   : 'MyWallModel/Simulate Virtual Wall/Triggered Subsystem/Chart'
 * '<S5>'   : 'MyWallModel/Simulate Virtual Wall/Triggered Subsystem/Subsystem'
 * '<S6>'   : 'MyWallModel/Simulate Virtual Wall/Triggered Subsystem/Subsystem1'
 */
#endif                                 /* RTW_HEADER_MyWallModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
