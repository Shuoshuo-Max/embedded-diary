// ring.h - 环形队列实现（C++17 + ARM GCC 10.x）

#pragma once

#include <array>
#include <cstddef>

template <typename T, std::size_t N>
class RingQueue {
    std::array<T, N> buf{};
    std::size_t head = 0, tail = 0;

public:
    // 修复：使用 const 引用传递参数
    bool push(const T& val) {
        if ((tail + 1) % N == head) return false;
        buf[tail] = val;
        tail = (tail + 1) % N;
        return true;
    }

    bool pop(T& val) {
        if (head == tail) return false;
        val = buf[head];
        head = (head + 1) % N;
        return true;
    }

    // 添加 [[nodiscard]] 属性
    [[nodiscard]] std::size_t size() const { 
        return (tail + N - head) % N; 
    }

    // 添加显式的空检查方法
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % N == head; }
};