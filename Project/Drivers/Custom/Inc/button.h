/*
 * button.h
 *
 *  Created on: Jul 4, 2025
 *      Author: makar
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32f1xx_hal.h"

int button_up(GPIO_TypeDef *GPIOx, uint16_t PIN);

#endif /* INC_BUTTON_H_ */
