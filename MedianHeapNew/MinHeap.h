#pragma once
#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include "Pair.h"

class MinHeap {
private:
    std::vector<Pair> heap;

public:
    void Min();
    void CreateEmpty();
    void FixHeap(int index);
    void Insert(Pair pair);
    Pair DeleteMin();
    int Size();
    Pair GetMin();
    int RemoveByIndex(int index);
};

#endif /* MINHEAP_H */
