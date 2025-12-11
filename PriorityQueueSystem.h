#ifndef PRIORITY_QUEUE_SYSTEM_H
#define PRIORITY_QUEUE_SYSTEM_H

#include <iostream>
#include <algorithm> // For swap
#include "City.h" 

using namespace std;

class PriorityQueueSystem {
private:
    // REPLACED VECTOR WITH RAW ARRAY
    City heapArray[100]; // Safe capacity for our 25-city map
    int currentSize;     // Tracks how many items are currently in the heap

    // Restore heap property moving UP
    void heapifyUp(int index) {
        if (index == 0) return;
        int parentIndex = (index - 1) / 2;

        if (heapArray[index].priorityScore > heapArray[parentIndex].priorityScore) {
            swap(heapArray[index], heapArray[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    // Restore heap property moving DOWN
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        // Check Left Child
        if (leftChild < currentSize && heapArray[leftChild].priorityScore > heapArray[largest].priorityScore) {
            largest = leftChild;
        }

        // Check Right Child
        if (rightChild < currentSize && heapArray[rightChild].priorityScore > heapArray[largest].priorityScore) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heapArray[index], heapArray[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Constructor to initialize size
    PriorityQueueSystem() {
        currentSize = 0;
    }

    // Enqueue: Add a new area
    void enqueue(City c) {
        if (currentSize >= 100) {
            cout << "[Error] Priority Queue Overflow!" << endl;
            return;
        }

        // Insert at the end of the array
        heapArray[currentSize] = c;
        heapifyUp(currentSize);
        currentSize++; // Increase count
    }

    // Dequeue: Remove Highest Priority
    City dequeue() {
        if (isEmpty()) return City();

        City root = heapArray[0];

        // Move the last element to the root
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--; // Decrease count

        if (!isEmpty()) {
            heapifyDown(0);
        }
        return root;
    }

    City peek() {
        if (isEmpty()) return City();
        return heapArray[0];
    }

    bool isEmpty() {
        return currentSize == 0;
    }
};

#endif