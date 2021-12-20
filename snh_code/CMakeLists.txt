cmake_minimum_required(VERSION 3.6.1)

# Configuration types
set(CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo")
if(win32)
  if(NOT OIDN_DEFAULT_CMAKE_CONFIGURATION_TYPES_SET)
    set(CMAKE_CONFIGURATION_TYPES "${CONFIGURATION_TYPES}"
        CACHE STRING "List of generated configurations." FORCE)
    set(OOIDN_DEFAULT_CMAKE_CONFIGURATION_TYPES_SET ON
        CACHE INTERNAL "Default CMake configuration types set.")
  endif()
else()
  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type." FORCE)
  endif()
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CONFIGURATION_TYPES})
endif()

# Output paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cubeSimulation
  LANGUAGES C CXX
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(cubesim)
add_subdirectory(hexcli)
add_subdirectory(tetcli)
