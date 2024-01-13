cmake_minimum_required(VERSION 3.10.0)
project(Threadpool VERSION 0.1.0 LANGUAGES CXX)

#include(CTest)
#enable_testing()

add_executable(Threadpool threadpool.cpp)
target_link_libraries(Threadpool Threads::Threads)
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)