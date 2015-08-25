/**************************************************************************/
/*!
    @file    ADXRS620.c
    @author  PLF (PACABOT)
    @date
    @version  0.0
 */
/**************************************************************************/
#include "stm32f4xx_hal.h"

#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "smallfonts.h"
#include "ssd1306.h"
#include "pictures.h"
#include "PCF8574.h"

#define RATIO 10

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim10;

__IO uint32_t uhADCxConvertedValue_LDIAG  = 0;
__IO uint32_t uhADCxConvertedValue_RDIAG  = 0;
__IO uint32_t uhADCxConvertedValue_LFRONT = 0;
__IO uint32_t uhADCxConvertedValue_RFRONT = 0;

volatile int L_diag_distance   = 0;
volatile int R_diag_distance   = 0;
volatile int L_front_distance  = 0;
volatile int R_front_distance  = 0;

GPIO_InitTypeDef GPIO_InitStruct;
/**
  * @brief  Period elapsed callback in non blocking mode
  * @param  htim : TIM handle
  * @retval None
  */
void Telemeters_Init(void)
{
	ADC_ChannelConfTypeDef sConfig;

	HAL_ADC_Stop_DMA(&hadc1);
	sConfig.Channel = ADC_CHANNEL_6;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&uhADCxConvertedValue_LFRONT, 1);
	HAL_ADC_Start(&hadc1);

	  /*##-1- Configure the TIM peripheral #######################################*/
	  /* -----------------------------------------------------------------------
	    In this example TIM3 input clock (TIM3CLK) is set to 2 * APB1 clock (PCLK1),
	    since APB1 prescaler is different from 1.
	      TIM3CLK = 2 * PCLK1
	      PCLK1 = HCLK / 4
	      => TIM3CLK = HCLK / 2 = SystemCoreClock /2
	    To get TIM3 counter clock at 10 KHz, the Prescaler is computed as following:
	    Prescaler = (TIM3CLK / TIM3 counter clock) - 1
	    Prescaler = ((SystemCoreClock /2) /10 KHz) - 1
	      ----------------------------------------------------------------------- */

	  uint32_t uwPrescalerValue = 0;
	  /* Compute the prescaler value to have TIM3 counter clock equal to 100 KHz */

	  uwPrescalerValue = (uint32_t) ((SystemCoreClock /2) / 1000000) - 1;

	  htim10.Instance = TIM10;
	  htim10.Init.Prescaler =  uwPrescalerValue;
	  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim10.Init.Period = 5-1;
	  HAL_TIM_Base_Init(&htim10);

	  /*##-2- Start the TIM Base generation in interrupt mode ####################*/
	  /* Start Channel1 */
	  if(HAL_TIM_Base_Start_IT(&htim10) != HAL_OK)
	  {
	    /* Starting Error */
//	    Error_Handler();
	  }
}

void Telemeters_IT(void)
{
	  static char selector;
	  ADC_ChannelConfTypeDef sConfig;

	  switch ( selector )
	  {
	  case 1:
		  HAL_ADC_Stop_DMA(&hadc1);
		  sConfig.Channel = ADC_CHANNEL_6;
		  sConfig.Rank = 1;
		  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
		  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
		  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&uhADCxConvertedValue_LFRONT, 1);
		break;
      case 2:
		  L_front_distance = uhADCxConvertedValue_LFRONT;
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
	    break;
	  case 3:
		  HAL_ADC_Stop_DMA(&hadc1);
		  sConfig.Channel = ADC_CHANNEL_11;
		  sConfig.Rank = 1;
		  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;
		  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&uhADCxConvertedValue_RFRONT, 1);
		break;
	  case 4:
		  R_front_distance = uhADCxConvertedValue_RFRONT;
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
	    break;
	  case 5:
		  HAL_ADC_Stop_DMA(&hadc1);
		  sConfig.Channel = ADC_CHANNEL_5;
		  sConfig.Rank = 1;
		  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;
		  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
		  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&uhADCxConvertedValue_LDIAG, 1);
	    break;
	  case 6:
		  L_diag_distance = uhADCxConvertedValue_LDIAG;
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		break;
	  case 7:
		  HAL_ADC_Stop_DMA(&hadc1);
		  sConfig.Channel = ADC_CHANNEL_10;
		  sConfig.Rank = 1;
		  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;
		  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
		  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&uhADCxConvertedValue_RDIAG, 1);
	    break;
	  case 8:
		  R_diag_distance = uhADCxConvertedValue_RDIAG;
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
	    break;
	  }

	  selector++;
	  if (selector > ((800 / RATIO)+1))
		  selector = 0;
}

