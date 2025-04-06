/*
 * led.c
 *
 *  Created on: 6 апр. 2025 г.
 */
#include "led.h"
#include "main.h"

void LED_OnOf(void) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_Delay(700);
}

