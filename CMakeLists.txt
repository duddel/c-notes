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

add_executable(std_array
    std_array.cpp)

add_executable(braced_init
    braced_init.cpp)

add_executable(copy_move
    copy_move.cpp)

add_executable(designated_init
    designated_init.c)

add_executable(func_pointers
    func_pointers.c)

add_executable(nullptr
    nullptr.cpp)

add_executable(pimpl
    pimpl.cpp)

add_executable(standard
    standard.cpp)

add_executable(struct_vs_class
    struct_vs_class.cpp)

add_executable(template
    template_impl.cpp
    template_main.cpp)

add_executable(threading
    threading.cpp)
# gcc implements std::thread via pthread
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)
    target_link_libraries(threading PRIVATE Threads::Threads)
endif()

add_executable(std_valarray
    std_valarray.cpp)

add_executable(typeid
    typeid.cpp)

add_executable(variadic
    variadic.c)
