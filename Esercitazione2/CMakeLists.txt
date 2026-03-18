cmake_minimum_required(VERSION 3.20)
project(esercitazione2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCES_PROG1 es2_1.cpp)
add_executable(calcoli_array ${SOURCES_PROG1})

set(SOURCES_PROG2 es02.cpp)
add_executable(address ${SOURCES_PROG2})