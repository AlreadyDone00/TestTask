/*
 * ADS1115.h
 *
 *  Created on: Apr 4, 2025
 */

#ifndef INC_ADS1115_H_
#define INC_ADS1115_H_
#define ADS1115_ADDRESS 0x48

#include "stdint.h"
#include "stm32f1xx_hal.h"

int16_t ADS1115_readChannel(I2C_HandleTypeDef *hi2c1, uint8_t ch);
void ADS1115_readAllChannels(I2C_HandleTypeDef *hi2c1, float *results);

#endif /* INC_ADS1115_H_ */
