cmake_minimum_required(VERSION 3.20.0)

#default board and board's path
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
target_sources(app PRIVATE src/main.c)
