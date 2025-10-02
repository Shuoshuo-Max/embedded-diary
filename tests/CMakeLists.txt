cmake_minimum_required(VERSION 3.14)
project(RingQueueTests)

add_executable(RingQueueTests RingQueueTest.cpp)

target_include_directories(RingQueueTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

enable_testing()
add_test(NAME RingQueueTests COMMAND RingQueueTests)