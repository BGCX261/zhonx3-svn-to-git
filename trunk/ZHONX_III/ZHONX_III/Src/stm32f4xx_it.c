/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @date    19/10/2014 22:24:43
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2014 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* External variables --------------------------------------------------------*/

extern DMA_HandleTypeDef hdma_i2c1_tx;
extern DMA_HandleTypeDef hdma_i2c1_rx;
extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim10;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles DMA1 Stream6 global interrupt.
*/
void DMA1_Stream6_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(DMA1_Stream6_IRQn);
  HAL_DMA_IRQHandler(&hdma_i2c1_tx);
}

/**
* @brief This function handles TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts.
*/
void TIM6_DAC_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM6_DAC_IRQn);
  HAL_TIM_IRQHandler(&htim6);
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}

/**
* @brief This function handles TIM7 global interrupt.
*/
void TIM7_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM7_IRQn);
  HAL_TIM_IRQHandler(&htim7);
}

/**
* @brief This function handles I2C1 error interrupt.
*/
void I2C1_ER_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(I2C1_ER_IRQn);
  HAL_I2C_ER_IRQHandler(&hi2c1);
}

/**
* @brief This function handles I2C1 event interrupt.
*/
void I2C1_EV_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(I2C1_EV_IRQn);
  HAL_I2C_EV_IRQHandler(&hi2c1);
}

/**
* @brief This function handles DMA1 Stream5 global interrupt.
*/
void DMA1_Stream5_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(DMA1_Stream5_IRQn);
  HAL_DMA_IRQHandler(&hdma_i2c1_rx);
}

/**
* @brief This function handles TIM1 Update interrupt and TIM10 global interrupt.
*/
void TIM1_UP_TIM10_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM1_UP_TIM10_IRQn);
  HAL_TIM_IRQHandler(&htim1);
  HAL_TIM_IRQHandler(&htim10);
}

/**
* @brief This function handles TIM3 global interrupt.
*/
void TIM3_IRQHandler(void)
{
  HAL_NVIC_ClearPendingIRQ(TIM3_IRQn);
  HAL_TIM_IRQHandler(&htim3);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/