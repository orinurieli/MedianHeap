#pragma once
#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include "Pair.h"

class MaxHeap {
private:
    std::vector<Pair> heap;

public:
    void Max();
    void CreateEmpty();
    void FixHeap(int index);
    void Insert(Pair pair);
    Pair DeleteMax();
    int Size();
    Pair GetMax();
    int RemoveByIndex(int index);
};

#endif /* MAXHEAP_H */
