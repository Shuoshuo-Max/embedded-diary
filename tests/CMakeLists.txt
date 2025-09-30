cmake_minimum_required(VERSION 3.14)
project(RingQueueTests)

# 自动下载 GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799fd395
)
FetchContent_MakeAvailable(googletest)

# 包含头文件路径
include_directories(../include)

# 创建测试可执行文件
add_executable(
  RingQueueTests
  RingQueueTest.cpp
)

# 链接 GoogleTest
target_link_libraries(
  RingQueueTests
  GTest::gtest_main
)

# 启用测试发现
include(GoogleTest)
gtest_discover_tests(RingQueueTests)