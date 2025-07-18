/*
 * app_main.c
 *
 *  Created on: Jul 7, 2025
 *      Author: makar
 */
#define DATA_UPDATE_TIME			3000
#define BUTTON_TIME					130
#define IDLE_TIME					3000

#include "app_main.h"
#include "button.h"
#include "oled_display.h"
#include "sht31.h"
#include <stdio.h>
#include <stdbool.h>

extern SPI_HandleTypeDef hspi1;
extern I2C_HandleTypeDef hi2c1;

float temp = 0;
float humd = 0;
char buffer_temp[16];
char buffer_humd[16];
uint32_t prevTime = 0;
uint32_t prevTimeButton = 0;
uint32_t prevTimeIdle = 0;
bool run = false;

void app_main() {
	oled_init(&hspi1);
	oled_clear(&hspi1);
	oled_string_print(&hspi1, "init");
	HAL_Delay(1000);
	oled_draw_char(&hspi1, '.');
	HAL_Delay(1000);
	oled_draw_char(&hspi1, '.');
	HAL_Delay(1000);
	oled_draw_char(&hspi1, '.');
	HAL_Delay(1000);
	oled_clear(&hspi1);
	oled_string_print(&hspi1, "press button");
	while (1) {
		uint32_t time = HAL_GetTick();
		if (run && time - prevTime >= DATA_UPDATE_TIME) {
			oled_clear(&hspi1);
			sht31_get_temp_and_humd(&hi2c1, &temp, &humd);
			snprintf(buffer_temp, sizeof(buffer_temp), "%.2f", temp);
			snprintf(buffer_humd, sizeof(buffer_humd), "%.2f", humd);
			oled_string_print(&hspi1, "Temperature: ");
			oled_string_println(&hspi1, buffer_temp);
			oled_string_print(&hspi1, "Humidity: ");
			oled_string_print(&hspi1, buffer_humd);
			prevTime = time;
		}
		if (!run && time - prevTimeIdle >= IDLE_TIME) {
			oled_clear(&hspi1);
			oled_string_print(&hspi1, "press button");
			prevTimeIdle = time;
		}
		if (button_up(GPIOB, GPIO_PIN_0) && time - prevTimeButton >= BUTTON_TIME) {
			run = !run;
			oled_clear(&hspi1);
			oled_string_print(&hspi1, "init...");
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
			prevTimeButton = time;
		}
	}
}
