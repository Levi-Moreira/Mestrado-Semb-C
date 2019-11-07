cmake_minimum_required(VERSION 3.15)
project(semb)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 17)

add_executable(semb main.cpp data/file_loading.h data/file_loading.cpp layers/convolution.h layers/convolution.cpp data/data_manipulation.h data/data_manipulation.cpp layers/pooling.h layers/pooling.cpp layers/activation.h layers/activation.cpp layers/batch_norm.h layers/batch_norm.cpp layers/fully_connected.h layers/fully_connected.cpp constants.h layers/forward_pass.h layers/forward_pass.cpp)