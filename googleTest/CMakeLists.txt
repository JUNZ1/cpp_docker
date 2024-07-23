# unitTests/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(googletest)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 11)

# External install location
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

# Google Test'i indir ve kur
ExternalProject_Add(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG "origin/main"
    PREFIX ${CMAKE_BINARY_DIR}/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

# Kurulan kütüphaneyi ve include dosyalarını ekle
add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
    IMPORTED_LOCATION ${EXTERNAL_INSTALL_LOCATION}/lib/libgtest.a
    INTERFACE_INCLUDE_DIRECTORIES ${EXTERNAL_INSTALL_LOCATION}/include
)

add_library(gtest_main STATIC IMPORTED)
set_target_properties(gtest_main PROPERTIES
    IMPORTED_LOCATION ${EXTERNAL_INSTALL_LOCATION}/lib/libgtest_main.a
    INTERFACE_INCLUDE_DIRECTORIES ${EXTERNAL_INSTALL_LOCATION}/include
)

# gtest kütüphanelerini bir bağımlılık olarak ekle
add_dependencies(gtest googletest)
add_dependencies(gtest_main googletest)