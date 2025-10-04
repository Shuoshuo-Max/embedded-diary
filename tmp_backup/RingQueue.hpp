#pragma once
#include <stdexcept>

template<typename T, size_t Capacity>
class RingQueue {
private:
    T data[Capacity];
    size_t head = 0;
    size_t tail = 0;
    size_t count = 0;

public:
    void push(T value) {
        if (count >= Capacity) throw std::runtime_error("Full");
        data[tail] = value;
        tail = (tail + 1) % Capacity;
        count++;
    }

    T pop() {
        if (count == 0) throw std::runtime_error("Empty");
        T value = data[head];
        head = (head + 1) % Capacity;
        count--;
        return value;
    }

    bool empty() const { return count == 0; }
    size_t size() const { return count; }
};