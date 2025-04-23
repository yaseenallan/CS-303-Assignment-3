#pragma once
#include <iostream>
#include <vector>

// Template Queue using linked list
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* front_ptr;
    Node* rear_ptr;
    size_t count;

public:
    Queue();
    ~Queue();

    void push(const T& val);
    void pop();
    T front() const;
    size_t size() const;
    bool empty() const;
    void move_to_rear();
};

// Recursive function to find last occurrence of a target in a vector
int recursive_last_occurrence(const std::vector<int>& vec, int target, int index);

// Modified insertion sort to sort a Queue<int>
void insertion_sort(Queue<int>& q);
