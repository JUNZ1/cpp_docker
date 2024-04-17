project(testLib)
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.*)
add_library(${PROJECT_NAME} SHARED ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
