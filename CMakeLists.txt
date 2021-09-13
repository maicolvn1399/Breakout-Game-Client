cmake_minimum_required(VERSION 3.20)
project(Breakout_Game_Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
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

add_executable(Breakout_Game_Client Game_GUI/main.cpp SocketClient/SocketClient.cpp SocketClient/SocketClient.h Game_GUI/Ball.cpp Game_GUI/Ball.h Game_GUI/BarPlayer.cpp Game_GUI/BarPlayer.h Game_GUI/Game.cpp Game_GUI/Game.h Game_GUI/ListaSimple.h Game_GUI/Nodo.h Game_GUI/Block.cpp Game_GUI/Block.h Game_GUI/Grid.cpp Game_GUI/Grid.h)

target_link_libraries (Breakout_Game_Client sfml-graphics sfml-window sfml-system)