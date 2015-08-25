/**************************************************************************/
/*!
    @file     PID.c
    @author  PLF (PACABOT)
    @date
    @version  0.0
 */
/**************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "stm32f4xx_hal.h"

#include "stdbool.h"
#include <arm_math.h>

#include "stm32f4xx_hal.h"

#include "smallfonts.h"
#include "ssd1306.h"
#include "pictures.h"
#include "PCF8574.h"

#include <arm_math.h>

#include "PID.h"
#include "Straight_Controls.h"

/* extern variables ---------------------------------------------------------*/
/* global variables ---------------------------------------------------------*/

GPIO_InitTypeDef GPIO_InitStruct;

void Pid_Init(arm_pid_instance_f32 * instance);
void Pid_Reset(arm_pid_instance_f32 * instance);
float32_t Pid(arm_pid_instance_f32 * instance, float32_t error);

void Pid_Init(arm_pid_instance_f32 * instance)
{
	arm_pid_init_f32(instance, 1);
}

void Pid_Reset(arm_pid_instance_f32 * instance)
{
	arm_pid_reset_f32(instance);
}

float32_t Pid(arm_pid_instance_f32 * instance, float32_t error)
{
	return (arm_pid_f32(instance, error));
}

void Pids_IT(void)
{
	Straight_Control_IT();
}
