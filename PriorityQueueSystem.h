#ifndef PRIORITY_QUEUE_SYSTEM_H
#define PRIORITY_QUEUE_SYSTEM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "City.h" // Needs to know what a City is

using namespace std;

class PriorityQueueSystem {
private:
    vector<City> heap;

    // Restore heap property moving UP
    void heapifyUp(int index) {
        if (index == 0) return;
        int parentIndex = (index - 1) / 2;

        if (heap[index].priorityScore > heap[parentIndex].priorityScore) {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    // Restore heap property moving DOWN
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild].priorityScore > heap[largest].priorityScore) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].priorityScore > heap[largest].priorityScore) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Enqueue: Add a new area
    void enqueue(City c) {
        heap.push_back(c);
        heapifyUp(heap.size() - 1);
    }

    // Dequeue: Remove Highest Priority
    City dequeue() {
        if (isEmpty()) return City();

        City root = heap[0];
        City lastElement = heap.back();
        heap.pop_back();

        if (!isEmpty()) {
            heap[0] = lastElement;
            heapifyDown(0);
        }
        return root;
    }

    City peek() {
        if (isEmpty()) return City();
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

#endif