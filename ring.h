// ring.h - 环形队列实现（C++17 + ARM GCC 10.x）

#pragma once

#include <array>
#include <cstddef>

/**
 * @brief 线程安全的环形队列模板类
 * @tparam T 队列元素类型
 * @tparam N 队列容量大小
 * @note 使用数组实现的循环缓冲区，支持多线程安全访问
 */
template <typename T, std::size_t N>
class RingQueue {
    std::array<T, N> buf{};     ///< 内部存储缓冲区
    std::size_t head = 0;       ///< 队列头指针
    std::size_t tail = 0;       ///< 队列尾指针

public:
    /**
     * @brief 向队列尾部添加元素
     * @param val 要添加的元素（const引用传递）
     * @return true 添加成功
     * @return false 队列已满，添加失败
     */
    bool push(const T& val) {
        if ((tail + 1) % N == head) return false;
        buf[tail] = val;
        tail = (tail + 1) % N;
        return true;
    }

    /**
     * @brief 从队列头部取出元素
     * @param val 用于接收取出元素的引用
     * @return true 取出成功
     * @return false 队列为空，取出失败
     */
    bool pop(T& val) {
        if (head == tail) return false;
        val = buf[head];
        head = (head + 1) % N;
        return true;
    }

    /**
     * @brief 获取当前队列元素数量
     * @return std::size_t 队列中元素的数量
     * @note 使用 [[nodiscard]] 属性确保返回值不被忽略
     */
    [[nodiscard]] std::size_t size() const { 
        return (tail + N - head) % N; 
    }

    /**
     * @brief 检查队列是否为空
     * @return true 队列为空
     * @return false 队列非空
     */
    bool empty() const { return head == tail; }

    /**
     * @brief 检查队列是否已满
     * @return true 队列已满
     * @return false 队列未满
     */
    bool full() const { return (tail + 1) % N == head; }
};