#include "pwm.h"

#include <stdio.h>
#include <stdbool.h>

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim11;
extern TIM_HandleTypeDef htim12;
extern TIM_HandleTypeDef htim13;

static bool is_initialised = false;

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

static HAL_StatusTypeDef MX_TIM3_Init(void);
static HAL_StatusTypeDef MX_TIM10_Init(void);
static HAL_StatusTypeDef MX_TIM11_Init(void);
static HAL_StatusTypeDef MX_TIM12_Init(void);
static HAL_StatusTypeDef MX_TIM13_Init(void);

// TODO: Make it inline
HAL_StatusTypeDef pwm_init()
{
    if (is_initialised)
    {
        return HAL_OK;
    }
    HAL_StatusTypeDef err = MX_TIM3_Init();
    err |= MX_TIM10_Init();
    err |= MX_TIM11_Init();
    err |= MX_TIM12_Init();
    err |= MX_TIM13_Init();
    return err;
}

void pwm_set_duty_cycle(TIM_TypeDef *instance, uint32_t channel, uint8_t duty_cycle)
{
    duty_cycle = duty_cycle > 100 ? 100 : (duty_cycle < 0) ? 0 : duty_cycle;

    if (instance == TIM3) {
        unsigned int ARR = __HAL_TIM_GET_AUTORELOAD(&htim3);
        switch (channel)
        {
            case TIM_CHANNEL_1:
                TIM3->CCR1 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            case TIM_CHANNEL_2:
                TIM3->CCR2 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            case TIM_CHANNEL_3:
                TIM3->CCR3 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            case TIM_CHANNEL_4:
                TIM3->CCR4 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            default:
                break;
        }
    }
    else if (instance == TIM10) {
        unsigned int ARR = __HAL_TIM_GET_AUTORELOAD(&htim10);
        switch (channel)
        {
            case TIM_CHANNEL_1:
                TIM10->CCR1 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            default:
                break;
        }
    }
    else if (instance == TIM11) {

        unsigned int ARR = __HAL_TIM_GET_AUTORELOAD(&htim11);
        switch (channel)
        {
            case TIM_CHANNEL_1:
                TIM11->CCR1 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            default:
                break;
        }
    }
    else if (instance == TIM12) {
        unsigned int ARR = __HAL_TIM_GET_AUTORELOAD(&htim12);
        switch (channel)
        {
            case TIM_CHANNEL_1:
                TIM12->CCR1 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            case TIM_CHANNEL_2:
                TIM12->CCR2 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            default:
                break;
        }
    }
    else if (instance == TIM13) {

        unsigned int ARR = __HAL_TIM_GET_AUTORELOAD(&htim13);
        switch (channel)
        {
            case TIM_CHANNEL_1:
                TIM13->CCR1 = (uint32_t)((ARR * duty_cycle) / 100);
                break;
            default:
                break;
        }
    }
}

/* TIM3 init function */
static HAL_StatusTypeDef MX_TIM3_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};
    TIM_OC_InitTypeDef sConfigOC = {0};

    htim3.Instance = TIM3;
    htim3.Init.Prescaler = 4 - 1;
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = 100 - 1;
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_StatusTypeDef err = HAL_TIM_Base_Init(&htim3);
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;

    err |= HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig);
    err |= HAL_TIM_PWM_Init(&htim3);
    err |= HAL_TIM_PWM_Init(&htim3);
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

    err |= HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    err |= HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);
    err |= HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2);
    err |= HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3);
    err |= HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4);
    HAL_TIM_MspPostInit(&htim3);

    err |= HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    err |= HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    err |= HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
    err |= HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);

    return err;
}

/* TIM10 init function */
static HAL_StatusTypeDef MX_TIM10_Init(void)
{

    TIM_OC_InitTypeDef sConfigOC = {0};

    htim10.Instance = TIM10;
    htim10.Init.Prescaler = 8 - 1;
    htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim10.Init.Period = 100 - 1;
    htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    HAL_StatusTypeDef err = HAL_TIM_Base_Init(&htim10);
    err |= HAL_TIM_PWM_Init(&htim10);
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    err |= HAL_TIM_PWM_ConfigChannel(&htim10, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_MspPostInit(&htim10);
    err |= HAL_TIM_PWM_Start(&htim10, TIM_CHANNEL_1);

    return err;
}

/* TIM11 init function */
static HAL_StatusTypeDef MX_TIM11_Init(void)
{
    TIM_OC_InitTypeDef sConfigOC = {0};

    htim11.Instance = TIM11;
    htim11.Init.Prescaler = 0;
    htim11.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim11.Init.Period = 65535;
    htim11.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim11.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_StatusTypeDef err = HAL_TIM_Base_Init(&htim11);
    err |= HAL_TIM_PWM_Init(&htim11);
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    err |= HAL_TIM_PWM_ConfigChannel(&htim11, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_MspPostInit(&htim11);
    err |= HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
    return err;
}
/* TIM12 init function */
static HAL_StatusTypeDef MX_TIM12_Init(void)
{
    TIM_OC_InitTypeDef sConfigOC = {0};

    htim12.Instance = TIM12;
    htim12.Init.Prescaler = 4 - 2;
    htim12.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim12.Init.Period = 100 - 1;
    htim12.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim12.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_StatusTypeDef err = HAL_TIM_PWM_Init(&htim12);
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    err |= HAL_TIM_PWM_ConfigChannel(&htim12, &sConfigOC, TIM_CHANNEL_1);
    err |= HAL_TIM_PWM_ConfigChannel(&htim12, &sConfigOC, TIM_CHANNEL_2);

    HAL_TIM_MspPostInit(&htim12);
    err |= HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_1);
    err |= HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_2);
    return err;
}
/* TIM13 init function */
static HAL_StatusTypeDef MX_TIM13_Init(void)
{
    TIM_OC_InitTypeDef sConfigOC = {0};

    htim13.Instance = TIM13;
    htim13.Init.Prescaler = 4 - 1;
    htim13.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim13.Init.Period = 100 - 1;
    htim13.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim13.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    HAL_StatusTypeDef err = HAL_TIM_Base_Init(&htim13);
    err |= HAL_TIM_PWM_Init(&htim13);

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    err |= HAL_TIM_PWM_ConfigChannel(&htim13, &sConfigOC, TIM_CHANNEL_1);

    HAL_TIM_MspPostInit(&htim13);
    err |= HAL_TIM_PWM_Start(&htim13, TIM_CHANNEL_1);
    return err;
}
