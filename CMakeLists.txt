cmake_minimum_required(VERSION 3.19)
project(Proyecto2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proyecto2 main.cpp PathfindingA/PathfindingA.cpp PathfindingA/PathfindingA.h PathfindingA/LinkedList.cpp PathfindingA/LinkedList.h PathfindingA/Node.cpp PathfindingA/Node.h)