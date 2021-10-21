/**
  ******************************************************************************
  * @file    audio_application.c
  * @author  SRA
  * @version v1.3.0
  * @date    17-Sep-2021
  * @brief   Source localization example.
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

/* Includes ------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

#include "audio_application.h"
#include "acoustic_sl.h"

uint16_t PCM_Buffer[AUDIO_IN_CHANNELS*AUDIO_IN_SAMPLING_FREQUENCY/1000];
AcousticSL_Handler_t libSoundSourceLoc_Handler_Instance;
AcousticSL_Config_t  libSoundSourceLoc_Config_Instance;
volatile int16_t  SOURCE_Angle_Value = 0;
volatile uint16_t SOURCE_Enable_Value = 1;
volatile int32_t result[2];

void BSP_AUDIO_IN_HalfTransfer_CallBack()
{
  AudioProcess();
}

void BSP_AUDIO_IN_TransferComplete_CallBack()
{
  AudioProcess();
}

/**
* @brief  User function that is called when 1 ms of PDM data is available.
* 		  In this application only PDM to PCM conversion and USB streaming
*                  is performed.
* 		  User can add his own code here to perform some DSP or audio analysis.
*                In this case audio libraries are used
* @param  none
* @retval None
*/
void AudioProcess(void)
{
  if(AcousticSL_Data_Input((int16_t *)&PCM_Buffer[BOTTOM_LEFT_MIC],
                           (int16_t *)&PCM_Buffer[TOP_RIGHT_MIC],
                           (int16_t *)&PCM_Buffer[BOTTOM_RIGHT_MIC],
                           (int16_t *)&PCM_Buffer[TOP_LEFT_MIC],
                           &libSoundSourceLoc_Handler_Instance) == 1U)
  {
    SW_Task2_Start(); /*Localization Processing Task*/
  }
}

/**
* @brief  Initialize the audio libraries adopted
* @param  None
* @retval None
*/
void Audio_Libraries_Init(void)
{
  volatile uint32_t error_value = 0;
  /* Enable CRC peripheral to unlock the library */
  __CRC_CLK_ENABLE();

  /*Setup Source Localization static parameters*/
  libSoundSourceLoc_Handler_Instance.channel_number = 4;
  libSoundSourceLoc_Handler_Instance.M12_distance =DIAGONAL;
  libSoundSourceLoc_Handler_Instance.M34_distance =DIAGONAL;
  libSoundSourceLoc_Handler_Instance.sampling_frequency = AUDIO_IN_SAMPLING_FREQUENCY;
  libSoundSourceLoc_Handler_Instance.algorithm = ACOUSTIC_SL_ALGORITHM_GCCP;
  libSoundSourceLoc_Handler_Instance.ptr_M1_channels = 4;
  libSoundSourceLoc_Handler_Instance.ptr_M2_channels = 4;
  libSoundSourceLoc_Handler_Instance.ptr_M3_channels = 4;
  libSoundSourceLoc_Handler_Instance.ptr_M4_channels = 4;
  libSoundSourceLoc_Handler_Instance.samples_to_process = 512;
  (void)AcousticSL_getMemorySize( &libSoundSourceLoc_Handler_Instance);
  libSoundSourceLoc_Handler_Instance.pInternalMemory=(uint32_t *)malloc(libSoundSourceLoc_Handler_Instance.internal_memory_size);
  error_value += AcousticSL_Init( &libSoundSourceLoc_Handler_Instance);

  /*Setup Source Localization dynamic parameters*/
  libSoundSourceLoc_Config_Instance.resolution=10;
  libSoundSourceLoc_Config_Instance.threshold=24;
  error_value += AcousticSL_setConfig(&libSoundSourceLoc_Handler_Instance, &libSoundSourceLoc_Config_Instance);

  /*Error Management*/
  if(error_value != 0U)
  {
    Error_Handler();
  }

  /*Malloc Failure*/
  if(libSoundSourceLoc_Handler_Instance.pInternalMemory == NULL)
  {
    Error_Handler();
  }

}

/**
* @brief  Initializes two SW interrupt with different priorities
* @param  None
* @retval None
*/
void SW_IRQ_Tasks_Init(void)
{
  HAL_NVIC_SetPriority((IRQn_Type)EXTI1_IRQn, 0x0D, 0);
  HAL_NVIC_EnableIRQ((IRQn_Type)EXTI1_IRQn);

  HAL_NVIC_SetPriority((IRQn_Type)EXTI2_IRQn, 0x0E, 0);
  HAL_NVIC_EnableIRQ((IRQn_Type)EXTI2_IRQn);

}


/**
* @brief  Highest priority interrupt handler routine
* @param  None
* @retval None
*/
void SW_Task1_Callback(void)
{

}

/**
* @brief Lower priority interrupt handler routine
* @param  None
* @retval None
*/

void SW_Task2_Callback(void)
{
  (void)AcousticSL_Process((int32_t *)&result, &libSoundSourceLoc_Handler_Instance);

  if(result[0]==ACOUSTIC_SL_NO_AUDIO_DETECTED)
  {
    result[0] = -1;
  }

  if(result[0] != -1)
  {
    //char output[4];
    //int32_t n = sprintf(output,"%i",(int32_t)result[0]);
    //(void)HAL_UART_Transmit(&UartHandle, (uint8_t *)"    ", 4, 0xFFFF);
    //(void)HAL_UART_Transmit(&UartHandle, (uint8_t *)"\r", 1, 0xFFFF);
    //(void)HAL_UART_Transmit(&UartHandle, (uint8_t *)output, (uint16_t)n, 0xFFFF);
  }
}


/**
* @brief Throws Highest priority interrupt
* @param  None
* @retval None
*/
void SW_Task1_Start(void)
{
  HAL_NVIC_SetPendingIRQ(EXTI1_IRQn);
}

void SW_Task2_Start(void)
{
  HAL_NVIC_SetPendingIRQ(EXTI2_IRQn);
}


void Error_Handler(void)
{
  while(1);
}


/**
* @}
*/

/**
* @}
*/

/**
* @}
*/

/**
* @}
*/
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
