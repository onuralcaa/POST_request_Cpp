cmake_minimum_required(VERSION 3.10)

project(PostRequest)

set(CMAKE_CXX_STANDARD 17)

# CPR kütüphanesini manuel olarak dahil edin
include_directories(${CMAKE_SOURCE_DIR}/cpr/include)

# Find OpenSSL and ZLIB packages
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

# Proje dosyalarını ekleyin
add_executable(program main.cpp)

# CPR, OpenSSL ve ZLIB kütüphanelerini bağlayın
target_link_libraries(program PRIVATE cpr curl OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB)
