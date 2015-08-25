/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private variables ---------------------------------------------------------*/
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim10;

//#include "TimesBase.h"
#include "ADXRS620.h"
#include "Telemeters.h"
#include "IE512.h"
#include "PID.h"
#include "TimesBase.h"


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	  if( htim == &htim10)
	  {
		  Telemeters_IT();
	  }
	  if( htim == &htim7)
	  {
		  High_Freq_IT();
	  }
	  if( htim == &htim6)
	  {
		  Low_Freq_IT();
	  }
	  if( htim == &htim1)
	  {
		  Left_Encoder_IT();
	  }
	  if( htim == &htim3)
	  {
		  Right_Encoder_IT();
	  }
}
