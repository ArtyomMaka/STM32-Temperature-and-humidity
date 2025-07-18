/*
 * button.c
 *
 *  Created on: Jul 4, 2025
 *      Author: makar
 */

#include "button.h"

int button_up(GPIO_TypeDef *GPIOx, uint16_t PIN) {
	int last_button_state = 0;
	int state = HAL_GPIO_ReadPin(GPIOx, PIN);
	int result = 0;

	if (state && !last_button_state) {
		result = 1;
	} else {
		result = 0;
	}
	last_button_state = state;

	return result;
}
