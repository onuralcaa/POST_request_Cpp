cmake_minimum_required(VERSION 3.10)
project(POST_Request_C++)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find libcurl
find_package(CURL REQUIRED)

# Include directories
include_directories(${CURL_INCLUDE_DIRS})

# Add the executable
add_executable(program main.cpp)

# Link libcurl
target_link_libraries(program ${CURL_LIBRARIES})

