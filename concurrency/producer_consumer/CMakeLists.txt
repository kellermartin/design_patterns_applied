cmake_minimum_required(VERSION 3.10.0)
project(ProducerConsumer VERSION 0.1.0 LANGUAGES CXX)

#include(CTest)
#enable_testing()

add_executable(ProducerConsumer producer-consumer.cpp)
target_link_libraries(ProducerConsumer Threads::Threads)
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)