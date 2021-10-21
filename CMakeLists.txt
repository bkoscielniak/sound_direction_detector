# SPDX-License-Identifier: Apache-2.0

# add needed extra modules (out of Zephyr)
list(APPEND ZEPHYR_EXTRA_MODULES
  ${CMAKE_CURRENT_SOURCE_DIR}/acousticSL
  ${CMAKE_CURRENT_SOURCE_DIR}/adv7533
  ${CMAKE_CURRENT_SOURCE_DIR}/fonts
  ${CMAKE_CURRENT_SOURCE_DIR}/otm8009a
  ${CMAKE_CURRENT_SOURCE_DIR}/stm32f769i_discovery
  ${CMAKE_CURRENT_SOURCE_DIR}/PDM
  ${CMAKE_CURRENT_SOURCE_DIR}/wm8994
  )

cmake_minimum_required(VERSION 3.20.0)

#default board
set(BOARD stm32f769i_disco)

#resolve project version
include(cmake/gitversion.cmake)
add_definitions(-DAPP_VERSION_STRING="${APP_VERSION_RAW}")
add_definitions(-DAPP_VERSION_MAJOR=${APP_VERSION_MAJOR})
add_definitions(-DAPP_VERSION_MINOR=${APP_VERSION_MINOR})
add_definitions(-DAPP_VERSION_PATCH=${APP_VERSION_PATCH})

#find and include zephyr dependencies
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

#set project name
project(sound_direction_detector)

#application source files
FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
