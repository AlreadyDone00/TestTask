/*
 * ADS1115.c
 *
 *  Created on: Apr 4, 2025
 */
#include "ADS1115.h"

int16_t ADS1115_readChannel(I2C_HandleTypeDef *hi2c1, uint8_t ch) // Функция для чтения значения с определенного канала
{
	unsigned char TX_buffer[6];
	unsigned char RX_buffer[6];
	TX_buffer[0] = 0x01;
    switch(ch) {
        case 0:
        	TX_buffer[1] = 0xC1;
            break;
        case 1:
        	TX_buffer[1] = 0xD1;
            break;
        case 2:
        	TX_buffer[1] = 0xE1;
            break;
        case 3:
        	TX_buffer[1] = 0xF1;
            break;
    }
	TX_buffer[2] = 0x83;
	//Request
	HAL_I2C_Master_Transmit_DMA(hi2c1, ADS1115_ADDRESS << 1, TX_buffer, 3);
	TX_buffer[0] = 0x00; //Очищаем
	HAL_I2C_Master_Transmit_DMA(hi2c1, ADS1115_ADDRESS << 1, TX_buffer, 1);
	HAL_Delay(20); // Ждем завершения преобразования
	//Response
	HAL_I2C_Master_Receive_DMA(hi2c1, ADS1115_ADDRESS << 1, RX_buffer, 2);
	int16_t reading = (RX_buffer[0] << 8 | RX_buffer[1]);
	if(reading < 0)
		{
			reading = 0;
		}

	return reading;
}

void ADS1115_readAllChannels(I2C_HandleTypeDef *hi2c1, float *results) { // Функция для опроса всех каналов
	const float voltageCoef = 6.114 / 32768.0;
    for (uint8_t ch = 0; ch < 4; ch++) {
        results[ch] = ADS1115_readChannel(hi2c1,ch) * voltageCoef;
    }
}
