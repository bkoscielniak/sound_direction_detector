# SPDX-License-Identifier: Apache-2.0

if(CONFIG_FONTS)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(font8.c)
  zephyr_library_sources(font12.c)
  zephyr_library_sources(font16.c)
  zephyr_library_sources(font20.c)
  zephyr_library_sources(font24.c)
endif()
