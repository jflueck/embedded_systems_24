/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: addersfunc.c
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

#include "addersfunc.h"
#include "addersfunc_private.h"

/* Block signals (default storage) */
B_addersfunc_T addersfunc_B;

/* Real-time model */
RT_MODEL_addersfunc_T addersfunc_M_;
RT_MODEL_addersfunc_T *const addersfunc_M = &addersfunc_M_;

/* Model step function */
void addersfunc_step(void)
{
  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Adder Task'
   */
  /* S-Function (gpio_s32k_input): '<S1>/Digital_Input' */

  /* GPIPORTE6 signal update */
  addersfunc_B.Digital_Input = (PINS_DRV_ReadPins(PTE) >> 6) & 0x01;

  /* S-Function (gpio_s32k_input): '<S1>/Digital_Input1' */

  /* GPIPORTE7 signal update */
  addersfunc_B.Digital_Input1 = (PINS_DRV_ReadPins(PTE) >> 7) & 0x01;

  /* S-Function (gpio_s32k_input): '<S1>/Digital_Input2' */

  /* GPIPORTE8 signal update */
  addersfunc_B.Digital_Input2 = (PINS_DRV_ReadPins(PTE) >> 8) & 0x01;

  /* S-Function (gpio_s32k_input): '<S1>/Digital_Input3' */

  /* GPIPORTE9 signal update */
  addersfunc_B.Digital_Input3 = (PINS_DRV_ReadPins(PTE) >> 9) & 0x01;

  /* S-Function (gpio_s32k_input): '<S1>/Digital_Input4' */

  /* GPIPORTE10 signal update */
  addersfunc_B.Digital_Input4 = (PINS_DRV_ReadPins(PTE) >> 10) & 0x01;

  /* S-Function (gpio_s32k_input): '<S1>/Digital_Input5' */

  /* GPIPORTE11 signal update */
  addersfunc_B.Digital_Input5 = (PINS_DRV_ReadPins(PTE) >> 11) & 0x01;

  /* S-Function (gpio_s32k_input): '<S1>/Digital_Input6' */

  /* GPIPORTE12 signal update */
  addersfunc_B.Digital_Input6 = (PINS_DRV_ReadPins(PTE) >> 12) & 0x01;

  /* S-Function (gpio_s32k_input): '<S1>/Digital_Input7' */

  /* GPIPORTE13 signal update */
  addersfunc_B.Digital_Input7 = (PINS_DRV_ReadPins(PTE) >> 13) & 0x01;

  /* SignalConversion generated from: '<S1>/S-Function Builder' */
  addersfunc_B.TmpSignalConversionAtSFunctionB[0] = addersfunc_B.Digital_Input;
  addersfunc_B.TmpSignalConversionAtSFunctionB[1] = addersfunc_B.Digital_Input1;
  addersfunc_B.TmpSignalConversionAtSFunctionB[2] = addersfunc_B.Digital_Input2;
  addersfunc_B.TmpSignalConversionAtSFunctionB[3] = addersfunc_B.Digital_Input3;
  addersfunc_B.TmpSignalConversionAtSFunctionB[4] = addersfunc_B.Digital_Input4;
  addersfunc_B.TmpSignalConversionAtSFunctionB[5] = addersfunc_B.Digital_Input5;
  addersfunc_B.TmpSignalConversionAtSFunctionB[6] = addersfunc_B.Digital_Input6;
  addersfunc_B.TmpSignalConversionAtSFunctionB[7] = addersfunc_B.Digital_Input7;

  /* S-Function (AdderFunction): '<S1>/S-Function Builder' */
  AdderFunction_Outputs_wrapper(&addersfunc_B.TmpSignalConversionAtSFunctionB[0],
    &addersfunc_B.SFunctionBuilder[0]);

  /* S-Function (gpio_s32k_output): '<S1>/Digital_Output' */

  /* GPOPORTD0 Data Signal Update */
  if (addersfunc_B.SFunctionBuilder[0]) {
    PINS_DRV_SetPins(PTD, 1UL<<0);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<0);
  }

  /* S-Function (gpio_s32k_output): '<S1>/Digital_Output1' */

  /* GPOPORTD1 Data Signal Update */
  if (addersfunc_B.SFunctionBuilder[1]) {
    PINS_DRV_SetPins(PTD, 1UL<<1);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<1);
  }

  /* S-Function (gpio_s32k_output): '<S1>/Digital_Output2' */

  /* GPOPORTD2 Data Signal Update */
  if (addersfunc_B.SFunctionBuilder[2]) {
    PINS_DRV_SetPins(PTD, 1UL<<2);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<2);
  }

  /* S-Function (gpio_s32k_output): '<S1>/Digital_Output3' */

  /* GPOPORTD3 Data Signal Update */
  if (addersfunc_B.SFunctionBuilder[3]) {
    PINS_DRV_SetPins(PTD, 1UL<<3);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<3);
  }

  /* S-Function (gpio_s32k_output): '<S1>/Digital_Output4' */

  /* GPOPORTD4 Data Signal Update */
  if (addersfunc_B.SFunctionBuilder[4]) {
    PINS_DRV_SetPins(PTD, 1UL<<4);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<4);
  }

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator' */
}

