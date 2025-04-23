// Yaseen Allan
// CS-303 Assignment 3
// 04/15/2025
//This program implements a template based queue using a linked list, supports basic queue operations, a move_to_rear function, recursive search for the last occurrence in a vector, and insertion sort for integers.


#include "Queue.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Queue<int> q;

    // Push 10 integers into the queue
    for (int i = 10; i >= 1; --i) {
        q.push(i);
    }

    // Display all elements using only queue functions
    cout << "Original queue contents: ";
    size_t original_size = q.size();
    for (size_t i = 0; i < original_size; ++i) {
        int val = q.front();
        cout << val << " ";
        q.pop();
        q.push(val); // maintain original order
    }
    cout << endl;

    // Move front to rear
    q.move_to_rear();

    cout << "After move_to_rear: ";
    for (size_t i = 0; i < original_size; ++i) {
        int val = q.front();
        cout << val << " ";
        q.pop();
        q.push(val);
    }
    cout << endl;

    // Recursive last occurrence
    vector<int> data = {5, 3, 7, 3, 2, 3, 9};
    int target = 3;
    int last_index = recursive_last_occurrence(data, target, data.size() - 1);
    cout << "Last occurrence of " << target << " in vector 5, 3, 7, 3, 2, 3, 9: index " << last_index << endl;

    // Sort the queue using insertion sort
    insertion_sort(q);

    cout << "Sorted queue contents: ";
    for (size_t i = 0; i < original_size; ++i) {
        int val = q.front();
        cout << val << " ";
        q.pop();
        q.push(val);
    }
    cout << endl;

    return 0;
}