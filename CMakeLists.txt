cmake_minimum_required(VERSION 3.5.1)
project(polish_calc_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES src/polish_calc.cpp src/polish_calc_exceptions.cpp)
set(HEADERS include/polish_calc.hpp include/polish_calc_exceptions.hpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)

add_library(polish_calc_lib ${SOURCES} ${HEADERS})

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(PCL::polish_calc_lib ALIAS polish_calc_lib)

set_target_properties(polish_calc_lib PROPERTIES
        PUBLIC_HEADER include/polish_calc.hpp)

target_include_directories(polish_calc_lib
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )