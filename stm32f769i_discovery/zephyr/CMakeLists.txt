# SPDX-License-Identifier: Apache-2.0

if(CONFIG_STM32F769I_DISCOVERY)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(stm32f769i_discovery.c)
  zephyr_library_sources(stm32f769i_discovery_audio.c)
  #zephyr_library_sources(stm32f769i_discovery_audio_ex.c)
  zephyr_library_sources(stm32f769i_discovery_lcd.c)
  zephyr_library_sources(stm32f769i_discovery_sdram.c)
endif()
