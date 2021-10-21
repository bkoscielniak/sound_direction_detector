/*
 * Copyright (c) 2021 Bartosz Kościelniak <kostek233@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <logging/log.h>
LOG_MODULE_REGISTER(main);

#include "main.h"
#include "stm32f7xx_hal.h"
#include "stm32f769i_discovery.h"
#include "stm32f769i_discovery_audio.h"
#include "stm32f769i_discovery_lcd.h"

#include "audio_application.h"

#define SCRATCH_BUFF_SIZE  512

extern uint16_t PCM_Buffer[AUDIO_IN_CHANNELS*AUDIO_IN_SAMPLING_FREQUENCY/1000];
int32_t Scratch[SCRATCH_BUFF_SIZE];

void main(void)
{
	int ret;
	uint8_t lcd_status = LCD_OK;

	/* Initialize the LCD */
        lcd_status = BSP_LCD_Init();
        while(lcd_status != LCD_OK);

        BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
        BSP_LCD_Clear(LCD_COLOR_WHITE);

	LOG_INF("Welcome to Sound Direction Detector, version: %u.%u.%u (%s)",
		APP_VERSION_MAJOR, APP_VERSION_MINOR, APP_VERSION_PATCH,
		APP_VERSION_STRING);

	BSP_AUDIO_IN_Init(AUDIO_IN_SAMPLING_FREQUENCY, 16, AUDIO_IN_CHANNELS);
	BSP_AUDIO_IN_AllocScratch(Scratch, SCRATCH_BUFF_SIZE);

        /* Initialize Acoustic_SL library */
        Audio_Libraries_Init();

        /* Initialize software interrupt tasks */
        SW_IRQ_Tasks_Init();

        /* Start audio acquisition */
	ret = BSP_AUDIO_IN_Record(PCM_Buffer, AUDIO_IN_BUFFER_SIZE);
        if (ret != AUDIO_OK) {
		LOG_ERR("Start audio acquisition error %d", ret);
		Error_Handler();
  	}

	LOG_INF("Recording started!");
}
