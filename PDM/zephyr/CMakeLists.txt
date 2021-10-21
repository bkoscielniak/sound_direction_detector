# SPDX-License-Identifier: Apache-2.0

if(CONFIG_STM32_PDM)
  zephyr_include_directories(.)

  add_library(libstm32pdm STATIC IMPORTED)
  set_target_properties(libstm32pdm PROPERTIES IMPORTED_LOCATION
    ${CMAKE_CURRENT_LIST_DIR}/libPDMFilter_CM7_GCC_wc32.a)

    zephyr_library_link_libraries(libstm32pdm)
endif()
