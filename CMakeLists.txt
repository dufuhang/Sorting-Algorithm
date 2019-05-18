cmake_minimum_required(VERSION 3.12)
project(Sorts)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)

add_executable(BubbleSort BubbleSort/main.cc)

add_executable(QucikSort QuickSort/main.cc)

add_executable(SelectionSort SelectionSort/main.cc)

add_executable(InsertionSort InsertionSort/main.cc)

add_executable(BitSort BitSort/main.cc)