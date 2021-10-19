find_package(Git)

if(GIT_FOUND)
  execute_process(COMMAND ${GIT_EXECUTABLE} describe --always --dirty --tags
    OUTPUT_VARIABLE GIT_DESCRIBE_VERSION
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

  if(GIT_DESCRIBE_VERSION)
    string(STRIP ${GIT_DESCRIBE_VERSION} GIT_DESCRIBE_VERSION)
    set(GIT_VERSION_RAW "${GIT_DESCRIBE_VERSION}")
    set(GIT_DESCRIBE_VERSION_REGEX
      "^v([0-9]*)\.([0-9]*)\.([0-9]*)([a-zA-Z0-9_-]*)$")
    string(REGEX MATCH ${GIT_DESCRIBE_VERSION_REGEX} GIT_DESCRIBE_MATCH
      ${GIT_DESCRIBE_VERSION})

    if(NOT GIT_DESCRIBE_MATCH)
      message(WARNING "Wrong git describe version: ${GIT_DESCRIBE_VERSION}")
    else()
      string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" GIT_VERSION_MAJOR
        "${GIT_DESCRIBE_VERSION}")
      string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" GIT_VERSION_MINOR
        "${GIT_DESCRIBE_VERSION}")
      string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1"
        GIT_VERSION_PATCH "${GIT_DESCRIBE_VERSION}")
    endif()
  endif()
endif()

if(GIT_VERSION_RAW)
  set(APP_VERSION_RAW "${GIT_VERSION_RAW}")
else()
  set(APP_VERSION_RAW "unknown")
endif()

if(GIT_VERSION_MAJOR)
  set(APP_VERSION_MAJOR "${GIT_VERSION_MAJOR}")
else()
  set(APP_VERSION_MAJOR "0")
endif()

if(GIT_VERSION_MINOR)
  set(APP_VERSION_MINOR "${GIT_VERSION_MINOR}")
else()
  set(APP_VERSION_MINOR "0")
endif()

if(GIT_VERSION_PATCH)
  set(APP_VERSION_PATCH "${GIT_VERSION_PATCH}")
else()
  set(APP_VERSION_PATCH "0")
endif()

message("Application version tag:\
  ${APP_VERSION_MAJOR}.${APP_VERSION_MINOR}.${APP_VERSION_PATCH}\
  (raw: ${APP_VERSION_RAW})")
