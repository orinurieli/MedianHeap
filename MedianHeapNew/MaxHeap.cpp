#include "MaxHeap.h"

void MaxHeap::Max() {
    if (heap.empty()) {
        // Handle empty heap case
        return;
    }

    std::cout << heap[0].priority<< " " << heap[0].data << std::endl;
}

void MaxHeap::CreateEmpty() {
    heap.clear();
}

void MaxHeap::FixHeap(int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap.size() && heap[leftChild].priority > heap[largest].priority)
        largest = leftChild;

    if (rightChild < heap.size() && heap[rightChild].priority > heap[largest].priority)
        largest = rightChild;

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        FixHeap(largest);
    }
}

void MaxHeap::Insert(Pair pair) {
    heap.push_back(pair);
    int index = heap.size() - 1;

    while (index > 0 && heap[index].priority > heap[(index - 1) / 2].priority) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

Pair MaxHeap::DeleteMax() {
    if (heap.empty()) {
        // Handle empty heap case
        Pair item;
        return item;
    }

    Pair maxPair = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    FixHeap(0);

    return maxPair;
}

int MaxHeap::Size() {
    return heap.size();
}

Pair MaxHeap::GetMax() {
    return heap[0];
}

int MaxHeap::RemoveByIndex(int index) {
    if (index < 0 || index >= heap.size()) {
        // Handle invalid index case
        return -1;
    }

    heap[index] = heap.back();
    heap.pop_back();
    FixHeap(index);

    return index;
}
