cmake_minimum_required(VERSION 3.24)
project(SchoolSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(SchoolSystem main.cpp LoginMenu.cpp LoginMenu.h TeacherMenu.cpp TeacherMenu.h StudentMenu.cpp StudentMenu.h Person.cpp Person.h Student.cpp Student.h Teacher.cpp Teacher.h)
