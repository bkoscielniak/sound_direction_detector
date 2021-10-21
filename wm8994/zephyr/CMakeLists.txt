# SPDX-License-Identifier: Apache-2.0

if(CONFIG_WM8994)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(wm8994.c)
endif()
