/*
 * sht.c
 *
 *  Created on: Jul 7, 2025
 *      Author: makar
 */

#include "sht31.h"

uint8_t slave_address = 0x44;

void sht31_get_temp_and_humd(I2C_HandleTypeDef *hi2c, float *temperature, float *humidity){
    uint8_t cmd[] = {0x24, 0x00};
    uint8_t data[6];

    HAL_I2C_Master_Transmit(hi2c, slave_address << 1, cmd, 2, 100);
    HAL_Delay(30);
    HAL_I2C_Master_Receive(hi2c, slave_address << 1, data, 6, 100);

    uint16_t raw_temp = (data[0] << 8) | data[1];
    uint16_t raw_hum  = (data[3] << 8) | data[4];

    *temperature = -45.0f + 175.0f * ((float)raw_temp / 65535.0f);
    *humidity    = 100.0f * ((float)raw_hum  / 65535.0f);
}

