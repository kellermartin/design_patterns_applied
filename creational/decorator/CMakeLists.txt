cmake_minimum_required(VERSION 3.10.0)
project(Decorator VERSION 0.1.0 LANGUAGES CXX)

#include(CTest)
#enable_testing()

add_executable(Decorator decorator.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)