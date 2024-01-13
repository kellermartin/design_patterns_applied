cmake_minimum_required(VERSION 3.10)
message("Configuring Design Patterns Applied project")
# project name and language
project(DesignPatternsApplied LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_subdirectory(behavioral)
add_subdirectory(creational)
add_subdirectory(structural)
add_subdirectory(architectural)
add_subdirectory(concurrency)