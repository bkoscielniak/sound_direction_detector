/**
  ******************************************************************************
  * @file    main.h
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "stm32f7xx_hal.h"
#include "stm32f769i_discovery.h"
#include "stm32f769i_discovery_lcd.h"

/* Exported types ------------------------------------------------------------*/
typedef struct
{
  void   (*DemoFunc)(void);
  uint8_t DemoName[50];
  uint32_t DemoIndex;
}BSP_DemoTypedef;

typedef enum {
  AUDIO_ERROR_NONE = 0,
  AUDIO_ERROR_NOTREADY,
  AUDIO_ERROR_IO,
  AUDIO_ERROR_EOF,
}AUDIO_ErrorTypeDef;

/* Exported variables --------------------------------------------------------*/
extern const unsigned char stlogo[];
extern __IO uint32_t SdmmcTest;
extern __IO uint32_t SdramTest;
/* Exported constants --------------------------------------------------------*/

/* LCD Frame buffer start address : starts at beginning of SDRAM */
#define ARBG8888_BYTE_PER_PIXEL   4
#define LCD_FB_LENGTH              ((uint32_t)(OTM8009A_480X800_HEIGHT * OTM8009A_480X800_WIDTH * ARBG8888_BYTE_PER_PIXEL))
#define SDRAM_WRITE_READ_ADDR        ((uint32_t)0xC0177000)

/* Exported macro ------------------------------------------------------------*/
#define COUNT_OF_EXAMPLE(x)    (sizeof(x)/sizeof(BSP_DemoTypedef))

#ifdef USE_FULL_ASSERT
/* Assert activated */
#define BSP_TEST_APPLI_ASSERT(__error_condition__)    do { if(__error_condition__) \
                                                           {  while(1);  \
                                                           } \
                                                          } while(0)
#else
/* Assert not activated : macro has no effect */
#define BSP_TEST_APPLI_ASSERT(__error_condition__)    do { if(__error_condition__) \
                                                           {  ;  \
                                                           } \
                                                         } while(0)
#endif /* USE_FULL_ASSERT */

/* Exported functions ------------------------------------------------------- */
void AudioLoopback_demo(void);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
