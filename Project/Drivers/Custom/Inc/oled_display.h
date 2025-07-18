/*
 * oled_display.h
 *
 *  Created on: Jul 6, 2025
 *      Author: makar
 */

#ifndef INC_OLED_DISPLAY_H_
#define INC_OLED_DISPLAY_H_

#include "stm32f1xx_hal.h"

void oled_power();
void oled_cmd_send(SPI_HandleTypeDef *spi, uint8_t cmd);
void oled_ram_send_byte(SPI_HandleTypeDef *spi, uint8_t data);
void oled_ram_send(SPI_HandleTypeDef *spi, uint8_t data, uint32_t size);
void oled_init(SPI_HandleTypeDef *spi);
void oled_clear(SPI_HandleTypeDef *spi);
void oled_fill(SPI_HandleTypeDef *spi, uint8_t value);
int oled_draw_char(SPI_HandleTypeDef *spi, char c);
void oled_string_print(SPI_HandleTypeDef *spi, const char *str);
void oled_string_println(SPI_HandleTypeDef *spi, const char *str);
#endif /* INC_OLED_DISPLAY_H_ */
