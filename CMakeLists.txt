cmake_minimum_required(VERSION 3.20)
project(Breakout_Game_Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Breakout_Game_Client main.cpp SocketClient/SocketClient.cpp SocketClient/SocketClient.h)
