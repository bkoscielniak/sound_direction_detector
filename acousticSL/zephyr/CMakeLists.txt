# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ACOUSTIC_SL)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(AcousticSL.c)
  #zephyr_library_sources(doa_via_block_sparsity.c)
  zephyr_library_sources(libSoundSourceLoc.c)

  add_library(libAcousticSL STATIC IMPORTED)
  set_target_properties(libAcousticSL PROPERTIES IMPORTED_LOCATION
    ${CMAKE_CURRENT_LIST_DIR}/lib/AcousticSL_CM7F_wc32_ot.a)

  zephyr_library_link_libraries(libAcousticSL)
endif()
