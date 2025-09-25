// ring.h - 环形队列模板（C++17 + ARM GCC 10.x）
#pragma once
#include <array>
#include <cstddef>

template<typename T, std::size_t N>
class RingQueue {
    std::array<T, N> buf{};
    std::size_t head = 0, tail = 0;
public:
    bool push(T val) {
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
    std::size_t size() const { return (tail + N - head) % N; }
};