# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ADV7533)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(adv7533.c)
endif()
