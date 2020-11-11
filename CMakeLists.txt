cmake_minimum_required(VERSION 3.17)
project(oop_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_lab main.cpp test_runner.h
        journaldata.h journaldata.cpp
        journal.h journal.cpp
        SimpleVector.h)