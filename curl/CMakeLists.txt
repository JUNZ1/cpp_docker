# curl/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(curl_project)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 11)

# External install location
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

# Curl kütüphanesini indir ve kur
ExternalProject_Add(
    curl_src
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG master
    PREFIX ${CMAKE_BINARY_DIR}/curl
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

# Kurulan kütüphaneyi ve include dosyalarını ekle
add_library(curl STATIC IMPORTED)
set_target_properties(curl PROPERTIES
    IMPORTED_LOCATION ${EXTERNAL_INSTALL_LOCATION}/lib/libcurl.a
    INTERFACE_INCLUDE_DIRECTORIES ${EXTERNAL_INSTALL_LOCATION}/include
)

# curl kütüphanesini bir bağımlılık olarak ekle
add_dependencies(curl curl_src)