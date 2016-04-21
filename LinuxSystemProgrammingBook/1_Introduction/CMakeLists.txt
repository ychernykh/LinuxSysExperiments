cmake_minimum_required(VERSION 2.8)

project(1_Introduction)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(Test Test.c)
