# SPDX-License-Identifier: Apache-2.0

if(CONFIG_OTM8009A)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(otm8009a.c)
endif()
