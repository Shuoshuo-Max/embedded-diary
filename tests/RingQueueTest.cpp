#include "gtest/gtest.h"
#include "RingQueue.hpp"

TEST(RingQueue, PopEmpty) {
    RingQueue<int> q(5);
    EXPECT_THROW(q.pop(), std::runtime_error);
}

TEST(RingQueue, PushFull) {
    RingQueue<int> q(2);
    q.push(1);
    q.push(2);
    EXPECT_THROW(q.push(3), std::runtime_error);
}

TEST(RingQueue, BasicOperations) {
    RingQueue<int> q(3);
    q.push(1);
    q.push(2);
    EXPECT_EQ(q.pop(), 1);
    EXPECT_EQ(q.pop(), 2);
}

TEST(RingQueue, WrapAround) {
    RingQueue<int> q(3);
    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);
    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.pop(), 3);
}

TEST(RingQueue, EmptyAfterOps) {
    RingQueue<int> q(3);
    EXPECT_TRUE(q.empty());
    q.push(1);
    EXPECT_FALSE(q.empty());
    q.pop();
    EXPECT_TRUE(q.empty());
}