cmake_minimum_required(VERSION 3.15)
project(LinkedList)

set(CMAKE_CXX_STANDARD 17)

set(HEADER LinkedList.hpp Iterator.hpp Node.hpp)

add_executable(LinkedList main.cpp ${HEADER})