#include "MinHeap.h"

void MinHeap::Min() {
    if (heap.empty()) {
        // Handle empty heap case
        std::cout << "MinHeap is empty." << std::endl;
        return;
    }

    std::cout << heap[0].priority << " " << heap[0].data << std::endl;
}

void MinHeap::CreateEmpty() {
    heap.clear();
}

void MinHeap::FixHeap(int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap.size() && heap[leftChild].priority < heap[smallest].priority)
        smallest = leftChild;

    if (rightChild < heap.size() && heap[rightChild].priority < heap[smallest].priority)
        smallest = rightChild;

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        FixHeap(smallest);
    }
}

void MinHeap::Insert(Pair pair) {
    heap.push_back(pair);
    int index = heap.size() - 1;

    while (index > 0 && heap[index].priority < heap[(index - 1) / 2].priority) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

Pair MinHeap::DeleteMin() {
    if (heap.empty()) {
        // Handle empty heap case
        return Pair{ 0, "", 0, 0 };
    }

    Pair minPair = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    FixHeap(0);

    return minPair;
}

int MinHeap::Size() {
    return heap.size();
}

Pair MinHeap::GetMin() {
    if (heap.empty()) {
        // Handle empty heap case
        return Pair{ 0, "", 0, 0 };
    }

    return heap[0];
}

int MinHeap::RemoveByIndex(int index) {
    if (index < 0 || index >= heap.size()) {
        // Handle invalid index case
        return -1;
    }

    heap[index] = heap.back();
    heap.pop_back();
    FixHeap(index);

    return index;
}
