#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return count == 0;
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow");
        }
        Node* temp = head;
        T value = head->value;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        count--;
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return head->value;
    }

    size_t size() const {
        return count;
    }
};

#endif
