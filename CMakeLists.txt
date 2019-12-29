cmake_minimum_required(VERSION 3.5.1)
project(polish_calc_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES src/polish_calc.cpp src/polish_calc_exceptions.cpp)
set(HEADERS include/polish_calc.hpp include/polish_calc_exceptions.hpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(polish_calc_lib ${SOURCES} ${HEADERS})

target_include_directories(polish_calc_lib
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )