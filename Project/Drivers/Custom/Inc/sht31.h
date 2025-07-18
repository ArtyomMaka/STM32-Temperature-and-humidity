/*
 * sht31.h
 *
 *  Created on: Jul 7, 2025
 *      Author: makar
 */

#ifndef CUSTOM_INC_SHT31_H_
#define CUSTOM_INC_SHT31_H_

#include "stm32f1xx_hal.h"

void sht31_get_temp_and_humd(I2C_HandleTypeDef *hi2c, float *temperature, float *humidity);

#endif /* CUSTOM_INC_SHT31_H_ */
