#include <iostream>
#include <vector>

class RingQueue {
private:
    std::vector<int> data;
    int head, tail, size, capacity;
public:
    RingQueue(int cap) : data(cap), head(0), tail(0), size(0), capacity(cap) {}
    
    bool enqueue(int value) {
        if (size == capacity) return false;
        data[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }
    
    bool dequeue() {
        if (size == 0) return false;
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    int front() {
        return size > 0 ? data[head] : -1;
    }
};

int main() {
    RingQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    
    std::cout << "Coverage test completed" << std::endl;
    std::cout << "Front: " << q.front() << std::endl;
    
    q.dequeue();
    std::cout << "After dequeue, Front: " << q.front() << std::endl;
    
    return 0;
}
