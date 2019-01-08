# cmake_minimum_required(VERSION <specify CMake version here>)
project(chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(chess main.cpp piece.cpp piece.h board.cpp board.h player.cpp player.h exceptions.h human_player.cpp human_player.h chess_model.cpp chess_model.h view.cpp view.h terminal.cpp terminal.h chess_controller.cpp chess_controller.h computer_player.cpp computer_player.h)