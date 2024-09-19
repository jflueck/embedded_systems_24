/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MyWallModel.c
 *
 * Code generated for Simulink model 'MyWallModel'.
 *
 * Model version                   : 1.27
 * Simulink Coder version          : 9.3 (R2020a) 18-Nov-2019
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Thu Sep 19 11:17:30 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#include "MyWallModel.h"
#include "MyWallModel_private.h"

/* Named constants for Chart: '<S3>/Chart' */
#define MyWallModel_IN_Inside_wall     ((uint8_T)1U)
#define MyWallModel_IN_Outside_wall    ((uint8_T)2U)
#define MyWallModel_IN_Start           ((uint8_T)3U)

/* Block signals (default storage) */
B_MyWallModel_T MyWallModel_B;

/* Block states (default storage) */
DW_MyWallModel_T MyWallModel_DW;

/* Real-time model */
RT_MODEL_MyWallModel_T MyWallModel_M_;
RT_MODEL_MyWallModel_T *const MyWallModel_M = &MyWallModel_M_;

/* Model step function */
void MyWallModel_step(void)
{
  uint32_T elapsedTicks;
  real32_T tmp;

  /* S-Function (fcncallgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/Triggered Subsystem'
   */
  /* S-Function (ftm_s32k_quadrature_decoder): '<S5>/Quadrature_Decoder' */

  /* FTM2: get counter value */
  MyWallModel_B.Quadrature_Decoder_o2 = FTM_DRV_GetQuadDir(FTM2);
  MyWallModel_B.Quadrature_Decoder_o4 = FTM_DRV_GetQuadTimerOverflowDir(FTM2);
  MyWallModel_B.Quadrature_Decoder_o3 = FTM_DRV_HasTimerOverflowed(FTM2);
  MyWallModel_B.Quadrature_Decoder_o1 = FTM_DRV_GetCounter(FTM2);
  FTM_DRV_ClearTimerOverflow(FTM2);

  /* Sum: '<S5>/Add1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  DataTypeConversion: '<S5>/Data Type Conversion2'
   *  Gain: '<S5>/Gain'
   *  Sum: '<S5>/Add'
   *  UnitDelay: '<S5>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  MyWallModel_DW.UnitDelay1_DSTATE += (real32_T)(int16_T)
    (MyWallModel_B.Quadrature_Decoder_o1 - MyWallModel_DW.UnitDelay_DSTATE) *
    0.09F;

  /* Chart: '<S3>/Chart' incorporates:
   *  Constant: '<S3>/Constant1'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  elapsedTicks = MyWallModel_M->Timing.clockTick0 - MyWallModel_DW.previousTicks;
  MyWallModel_DW.previousTicks = MyWallModel_M->Timing.clockTick0;
  if (MyWallModel_DW.temporalCounter_i1 + elapsedTicks <= 127U) {
    MyWallModel_DW.temporalCounter_i1 = (uint8_T)
      (MyWallModel_DW.temporalCounter_i1 + elapsedTicks);
  } else {
    MyWallModel_DW.temporalCounter_i1 = 127U;
  }

  switch (MyWallModel_DW.is_c1_MyWallModel) {
   case MyWallModel_IN_Inside_wall:
    if ((real32_T)MyWallModel_DW.UnitDelay1_DSTATE - 10.0F <= 0.0F) {
      MyWallModel_DW.is_c1_MyWallModel = MyWallModel_IN_Outside_wall;
      MyWallModel_B.torque = 0.0F;
    } else {
      MyWallModel_B.torque = (10.0F - (real32_T)MyWallModel_DW.UnitDelay1_DSTATE)
        * 500.0F;
    }
    break;

   case MyWallModel_IN_Outside_wall:
    if ((real32_T)MyWallModel_DW.UnitDelay1_DSTATE - 10.0F > 0.0F) {
      MyWallModel_DW.is_c1_MyWallModel = MyWallModel_IN_Inside_wall;
      MyWallModel_B.torque = (10.0F - (real32_T)MyWallModel_DW.UnitDelay1_DSTATE)
        * 500.0F;
    }
    break;

   default:
    /* case IN_Start: */
    if (MyWallModel_DW.temporalCounter_i1 >= 100U) {
      MyWallModel_DW.is_c1_MyWallModel = MyWallModel_IN_Outside_wall;
      MyWallModel_B.torque = 0.0F;
    }
    break;
  }

  /* End of Chart: '<S3>/Chart' */

  /* Saturate: '<S3>/Saturation' */
  if (MyWallModel_B.torque > 822.0F) {
    tmp = 822.0F;
  } else if (MyWallModel_B.torque < -822.0F) {
    tmp = -822.0F;
  } else {
    tmp = MyWallModel_B.torque;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Saturate: '<S6>/Saturation' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain'
   *  Sum: '<S6>/Add'
   */
  MyWallModel_B.Saturation = (real32_T)(0.0003162F * tmp + 0.5);

  /* S-Function (ftm_s32k_pwm_config): '<S6>/FTM_PWM_Config' */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * MyWallModel_B.Saturation;
    FTM_DRV_UpdatePwmChannel(FTM_PWM0, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }

  /* Simulation Outputs */
  MyWallModel_B.FTM_PWM_Config_c = (float) MyWallModel_B.Saturation;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  MyWallModel_DW.UnitDelay_DSTATE = MyWallModel_B.Quadrature_Decoder_o1;

  /* End of Outputs for S-Function (fcncallgen): '<S1>/Function-Call Generator' */

  /* S-Function (ftm_s32k_pwm_config): '<S2>/FTM_PWM_Config' incorporates:
   *  Constant: '<S2>/Constant'
   */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * 0.5F;
    FTM_DRV_UpdatePwmChannel(FTM_PWM3, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }

  /* Simulation Outputs */
  MyWallModel_B.FTM_PWM_Config = (float) 0.5F;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  MyWallModel_M->Timing.clockTick0++;
}

/* Model initialize function */
void MyWallModel_initialize(void)
{
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

  /* SystemInitialize for S-Function (fcncallgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/Triggered Subsystem'
   */
  /* Start for S-Function (ftm_s32k_quadrature_decoder): '<S5>/Quadrature_Decoder' */
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

  /* Start for S-Function (ftm_s32k_pwm_config): '<S6>/FTM_PWM_Config' */

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

  /* Chart: '<S3>/Chart' */
  MyWallModel_DW.is_c1_MyWallModel = MyWallModel_IN_Start;

  /* End of SystemInitialize for S-Function (fcncallgen): '<S1>/Function-Call Generator' */

  /* Enable for S-Function (fcncallgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/Triggered Subsystem'
   */
  /* Enable for Chart: '<S3>/Chart' */
  MyWallModel_DW.previousTicks = MyWallModel_M->Timing.clockTick0;

  /* End of Enable for S-Function (fcncallgen): '<S1>/Function-Call Generator' */
}

/* Model terminate function */
void MyWallModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
