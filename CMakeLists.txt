cmake_minimum_required(VERSION 3.30)
project(bench)

set(NO_OPT "True")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 99)

add_executable(bench_c main.c)
add_executable(bench_cpp main.cpp entity_extern.cpp)

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" AND WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker /STACK:10000000")
else()
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")
endif()

if (NO_OPT)
if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /O2")
else()
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O2")
endif()
endif()