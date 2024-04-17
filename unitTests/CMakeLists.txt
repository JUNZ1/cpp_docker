project(unitTests)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.*)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_SOURCE_DIR}/external)

ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG "origin/main"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(${PROJECT_NAME} unitTest.cpp)
target_link_libraries(${PROJECT_NAME} gtest gmock testLib pthread)