cmake_minimum_required(VERSION 3.22)
project(projectBobo_Lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projectBobo_Lab4
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h)
