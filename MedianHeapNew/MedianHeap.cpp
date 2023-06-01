#include "MedianHeap.h"


void MedianHeap::Insert(Pair pair) {
    pair.indexInOtherHeap = -1; // Initialize the indexInOtherHeap to -1

    if (pair.priority <= Median().priority) {
        lowMaxHeap.Insert(pair);
        lowMinHeap.Insert(pair);

        if (lowMaxHeap.Size() > highMaxHeap.Size()) {
            Pair removedPair = lowMaxHeap.DeleteMax();
            highMaxHeap.Insert(removedPair);

            removedPair.indexInOtherHeap = lowMinHeap.RemoveByIndex(removedPair.currIndex);
            highMinHeap.Insert(removedPair);
        }
    }
    else {
        highMaxHeap.Insert(pair);
        highMinHeap.Insert(pair);

        if (highMinHeap.Size() > lowMinHeap.Size()) {
            Pair removedPair = highMinHeap.DeleteMin();
            lowMinHeap.Insert(removedPair);

            removedPair.indexInOtherHeap = highMaxHeap.RemoveByIndex(removedPair.currIndex);
            lowMaxHeap.Insert(removedPair);
        }
    }
    std::cout << "Pair inserted: (" << pair.priority << ", " << pair.data << ")" << std::endl;
}

MedianHeap::MedianHeap() {
    // Constructor
}

void MedianHeap::Max() {
    highMaxHeap.Max();
}

void MedianHeap::DeleteMax() {
    highMaxHeap.DeleteMax();
    std::cout << "Maximum pair deleted." << std::endl;
}

void MedianHeap::Min() {
    lowMinHeap.Min();
}

void MedianHeap::DeleteMin() {
    lowMinHeap.DeleteMin();
}

void MedianHeap::CreateEmpty() {
    highMaxHeap.CreateEmpty();
    lowMaxHeap.CreateEmpty();
    highMinHeap.CreateEmpty();
    lowMinHeap.CreateEmpty();
}

Pair MedianHeap::Median() {
    if (lowMaxHeap.Size() > highMaxHeap.Size()) {
        Pair median = lowMaxHeap.GetMax();
        return median;
    }
    else if (highMinHeap.Size() > lowMinHeap.Size()) {
        Pair median = highMinHeap.GetMin();
        return median;
    }
    else {
        // If the sizes are equal, return the maximum from the lowMaxHeap
        Pair median = lowMaxHeap.GetMax();
        return median;
    }
}
