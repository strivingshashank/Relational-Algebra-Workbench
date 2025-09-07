cmake_minimum_required(VERSION 3.10)

project(DBMS_PBL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DBMS_PBL main.cpp)

find_package(ftxui REQUIRED COMPONENTS screen dom component)

target_link_libraries(DBMS_PBL PRIVATE ftxui::screen ftxui::dom ftxui::component)
