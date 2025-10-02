#include <iostream>
#include <stdexcept>
#include <string>

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

bool testPopEmpty() {
    std::cout << "[ RUN      ] PopEmpty" << std::endl;
    RingQueue<int, 5> q;
    try {
        q.pop();
        std::cout << "[  FAILED  ] PopEmpty - Expected exception but none thrown" << std::endl;
        return false;
    } catch (const std::runtime_error&) {
        std::cout << "[       OK ] PopEmpty" << std::endl;
        return true;
    }
}

bool testPushFull() {
    std::cout << "[ RUN      ] PushFull" << std::endl;
    RingQueue<int, 2> q;
    q.push(1);
    q.push(2);
    try {
        q.push(3);
        std::cout << "[  FAILED  ] PushFull - Expected exception but none thrown" << std::endl;
        return false;
    } catch (const std::runtime_error&) {
        std::cout << "[       OK ] PushFull" << std::endl;
        return true;
    }
}

bool testBasicOperations() {
    std::cout << "[ RUN      ] BasicOperations" << std::endl;
    RingQueue<int, 3> q;
    q.push(1);
    q.push(2);
    if (q.pop() == 1 && q.pop() == 2) {
        std::cout << "[       OK ] BasicOperations" << std::endl;
        return true;
    } else {
        std::cout << "[  FAILED  ] BasicOperations - Wrong pop values" << std::endl;
        return false;
    }
}

bool testWrapAround() {
    std::cout << "[ RUN      ] WrapAround" << std::endl;
    RingQueue<int, 3> q;
    q.push(1);
    q.push(2);
    q.pop();    q.push(3);
    if (q.pop() == 2 && q.pop() == 3) {
        std::cout << "[       OK ] WrapAround" << std::endl;
        return true;
    } else {
        std::cout << "[  FAILED  ] WrapAround - Wrap around failed" << std::endl;
        return false;
    }
}

bool testEmptyAfterOps() {
    std::cout << "[ RUN      ] EmptyAfterOps" << std::endl;
    RingQueue<int, 3> q;
    if (!q.empty()) {
        std::cout << "[  FAILED  ] EmptyAfterOps - Initially not empty" << std::endl;
        return false;
    }
    q.push(1);
    if (q.empty()) {
        std::cout << "[  FAILED  ] EmptyAfterOps - After push still empty" << std::endl;
        return false;
    }
    q.pop();
    if (!q.empty()) {
        std::cout << "[  FAILED  ] EmptyAfterOps - After pop not empty" << std::endl;
        return false;
    }
    std::cout << "[       OK ] EmptyAfterOps" << std::endl;
    return true;
}

int main() {
    std::cout << "[==========] Running 5 tests from RingQueue" << std::endl;
    
    int passed = 0;
    int total = 5;
    
    if (testPopEmpty()) passed++;
    if (testPushFull()) passed++;
    if (testBasicOperations()) passed++;
    if (testWrapAround()) passed++;
    if (testEmptyAfterOps()) passed++;
    
    std::cout << "[==========] " << total << " tests ran." << std::endl;
    std::cout << "[  PASSED  ] " << passed << " tests." << std::endl;
    if (passed < total) {
        std::cout << "[  FAILED  ] " << (total - passed) << " tests." << std::endl;
    }
    
    return (passed == total) ? 0 : 1;
}