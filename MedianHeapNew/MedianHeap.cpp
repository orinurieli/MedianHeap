#include "MedianHeap.h"

void MedianHeap::Insert(Pair pair) {
    pair.indexInOtherHeap = -1; // Initialize the indexInOtherHeap to -1

    //std::cout << "median priority: " << Median().priority << endl;
    if (lowMaxHeap.Size() == 0) {
        // If lowMaxHeap is empty, insert the pair into both lowMaxHeap and lowMinHeap
        lowMaxHeap.Insert(pair);
        lowMinHeap.Insert(pair);

        pair.indexInOtherHeap = lowMinHeap.Size() - 1;
        //std::cout << "Pair inserted into lowMaxHeap and lowMinHeap." << endl;
    }
    else if (pair.priority > Median().priority) {
        // If the pair's priority is greater than the median, insert it into highMaxHeap and highMinHeap
        highMaxHeap.Insert(pair);
        highMinHeap.Insert(pair);

        pair.indexInOtherHeap = highMinHeap.Size() - 1;
        //std::cout << "Pair inserted into highMaxHeap and highMinHeap." << endl;

        if (highMinHeap.Size() > lowMinHeap.Size()) {
            // If highMinHeap size is greater than lowMinHeap size, move the minimum from highMinHeap to lowMinHeap
            Pair removedPair = highMinHeap.DeleteMin();
            lowMinHeap.Insert(removedPair);

            removedPair.indexInOtherHeap = highMaxHeap.RemoveByIndex(removedPair.indexInOtherHeap);
            lowMaxHeap.Insert(removedPair);
            std::cout << "Pair moved from highMinHeap to lowMinHeap." << endl;
        }
    }
    else {
        // If the pair's priority is less than or equal to the median, insert it into lowMaxHeap and lowMinHeap
        lowMaxHeap.Insert(pair);
        lowMinHeap.Insert(pair);

        pair.indexInOtherHeap = lowMinHeap.Size() - 1;
        //std::cout << "Pair inserted into lowMaxHeap and lowMinHeap." << endl;

        if (lowMaxHeap.Size() > highMaxHeap.Size() + 1) {
            Pair removedPair = lowMaxHeap.DeleteMax();
            highMaxHeap.Insert(removedPair);

            removedPair.indexInOtherHeap = lowMinHeap.RemoveByIndex(removedPair.indexInOtherHeap);
            highMinHeap.Insert(removedPair);
            //std::cout << "Pair moved from lowMaxHeap to highMaxHeap." << endl;
        }
    }

    //std::cout << "Pair inserted: (" << pair.priority << ", " << pair.data << ")" << std::endl;
}

//void MedianHeap::Insert(Pair pair) {
//    pair.indexInOtherHeap = -1; // Initialize the indexInOtherHeap to -1
//
//    cout << "median priority: " << Median().priority << endl;
//    if (pair.priority <= Median().priority) {
//        lowMaxHeap.Insert(pair);
//        lowMinHeap.Insert(pair);
//
//        if (lowMaxHeap.Size() > highMaxHeap.Size()) {
//            Pair removedPair = lowMaxHeap.DeleteMax();
//            highMaxHeap.Insert(removedPair);
//
//            removedPair.indexInOtherHeap = lowMinHeap.RemoveByIndex(removedPair.currIndex);
//            highMinHeap.Insert(removedPair);
//        }
//    }
//    else {
//        highMaxHeap.Insert(pair);
//        highMinHeap.Insert(pair);
//
//        if (highMinHeap.Size() > lowMinHeap.Size()) {
//            Pair removedPair = highMinHeap.DeleteMin();
//            lowMinHeap.Insert(removedPair);
//
//            removedPair.indexInOtherHeap = highMaxHeap.RemoveByIndex(removedPair.currIndex);
//            lowMaxHeap.Insert(removedPair);
//        }
//    }
//    std::cout << "Pair inserted: (" << pair.priority << ", " << pair.data << ")" << std::endl;
//}

MedianHeap::MedianHeap() {
    // Constructor
}

void MedianHeap::Max() {
    highMaxHeap.Max();
}

void MedianHeap::DeleteMax() {
    Pair item = highMaxHeap.DeleteMax();
    if(item.priority != -1)
        cout << item.priority << " " << item.data << endl;
}

void MedianHeap::Min() {
    lowMinHeap.Min();
}

void MedianHeap::DeleteMin() {
    Pair item = lowMinHeap.DeleteMin();
    if (item.priority != -1)
        cout << item.priority << " " << item.data << endl;
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
