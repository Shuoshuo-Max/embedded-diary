cmake_minimum_required(VERSION 3.14)
project(RingQueue)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 如果有源文件，添加可执行文件
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src")
    add_executable(RingQueueMain src/main.cpp)  # 根据实际情况调整
endif()

# 启用测试并包含 tests 目录
enable_testing()
add_subdirectory(tests)