/**
******************************************************************************
* @file    acousticSL.c
* @author  SRA
* @version v3.0.0
* @date    8-Sep-2021
* @brief   Acoustic Sound Source Localization APIs
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2021 STMicroelectronics</center></h2>
*
* Licensed under Software License Agreement SLA0077, (the "License"). 
* You may not use this package except in compliance with the License. 
* You may obtain a copy of the License at:
*
* http://www.st.com/content/st_com/en/search.html#q=SLA0077-t=keywords-page=1
*
* Some of the library code is based on the CMSIS DSP software library by ARM,
* a suite of common signal processing functions for use on Cortex-M processor
* based devices. Licencing terms are available in the attached release_note.html
* file, in the application note, in the next lines of this
* document and it's available on the web at:
* http://www.keil.com/pack/doc/CMSIS/DSP/html/index.html
*
*   ARM licence note:
*
* Copyright (C) 2009-2012 ARM Limited.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of ARM nor the names of its contributors may be used
*   to endorse or promote products derived from this software without
*   specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "libSoundSourceLoc.c"

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Functions Definition ------------------------------------------------------*/

/** @addtogroup MIDDLEWARES
  * @{
  */

/** @defgroup AcousticSL AcousticSL
  * @{
  */

  /** @defgroup AcousticSL_Exported_Functions AcousticSL Exported Functions
 * @{
 */

/**
 * @brief  Library initialization.
 * @param  pHandler: AcousticSL_Handler_t filled with desired parameters.
 * @retval 0 if everything is fine.
 *         different from 0 if erroneous parameters have been passed to the Init function and the default value has been used.
 *         The specific error can be recognized by checking the relative bit in the returned word.
 */
uint32_t AcousticSL_Init(AcousticSL_Handler_t * pHandler)
{   
  return libSoundSourceLoc_Init(pHandler);
}

/**
 * @brief  Library data input
 * @param  pM1: pointer to an array that contains PCM samples (16 bit signed int)
 *         representing 1 ms of data acquired by the first channel.
 * @param  pM2: pointer to an array that contains PCM samples (16 bit signed int)
 *         representing 1 ms of data acquired by the second channel.
 * @param  pM3: pointer to an array that contains PCM samples (16 bit signed int)
 *         representing 1 ms of data acquired by the third channel.
 * @param  pM4: pointer to an array that contains PCM samples (16 bit signed int)
 *         representing 1 ms of data acquired by the fourth channel.
 * @param  pHandler: pointer to the handler of the curent Source Localization instance running.
 * @retval 1 if data collection is finished and libSoundSourceLoc_Process must be called, 0 otherwise.
 * @note   Input function reads samples skipping the required number of values depending on the Ptr_Mx_Channels configuration.
 * @note   pM3 and pM4 are ignored in the case the library is setup for using 2 channels.
*/
uint32_t AcousticSL_Data_Input(void *pM1, void *pM2, void *pM3, void *pM4, AcousticSL_Handler_t * pHandler)
{
return libSoundSourceLoc_Data_Input((int16_t *)pM1, (int16_t *)pM2, (int16_t *)pM3, (int16_t *)pM4, pHandler);
}

/**
 * @brief  Library run function, performs audio analysis when all required data has been collected.
 * @param  Estimated_Angle: pointer to the int32_t variable that will contain the computed value.
 * @param  pHandler: pointer to the handler of the current Source Localization instance running.
 * @retval 0 if everything is ok, 1 otherwise
*/
uint32_t AcousticSL_Process(int32_t * Estimated_Angle, AcousticSL_Handler_t * pHandler)
{
  return libSoundSourceLoc_Process(Estimated_Angle, pHandler);
}

/**
 * @brief  Library setup function, it sets the values for threshold and resolution. It can be called at runtime to change
 *         dynamic parameters.
 * @note   Only the threshold and resolution are evaluated by the SetConfig function.
 * @retval 0 if everything is fine.
 *         different from 0 if erroneous parameters have been passed to the Init function and the default value has been used.
 *         The specific error can be recognized by checking the relative bit in the returned word.
*/
uint32_t AcousticSL_setConfig(AcousticSL_Handler_t * pHandler, AcousticSL_Config_t * pConfig)
{
  return libSoundSourceLoc_setConfig(pHandler, pConfig);
}

/**
 * @brief  Fills the pConfig structure with the actual dynamic parameters as they are currently used inside the library.
 * @param  pHandler: pointer to the handler of the current Source Localization instance running.
 * @param  pConfig: pointer to the dynamic parameters handler that will be filled with the current library configuration
 * @retval 0 if everything is fine.
*/
uint32_t AcousticSL_getConfig(AcousticSL_Handler_t * pHandler, AcousticSL_Config_t * pConfig)
{
  return libSoundSourceLoc_getConfig(pHandler, pConfig);
}

/**
 * @brief  Fills the "internal_memory_size" of the pHandler parameter passed as argument with a value representing the
 *         right amount of memory needed by the library, depending on the specific static parameters adopted.
 * @param  pHandler: AcousticSL_Handler_t filled with desired parameters.
 * @retval 0 if everything is fine.
 */
uint32_t AcousticSL_getMemorySize(AcousticSL_Handler_t * pHandler)
{
  return libSoundSourceLoc_getMemorySize(pHandler);
}

/**
 * @brief  To be used to retrieve version information.
 * @param  version char array to be filled with the current library version
 * @retval 0 if everything is fine.
*/
uint32_t AcousticSL_GetLibVersion(char *version)
{
  return libSoundSourceLoc_GetLibVersion(version);
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
