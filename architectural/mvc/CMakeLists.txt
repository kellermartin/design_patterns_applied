cmake_minimum_required(VERSION 3.10.0)
project(ModelViewController VERSION 0.1.0 LANGUAGES CXX)

#include(CTest)
#enable_testing()

add_executable(ModelViewController model-view-controller.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)