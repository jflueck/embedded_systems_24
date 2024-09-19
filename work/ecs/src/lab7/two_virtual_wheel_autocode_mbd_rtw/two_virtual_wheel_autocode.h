/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: two_virtual_wheel_autocode.h
 *
 * Code generated for Simulink model 'two_virtual_wheel_autocode'.
 *
 * Model version                   : 1.8
 * Simulink Coder version          : 9.3 (R2020a) 18-Nov-2019
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Thu Sep 19 13:06:46 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_two_virtual_wheel_autocode_h_
#define RTW_HEADER_two_virtual_wheel_autocode_h_
#ifndef two_virtual_wheel_autocode_COMMON_INCLUDES_
# define two_virtual_wheel_autocode_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "ftm_pwm_driver.h"
#include "clock_manager.h"
#include "pcc_hw_access.h"
#include "pins_port_hw_access.h"
#include "ftm_hw_access.h"
#include "ftm3_pwm_params.h"
#include "ftm0_pwm_params.h"
#include "ftm_qd_driver.h"
#endif                         /* two_virtual_wheel_autocode_COMMON_INCLUDES_ */

#include "two_virtual_wheel_autocode_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>/Fast Subsystem' */
typedef struct {
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S1>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S1>/Discrete-Time Integrator3' */
  real32_T DiscreteTimeIntegrator2_PREV_U;/* '<S1>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_PREV_U;/* '<S1>/Discrete-Time Integrator3' */
  uint32_T FastSubsystem_PREV_T;       /* '<Root>/Fast Subsystem' */
  uint8_T DiscreteTimeIntegrator2_SYSTEM_;/* '<S1>/Discrete-Time Integrator2' */
  uint8_T DiscreteTimeIntegrator3_SYSTEM_;/* '<S1>/Discrete-Time Integrator3' */
  boolean_T FastSubsystem_RESET_ELAPS_T;/* '<Root>/Fast Subsystem' */
} DW_fast_subsystem_T;

/* Block states (default storage) for system '<Root>/slow subsystem' */
typedef struct {
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S5>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S5>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_PREV_U;/* '<S5>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S5>/Discrete-Time Integrator' */
  uint32_T slowsubsystem_PREV_T;       /* '<Root>/slow subsystem' */
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S5>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S5>/Discrete-Time Integrator' */
  boolean_T slowsubsystem_RESET_ELAPS_T;/* '<Root>/slow subsystem' */
} DW_slow_subsystem_T;

/* Block signals (default storage) */
typedef struct {
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T FTM_PWM_Config;             /* '<S2>/FTM_PWM_Config' */
  real32_T Saturation;                 /* '<S4>/Saturation' */
  real32_T FTM_PWM_Config_j;           /* '<S4>/FTM_PWM_Config' */
  real32_T Sum2;                       /* '<S5>/Sum2' */
  uint16_T Quadrature_Decoder_o1;      /* '<S3>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o2;     /* '<S3>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o3;     /* '<S3>/Quadrature_Decoder' */
  boolean_T Quadrature_Decoder_o4;     /* '<S3>/Quadrature_Decoder' */
} B_two_virtual_wheel_autocode_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay1_DSTATE;          /* '<S3>/Unit Delay1' */
  real32_T RT1_Buffer0;                /* '<Root>/RT1' */
  uint16_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
  DW_slow_subsystem_T slowsubsystem;   /* '<Root>/slow subsystem' */
  DW_fast_subsystem_T FastSubsystem;   /* '<Root>/Fast Subsystem' */
} DW_two_virtual_wheel_autocode_T;

/* Real-time Model Data Structure */
struct tag_RTM_two_virtual_wheel_aut_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_two_virtual_wheel_autocode_T two_virtual_wheel_autocode_B;

/* Block states (default storage) */
extern DW_two_virtual_wheel_autocode_T two_virtual_wheel_autocode_DW;

/* Model entry point functions */
extern void two_virtual_wheel_autocode_initialize(void);
extern void two_virtual_wheel_autocode_step(void);
extern void two_virtual_wheel_autocode_terminate(void);

/* Real-time Model object */
extern RT_MODEL_two_virtual_wheel_au_T *const two_virtual_wheel_autocode_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'two_virtual_wheel_autocode'
 * '<S1>'   : 'two_virtual_wheel_autocode/Fast Subsystem'
 * '<S2>'   : 'two_virtual_wheel_autocode/PWM Filter Config'
 * '<S3>'   : 'two_virtual_wheel_autocode/Read_Wheel_Position'
 * '<S4>'   : 'two_virtual_wheel_autocode/Write_Reaction_Torque'
 * '<S5>'   : 'two_virtual_wheel_autocode/slow subsystem'
 */
#endif                            /* RTW_HEADER_two_virtual_wheel_autocode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
