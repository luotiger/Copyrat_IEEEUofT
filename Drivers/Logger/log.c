#include "log.h"

#include <stdio.h>
#include <stdbool.h>

#ifdef SEMIHOSTING
extern void initialise_monitor_handles(void);
// #else
// int _write(int file, char *ptr, int len) {
//     HAL_UART_Transmit(&huart2, (uint8_t *) ptr, len, HAL_MAX_DELAY);
//     return len;
// }
#endif

extern UART_HandleTypeDef huart2;
static bool logger_initialised = false;

static void MX_USART2_UART_Init(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    // if (HAL_UART_Init(&huart2) != HAL_OK)
    // {
    //   Error_Handler();
    // }
}

void set_log_level(stm32_log_level_t log_level) {
    if (!logger_initialised) {
#ifdef SEMIHOSTING
        initialise_monitor_handles();
#else
        MX_USART2_UART_Init();
#endif
        logger_initialised = true; 
    }
    switch(log_level) {
        case LOG_ERROR:
            printf(LOG_COLOR_E);
            break;
        case LOG_WARN:
            printf(LOG_COLOR_W);
            break;
        case LOG_INFO:
            printf(LOG_COLOR_I);
            break;
        case LOG_DEBUG:
            printf(LOG_COLOR_D);
            break;
        case LOG_VERBOSE:
            printf(LOG_COLOR_V);
            break;
        default:
            break; 
    }
}
