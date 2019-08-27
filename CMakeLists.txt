cmake_minimum_required(VERSION 3.10)

project(c-notes)

# enforce C++11 and disable extensions
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# enforce C99 and disable extensions
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(braced_init
    braced_init.cpp)

add_executable(designated_init
    designated_init.c)

add_executable(func_pointers
    func_pointers.c)

add_executable(standard
    standard.cpp)

add_executable(struct_vs_class
    struct_vs_class.cpp)

add_executable(variadic
    variadic.c)
