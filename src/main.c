/*
 * Copyright (c) 2021 Bartosz Kościelniak <kostek233@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <logging/log.h>
LOG_MODULE_REGISTER(main);

#include "stm32f769i_discovery_lcd.h"

void main(void)
{
	uint8_t lcd_status = LCD_OK;

	/* Initialize the LCD */
        lcd_status = BSP_LCD_Init();
        while(lcd_status != LCD_OK);

        BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
        BSP_LCD_Clear(LCD_COLOR_WHITE);

	LOG_INF("Welcome to Sound Direction Detector, version: %u.%u.%u (%s)",
		APP_VERSION_MAJOR, APP_VERSION_MINOR, APP_VERSION_PATCH,
		APP_VERSION_STRING);
}
