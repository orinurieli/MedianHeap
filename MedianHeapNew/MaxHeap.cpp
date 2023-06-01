#include "MaxHeap.h"

void MaxHeap::Max() {
    if (heap.empty()) {
        // Handle empty heap case
        std::cout << "MaxHeap is empty." << std::endl;
        return;
    }

    std::cout << "Max: " << heap[0].priority << std::endl;
}

void MaxHeap::CreateEmpty() {
    heap.clear();
    std::cout << "MaxHeap created empty." << std::endl;
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
    std::cout << "Heap fixed at index: " << index << std::endl;
}

void MaxHeap::Insert(Pair pair) {
    heap.push_back(pair);
    int index = heap.size() - 1;

    while (index > 0 && heap[index].priority > heap[(index - 1) / 2].priority) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    std::cout << "Pair inserted: (" << pair.priority << ", " << pair.data << ")" << std::endl;
}

Pair MaxHeap::DeleteMax() {
    if (heap.empty()) {
        // Handle empty heap case
        std::cout << "MaxHeap is empty." << std::endl;
        return Pair{ 0, "", 0, 0 };
    }

    Pair maxPair = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    FixHeap(0);

    std::cout << "Max pair deleted." << std::endl;
    return maxPair;
}

int MaxHeap::Size() {
    return heap.size();
}

Pair MaxHeap::GetMax() {
    if (heap.empty()) {
        // Handle empty heap case
        std::cout << "MaxHeap is empty." << std::endl;
        return Pair{ 0, "", 0, 0 };
    }

    return heap[0];
}

int MaxHeap::RemoveByIndex(int index) {
    if (index < 0 || index >= heap.size()) {
        // Handle invalid index case
        std::cout << "Invalid index." << std::endl;
        return -1;
    }

    heap[index] = heap.back();
    heap.pop_back();
    FixHeap(index);

    std::cout << "Pair removed at index: " << index << std::endl;
    return index;
}
