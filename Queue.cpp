#include "Queue.h"

// Constructor
template <typename T>
Queue<T>::Queue() : front_ptr(nullptr), rear_ptr(nullptr), count(0) {}

// Destructor
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

// Push element to rear
template <typename T>
void Queue<T>::push(const T& val) {
    Node* new_node = new Node(val);
    if (rear_ptr) rear_ptr->next = new_node;
    rear_ptr = new_node;
    if (!front_ptr) front_ptr = new_node;
    ++count;
}

// Pop element from front
template <typename T>
void Queue<T>::pop() {
    if (empty()) return;
    Node* temp = front_ptr;
    front_ptr = front_ptr->next;
    delete temp;
    if (!front_ptr) rear_ptr = nullptr;
    --count;
}

// Return front element
template <typename T>
T Queue<T>::front() const {
    if (empty()) throw std::runtime_error("Queue is empty");
    return front_ptr->data;
}

// Return size
template <typename T>
size_t Queue<T>::size() const {
    return count;
}

// Return if empty
template <typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

// Move front element to rear
template <typename T>
void Queue<T>::move_to_rear() {
    if (size() <= 1) return;
    T temp = front();
    pop();
    push(temp);
}

// Recursive function to find last occurrence of a target
int recursive_last_occurrence(const std::vector<int>& vec, int target, int index) {
    if (index < 0) return -1;
    if (vec[index] == target) return index;
    return recursive_last_occurrence(vec, target, index - 1);
}

// Modified insertion sort to sort a Queue<int> directly
void insertion_sort(Queue<int>& q) {
    std::vector<int> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    for (size_t i = 1; i < temp.size(); ++i) {
        int key = temp[i];
        int j = i - 1;
        while (j >= 0 && temp[j] > key) {
            temp[j + 1] = temp[j];
            --j;
        }
        temp[j + 1] = key;
    }
    for (int val : temp) {
        q.push(val);
    }
}

// Explicit template instantiation for Queue<int>
template class Queue<int>;