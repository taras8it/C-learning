cmake_minimum_required(VERSION 3.19)
project(4 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall -Wextra -pedantic")

add_executable(4 main.c)