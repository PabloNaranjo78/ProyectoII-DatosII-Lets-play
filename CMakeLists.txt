cmake_minimum_required(VERSION 3.19)
project(Proyecto2)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

include_directories(AlgoritmoG Graphics BT BT/BTListRegister)

add_executable(Proyecto2 main.cpp PathfindingA/PathfindingA.cpp PathfindingA/PathfindingA.h PathfindingA/LinkedList.cpp PathfindingA/LinkedList.h PathfindingA/Node.cpp PathfindingA/Node.h Physics/Movement.cpp Physics/Movement.h GameManagment/Scores.cpp GameManagment/Scores.h GameManagment/Board.cpp GameManagment/Board.h GameManagment/Ball.cpp GameManagment/Ball.h Graphics/BoardDisplay.cpp Graphics/BoardDisplay.h BT/BackTrackingSearch.cpp BT/BackTrackingSearch.h BT/BTListRegister/BTLinkedList.cpp BT/BTListRegister/LLNode.h BT/BTListRegister/LLNode.h BT/BTListRegister/LLNode.cpp)
add_executable(Server Server/Server.cpp)
target_link_libraries (Proyecto2 sfml-graphics sfml-window sfml-system sfml-network)
target_link_libraries (Server sfml-graphics sfml-window sfml-system sfml-network)