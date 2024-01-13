cmake_minimum_required(VERSION 3.10)
# project name and language
#project(DesignPatternsApplied LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Threads REQUIRED)

add_subdirectory(observer)
add_subdirectory(command)
add_subdirectory(state)
add_subdirectory(strategy)

