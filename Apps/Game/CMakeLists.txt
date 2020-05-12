cmake_minimum_required(VERSION 3.15)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/Tic Tac Toe" Sources)
add_library(TicTacToe_Lib ${Sources})