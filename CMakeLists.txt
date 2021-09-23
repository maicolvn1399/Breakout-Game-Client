cmake_minimum_required(VERSION 3.20)
project(Breakout_Game_Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")
set(jsoncpp_lib_dir ${CMAKE_BINARY_DIR}/jsoncpp-build/src/lib_json)
set(jsoncpp_src_dir ${CMAKE_BINARY_DIR}/jsoncpp-src/include)


link_directories(jsoncpp_lib_dir)
include_directories(jsoncpp_include_dir)
link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
find_package(jsoncpp)

if (jsoncpp_found)
    message(STATUS "jsoncpp_include_dir:${jsoncpp_include_dir}")
    message(STATUS "jsoncpp_libraries:${jsoncpp_libraries}")
    message(STATUS "jsoncpp_version:${jsoncpp_version}")
endif ()

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Breakout_Game_Client BreakoutGameGUI/main.cpp SocketClient/SocketClient.cpp SocketClient/SocketClient.h BreakoutGameGUI/GameBreakout.cpp BreakoutGameGUI/GameBreakout.h BreakoutGameGUI/GameBar.cpp BreakoutGameGUI/GameBar.h BreakoutGameGUI/GameBall.cpp BreakoutGameGUI/GameBall.h BreakoutGameGUI/GameBlock.cpp BreakoutGameGUI/GameBlock.h)
target_link_libraries (Breakout_Game_Client sfml-graphics sfml-window sfml-system sfml-network jsoncpp)
