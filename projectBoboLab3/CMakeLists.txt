cmake_minimum_required(VERSION 3.22)
project(projectBoboLab3)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++")
include_directories(Teste)

add_executable(projectBoboLab3
        "Proiect C++/App.cpp"
        "Proiect C++/IteratorMD.cpp"
        "Proiect C++/IteratorMD.h"
        "Proiect C++/MD.cpp"
        "Proiect C++/MD.h"
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h)
