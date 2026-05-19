cmake_minimum_required(VERSION 3.20)
project(Esercitazione9)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(visita_grafo test_algoritmi_grafo.cpp ${SOURCES})