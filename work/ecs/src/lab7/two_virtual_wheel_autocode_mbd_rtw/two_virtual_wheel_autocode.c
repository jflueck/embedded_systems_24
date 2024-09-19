/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: two_virtual_wheel_autocode.c
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

#include "two_virtual_wheel_autocode.h"
#include "two_virtual_wheel_autocode_private.h"

/* Block signals (default storage) */
B_two_virtual_wheel_autocode_T two_virtual_wheel_autocode_B;

/* Block states (default storage) */
DW_two_virtual_wheel_autocode_T two_virtual_wheel_autocode_DW;

/* Real-time model */
RT_MODEL_two_virtual_wheel_au_T two_virtual_wheel_autocode_M_;
RT_MODEL_two_virtual_wheel_au_T *const two_virtual_wheel_autocode_M =
  &two_virtual_wheel_autocode_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1])++;
  if ((two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.02s, 0.0s] */
    two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Enable for function-call system: '<Root>/Fast Subsystem' */
void fast_subsystem_Enable(DW_fast_subsystem_T *localDW)
{
  localDW->FastSubsystem_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
  localDW->DiscreteTimeIntegrator2_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
  localDW->DiscreteTimeIntegrator3_SYSTEM_ = 1U;
}

/* Output and update for function-call system: '<Root>/Fast Subsystem' */
void fast_subsystem(RT_MODEL_two_virtual_wheel_au_T * const
                    two_virtual_wheel_autocode_M, real32_T rtu_Input, real32_T
                    *rty_Out1, DW_fast_subsystem_T *localDW)
{
  uint32_T FastSubsystem_ELAPS_T;
  if (localDW->FastSubsystem_RESET_ELAPS_T) {
    FastSubsystem_ELAPS_T = 0U;
  } else {
    FastSubsystem_ELAPS_T = two_virtual_wheel_autocode_M->Timing.clockTick0 -
      localDW->FastSubsystem_PREV_T;
  }

  localDW->FastSubsystem_PREV_T =
    two_virtual_wheel_autocode_M->Timing.clockTick0;
  localDW->FastSubsystem_RESET_ELAPS_T = false;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
  if (localDW->DiscreteTimeIntegrator2_SYSTEM_ == 0) {
    localDW->DiscreteTimeIntegrator2_DSTATE += 0.002F * (real32_T)
      FastSubsystem_ELAPS_T * localDW->DiscreteTimeIntegrator2_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
  if (localDW->DiscreteTimeIntegrator3_SYSTEM_ == 0) {
    localDW->DiscreteTimeIntegrator3_DSTATE += 0.002F * (real32_T)
      FastSubsystem_ELAPS_T * localDW->DiscreteTimeIntegrator3_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */

  /* Sum: '<S1>/Sum3' incorporates:
   *  Gain: '<S1>/damping4'
   *  Gain: '<S1>/spring  constant2'
   *  Sum: '<S1>/Sum1'
   */
  *rty_Out1 = (rtu_Input - localDW->DiscreteTimeIntegrator2_DSTATE) * 7.5F -
    0.015F * localDW->DiscreteTimeIntegrator3_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
  localDW->DiscreteTimeIntegrator2_SYSTEM_ = 0U;
  localDW->DiscreteTimeIntegrator2_PREV_U =
    localDW->DiscreteTimeIntegrator3_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' incorporates:
   *  Gain: '<S1>/1//virtual inertia2'
   */
  localDW->DiscreteTimeIntegrator3_SYSTEM_ = 0U;
  localDW->DiscreteTimeIntegrator3_PREV_U = 533.333313F * *rty_Out1;
}

/* Enable for function-call system: '<Root>/slow subsystem' */
void slow_subsystem_Enable(DW_slow_subsystem_T *localDW)
{
  localDW->slowsubsystem_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_SYSTEM_E = 1U;
}

/* Output and update for function-call system: '<Root>/slow subsystem' */
void slow_subsystem(RT_MODEL_two_virtual_wheel_au_T * const
                    two_virtual_wheel_autocode_M, real32_T rtu_In1, real32_T
                    *rty_Out1, DW_slow_subsystem_T *localDW)
{
  uint32_T slowsubsystem_ELAPS_T;
  if (localDW->slowsubsystem_RESET_ELAPS_T) {
    slowsubsystem_ELAPS_T = 0U;
  } else {
    slowsubsystem_ELAPS_T = two_virtual_wheel_autocode_M->Timing.clockTick1 -
      localDW->slowsubsystem_PREV_T;
  }

  localDW->slowsubsystem_PREV_T =
    two_virtual_wheel_autocode_M->Timing.clockTick1;
  localDW->slowsubsystem_RESET_ELAPS_T = false;

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  if (localDW->DiscreteTimeIntegrator1_SYSTEM_ == 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE += 0.02F * (real32_T)
      slowsubsystem_ELAPS_T * localDW->DiscreteTimeIntegrator1_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  if (localDW->DiscreteTimeIntegrator_SYSTEM_E == 0) {
    localDW->DiscreteTimeIntegrator_DSTATE += 0.02F * (real32_T)
      slowsubsystem_ELAPS_T * localDW->DiscreteTimeIntegrator_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */

  /* Sum: '<S5>/Sum2' incorporates:
   *  Gain: '<S5>/damping1'
   *  Gain: '<S5>/spring  constant1'
   *  Sum: '<S5>/Sum5'
   */
  *rty_Out1 = (rtu_In1 - localDW->DiscreteTimeIntegrator1_DSTATE) * 7.5F - 0.15F
    * localDW->DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  localDW->DiscreteTimeIntegrator1_PREV_U =
    localDW->DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S5>/1//virtual inertia1'
   */
  localDW->DiscreteTimeIntegrator_SYSTEM_E = 0U;
  localDW->DiscreteTimeIntegrator_PREV_U = 5.33333349F * *rty_Out1;
}

/* Model step function */
void two_virtual_wheel_autocode_step(void)
{
  real32_T Sum3;
  real_T u0;

  /* S-Function (ftm_s32k_quadrature_decoder): '<S3>/Quadrature_Decoder' */

  /* FTM2: get counter value */
  two_virtual_wheel_autocode_B.Quadrature_Decoder_o2 = FTM_DRV_GetQuadDir(FTM2);
  two_virtual_wheel_autocode_B.Quadrature_Decoder_o4 =
    FTM_DRV_GetQuadTimerOverflowDir(FTM2);
  two_virtual_wheel_autocode_B.Quadrature_Decoder_o3 =
    FTM_DRV_HasTimerOverflowed(FTM2);
  two_virtual_wheel_autocode_B.Quadrature_Decoder_o1 = FTM_DRV_GetCounter(FTM2);
  FTM_DRV_ClearTimerOverflow(FTM2);

  /* Sum: '<S3>/Add1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Gain: '<S3>/Gain'
   *  Sum: '<S3>/Add'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  two_virtual_wheel_autocode_DW.UnitDelay1_DSTATE += (real32_T)(int16_T)
    (two_virtual_wheel_autocode_B.Quadrature_Decoder_o1 -
     two_virtual_wheel_autocode_DW.UnitDelay_DSTATE) * 0.09F;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Fast Subsystem'
   */
  /* UnitDelay: '<S3>/Unit Delay1' */
  fast_subsystem(two_virtual_wheel_autocode_M,
                 two_virtual_wheel_autocode_DW.UnitDelay1_DSTATE, &Sum3,
                 &two_virtual_wheel_autocode_DW.FastSubsystem);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

  /* RateTransition: '<Root>/RT1' */
  if (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] == 0) {
    two_virtual_wheel_autocode_B.RT1 = two_virtual_wheel_autocode_DW.RT1_Buffer0;
  }

  /* End of RateTransition: '<Root>/RT1' */

  /* Outputs for Atomic SubSystem: '<Root>/Write_Reaction_Torque' */
  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant'
   *  Gain: '<S4>/Gain'
   *  Sum: '<Root>/Add'
   */
  u0 = ((0.0F - two_virtual_wheel_autocode_B.RT1) - Sum3) * 0.0003162F + 0.5;

  /* Saturate: '<S4>/Saturation' */
  if (u0 > 0.75999999046325684) {
    two_virtual_wheel_autocode_B.Saturation = 0.76F;
  } else if (u0 < 0.23999999463558197) {
    two_virtual_wheel_autocode_B.Saturation = 0.24F;
  } else {
    two_virtual_wheel_autocode_B.Saturation = (real32_T)u0;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* S-Function (ftm_s32k_pwm_config): '<S4>/FTM_PWM_Config' */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE *
      two_virtual_wheel_autocode_B.Saturation;
    FTM_DRV_UpdatePwmChannel(FTM_PWM0, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }

  /* Simulation Outputs */
  two_virtual_wheel_autocode_B.FTM_PWM_Config_j = (float)
    two_virtual_wheel_autocode_B.Saturation;

  /* End of Outputs for SubSystem: '<Root>/Write_Reaction_Torque' */

  /* RateTransition: '<Root>/RT' incorporates:
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
     *  SubSystem: '<Root>/slow subsystem'
     */
    slow_subsystem(two_virtual_wheel_autocode_M,
                   two_virtual_wheel_autocode_DW.UnitDelay1_DSTATE,
                   &two_virtual_wheel_autocode_B.Sum2,
                   &two_virtual_wheel_autocode_DW.slowsubsystem);

    /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator1' */
  }

  /* End of RateTransition: '<Root>/RT' */

  /* S-Function (ftm_s32k_pwm_config): '<S2>/FTM_PWM_Config' incorporates:
   *  Constant: '<S2>/Constant'
   */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * 0.5F;
    FTM_DRV_UpdatePwmChannel(FTM_PWM3, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }

  /* Simulation Outputs */
  two_virtual_wheel_autocode_B.FTM_PWM_Config = (float) 0.5F;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  two_virtual_wheel_autocode_DW.UnitDelay_DSTATE =
    two_virtual_wheel_autocode_B.Quadrature_Decoder_o1;

  /* Update for RateTransition: '<Root>/RT1' */
  if (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] == 0) {
    two_virtual_wheel_autocode_DW.RT1_Buffer0 =
      two_virtual_wheel_autocode_B.Sum2;
  }

  /* End of Update for RateTransition: '<Root>/RT1' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  two_virtual_wheel_autocode_M->Timing.clockTick0++;
  if (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.02, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    two_virtual_wheel_autocode_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void two_virtual_wheel_autocode_initialize(void)
{
  /* Start for S-Function (ftm_s32k_quadrature_decoder): '<S3>/Quadrature_Decoder' */
  {
    ftm_user_config_t ftm2_qd_InitConfig = {
      {
        true,                          /* Software trigger state */
        false,                         /* Hardware trigger 1 state */
        false,                         /* Hardware trigger 2 state */
        false,                         /* Hardware trigger 3 state */
        false,                         /* Max loading point state */
        false,                         /* Min loading point state */
        FTM_SYSTEM_CLOCK,              /* Update mode for INVCTRL register */
        FTM_SYSTEM_CLOCK,              /* Update mode for SWOCTRL register */
        FTM_SYSTEM_CLOCK,              /* Update mode for OUTMASK register */
        FTM_SYSTEM_CLOCK,              /* Update mode for CNTIN register */
        false,                         /* Automatic clear of the trigger*/
        FTM_UPDATE_NOW,                /* Synchronization point */
      },
      FTM_MODE_QUADRATURE_DECODER,     /* Mode of operation for FTM */
      FTM_CLOCK_DIVID_BY_1,            /* FTM clock prescaler */
      FTM_CLOCK_SOURCE_SYSTEMCLK,      /* FTM clock source */
      FTM_BDM_MODE_00,                 /* FTM debug mode */
      false,                           /* Interrupt state */
      false                            /* Initialization trigger */
    };

    ftm_quad_decode_config_t ftm2_qd_Params = {
      FTM_QUAD_PHASE_ENCODE,           /* Quadrature decoder mode */
      0,                               /* Initial counter value */
      65535,                           /* Maximum counter value */

      {
        false,                         /* Filter state */
        0,                             /* Filter value */
        FTM_QUAD_PHASE_NORMAL          /* Phase polarity */
      },

      {
        false,                         /* Filter state */
        0,                             /* Filter value */
        FTM_QUAD_PHASE_NORMAL          /* Phase polarity */
      }
    };

    /* Enable clock for PORTA */
    PCC_SetClockMode(PCC, PCC_PORTA_CLOCK, true);

    /* Pin is configured for FTM function */
    PINS_SetMuxModeSel(PORTA, 13, PORT_MUX_ALT6);

    /* Enable clock for PORTA */
    PCC_SetClockMode(PCC, PCC_PORTA_CLOCK, true);

    /* Pin is configured for FTM function */
    PINS_SetMuxModeSel(PORTA, 12, PORT_MUX_ALT6);

    /* Set FTM_2 clock source */
    PCC_SetPeripheralClockControl (PCC, PCC_FTM2_CLOCK, true, CLK_SRC_SPLL, 0, 0);

    /* Enable clock for FTM_2 */
    PCC_SetClockMode (PCC, PCC_FTM2_CLOCK, true);

    /* Initialize FTM instance QD decoder*/
    static ftm_state_t ftm2StateStruct;
    FTM_DRV_Init(2, &ftm2_qd_InitConfig, &ftm2StateStruct);

    /* Start QD decoder*/
    FTM_DRV_QuadDecodeStart(2, &ftm2_qd_Params);
  }

  /* Start for S-Function (ftm_s32k_pwm_config): '<S2>/FTM_PWM_Config' incorporates:
   *  Constant: '<S2>/Constant'
   */

  /* Enable clock for PORTB */
  PCC_SetClockMode (PCC, PCC_PORTB_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel (PORTB, 8, PORT_MUX_ALT2);

  /* Set FTM_3 clock source */
  PCC_SetPeripheralClockControl (PCC, PCC_FTM3_CLOCK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for FTM_3 */
  PCC_SetClockMode (PCC, PCC_FTM3_CLOCK, true);

  /* PWM3 initialization */
  FTM_DRV_Init (FTM_PWM3, &flexTimer_pwm3_InitConfig, &ftmStateStruct3);
  FTM_DRV_InitPwm (FTM_PWM3, &flexTimer_pwm3_PwmConfig);
  FTM_DRV_SetChnTriggerCmd(FTM3, 1, false);

  /* SystemInitialize for Atomic SubSystem: '<Root>/Write_Reaction_Torque' */

  /* Start for S-Function (ftm_s32k_pwm_config): '<S4>/FTM_PWM_Config' */

  /* Enable clock for PORTB */
  PCC_SetClockMode (PCC, PCC_PORTB_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel (PORTB, 12, PORT_MUX_ALT2);

  /* Set FTM_0 clock source */
  PCC_SetPeripheralClockControl (PCC, PCC_FTM0_CLOCK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for FTM_0 */
  PCC_SetClockMode (PCC, PCC_FTM0_CLOCK, true);

  /* PWM0 initialization */
  FTM_DRV_Init (FTM_PWM0, &flexTimer_pwm0_InitConfig, &ftmStateStruct0);
  FTM_DRV_InitPwm (FTM_PWM0, &flexTimer_pwm0_PwmConfig);
  FTM_DRV_SetChnTriggerCmd(FTM0, 1, false);

  /* End of SystemInitialize for SubSystem: '<Root>/Write_Reaction_Torque' */

  /* Enable for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Fast Subsystem'
   */
  fast_subsystem_Enable(&two_virtual_wheel_autocode_DW.FastSubsystem);

  /* End of Enable for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

  /* Enable for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/slow subsystem'
   */
  slow_subsystem_Enable(&two_virtual_wheel_autocode_DW.slowsubsystem);

  /* End of Enable for S-Function (fcncallgen): '<Root>/Function-Call Generator1' */
}

/* Model terminate function */
void two_virtual_wheel_autocode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
