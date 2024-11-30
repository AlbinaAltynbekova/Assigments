#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.peek() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    std::cout << "Queue size after dequeue: " << queue.size() << std::endl;

    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}

