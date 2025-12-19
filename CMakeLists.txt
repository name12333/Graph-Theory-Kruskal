cmake_minimum_required(VERSION 3.10)
project(attack_Kruskal_demo)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(attack_mst
    src/main.cpp
    src/Graph.cpp
    src/UnionFind.cpp
    src/Kruskal.cpp
    src/Exporter.cpp
    src/Logger.cpp
)

