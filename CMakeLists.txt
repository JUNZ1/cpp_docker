cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(ExternalProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release)

#add_subdirectory(unitTests)
#add_subdirectory(src)
add_subdirectory(curl)
add_subdirectory(mainCPP)

