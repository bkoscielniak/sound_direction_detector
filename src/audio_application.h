/**
  ******************************************************************************
  * @file    audio_application.h
  * @author  SRA
  * @version v1.3.0
  * @date    17-Sep-2021
  * @brief   Header for audio_application.c module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0055, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0055
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AUDIO_APPLICATION_H
#define __AUDIO_APPLICATION_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32xx_it.h"
#include "stm32f769i_discovery.h"
//#include "stm32f769i_discovery_audio_ex.h"

/** @addtogroup X_CUBE_MEMSMIC1_Applications
  * @{
  */

/** @addtogroup ACOUSTIC_SL_Example
  * @{
  */

/** @defgroup AUDIO_APPLICATION
  * @{
  */

 /** @defgroup AUDIO_APPLICATION_Private_Types
  * @{
  */

  /**
  * @}
  */

/* The N_MS value defines the number of millisecond to be processed at each AudioProcess call,
that must be consistent with the N_MS_PER_INTERRUPT defined in the audio driver
(stm32f769i_discovery_audio_ex.h).
The default value of the N_MS_PER_INTERRUPT directive in the driver is set to 1,
for backward compatibility: leaving this values as it is allows to avoid any
modification in the application layer developed with the older versions of the driver */


#define N_MS (N_MS_PER_INTERRUPT)

#define AUDIO_IN_CHANNELS 4
#define AUDIO_IN_SAMPLING_FREQUENCY 16000

#define AUDIO_IN_BUFFER_SIZE            (AUDIO_IN_CHANNELS*AUDIO_IN_SAMPLING_FREQUENCY/1000)
#define AUDIO_VOLUME_INPUT              64U
#define STM32F769I_DISCOVERY_AUDIO_INSTANCE             1U /*Select 0U or 1U in base of the peripheral used (0U->I2S/SAI 1U->DFSDM)*/
#define STM32F769I_DISCOVERY_AUDIO_IN_IT_PRIORITY       5U

#if (AUDIO_IN_SAMPLING_FREQUENCY == 8000)
#define MAX_DECIMATION_FACTOR 160
#else
#define MAX_DECIMATION_FACTOR 128
#endif


/* 	If you want to customize the length of the buffers used into the BSP, uncomment and modify these defines.
	Change the values according to the max PDM clock you want to customize and number of microphones you want to use
*/

//	#define MAX_MIC_FREQ                 	  3072  /*kHz - Maximum PDM clock */
//	#define MAX_AUDIO_IN_CHANNEL_NBR_PER_IF   2 /* Maximum number of microhpones channels for peripheral interface */
//	#define MAX_AUDIO_IN_CHANNEL_NBR_TOTAL    4 /* For WB, this must be minimum equal to 2 */


//  #define USE_SPI3
/*If you want to use SPI3 instead of SPI2 for M3 and M4, uncomment this define and
close SB20 and SB21*/

//  #define PDM_FREQ_16K 2048
/*Uncomment if you need to change PDM clock frequency when AUDIO_IN_SAMPLING_FREQUENCY = 16000*/

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup AUDIO_APPLICATION_Exported_Defines
 * @{
 */

#define TOP_LEFT_MIC 3
#define TOP_RIGHT_MIC 0
#define BOTTOM_LEFT_MIC 2
#define BOTTOM_RIGHT_MIC 1
#define SIDE 147
#define DIAGONAL 212

/**
 * @}
 */
/* Exported functions ------------------------------------------------------- */
void Audio_Libraries_Init(void);
void Error_Handler(void);
void AudioProcess(void);
void SW_IRQ_Tasks_Init(void);
void SW_Task1_Callback(void);
void SW_Task2_Callback(void);
void SW_Task1_Start(void);
void SW_Task2_Start(void);


/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */



#endif /* __AUDIO_APPLICATION_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
