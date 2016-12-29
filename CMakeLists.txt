cmake_minimum_required(VERSION 3.6)
project(AnnCursach)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp dynamicArray.h stack.h array_stack.h ListBaseStack.h)
add_executable(AnnCursach ${SOURCE_FILES})