/* Model initialize function */
void addersfunc_initialize(void)
{
  /* SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Adder Task'
   */

  /* Start for S-Function (gpio_s32k_input): '<S1>/Digital_Input' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin6 = {
      .base = PORTE,
      .pinPortIdx = 6,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE6. */
    PINS_DRV_Init(1, &gpioPORTEPin6);
  }

  /* Start for S-Function (gpio_s32k_input): '<S1>/Digital_Input1' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin7 = {
      .base = PORTE,
      .pinPortIdx = 7,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE7. */
    PINS_DRV_Init(1, &gpioPORTEPin7);
  }

  /* Start for S-Function (gpio_s32k_input): '<S1>/Digital_Input2' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin8 = {
      .base = PORTE,
      .pinPortIdx = 8,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE8. */
    PINS_DRV_Init(1, &gpioPORTEPin8);
  }

  /* Start for S-Function (gpio_s32k_input): '<S1>/Digital_Input3' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin9 = {
      .base = PORTE,
      .pinPortIdx = 9,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE9. */
    PINS_DRV_Init(1, &gpioPORTEPin9);
  }

  /* Start for S-Function (gpio_s32k_input): '<S1>/Digital_Input4' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin10 = {
      .base = PORTE,
      .pinPortIdx = 10,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE10. */
    PINS_DRV_Init(1, &gpioPORTEPin10);
  }

  /* Start for S-Function (gpio_s32k_input): '<S1>/Digital_Input5' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin11 = {
      .base = PORTE,
      .pinPortIdx = 11,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE11. */
    PINS_DRV_Init(1, &gpioPORTEPin11);
  }

  /* Start for S-Function (gpio_s32k_input): '<S1>/Digital_Input6' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin12 = {
      .base = PORTE,
      .pinPortIdx = 12,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE12. */
    PINS_DRV_Init(1, &gpioPORTEPin12);
  }

  /* Start for S-Function (gpio_s32k_input): '<S1>/Digital_Input7' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin13 = {
      .base = PORTE,
      .pinPortIdx = 13,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE13. */
    PINS_DRV_Init(1, &gpioPORTEPin13);
  }

  /* Start for S-Function (gpio_s32k_output): '<S1>/Digital_Output' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin0 = {
      .base = PORTD,
      .pinPortIdx = 0,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD0. */
    PINS_DRV_Init(1, &gpioPORTDPin0);
  }

  /* Start for S-Function (gpio_s32k_output): '<S1>/Digital_Output1' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin1 = {
      .base = PORTD,
      .pinPortIdx = 1,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD1. */
    PINS_DRV_Init(1, &gpioPORTDPin1);
  }

  /* Start for S-Function (gpio_s32k_output): '<S1>/Digital_Output2' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin2 = {
      .base = PORTD,
      .pinPortIdx = 2,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD2. */
    PINS_DRV_Init(1, &gpioPORTDPin2);
  }

  /* Start for S-Function (gpio_s32k_output): '<S1>/Digital_Output3' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin3 = {
      .base = PORTD,
      .pinPortIdx = 3,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD3. */
    PINS_DRV_Init(1, &gpioPORTDPin3);
  }

  /* Start for S-Function (gpio_s32k_output): '<S1>/Digital_Output4' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin4 = {
      .base = PORTD,
      .pinPortIdx = 4,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD4. */
    PINS_DRV_Init(1, &gpioPORTDPin4);
  }

  /* End of SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator' */
}

/* Model terminate function */
void addersfunc_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
