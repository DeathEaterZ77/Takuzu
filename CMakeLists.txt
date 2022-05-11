cmake_minimum_required(VERSION 3.21)
project(Takuzu C)

set(CMAKE_C_STANDARD 99)

add_executable(Takuzu main.c game_player.c game_player.h solutions_grids.c solutions_grids.h interface.c interface.h manual_solving.c manual_solving.h)
