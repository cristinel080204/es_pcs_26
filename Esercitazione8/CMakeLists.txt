cmake_minimum_required(VERSION 3.20)
project(Esercitazione8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCES test_arco_grafo.cpp unidirected_edge.hpp unidirected_graph.hpp)
add_executable(graph ${SOURCES})