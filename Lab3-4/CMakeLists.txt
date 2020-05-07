cmake_minimum_required(VERSION 3.13)
project(Lab3_4 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab3_4 main.c domain.c domain.h controller.c controller.h ui.c ui.h repository.c repository.h dynamic_array.c dynamic_array.h OperationStack.c OperationStack.h)