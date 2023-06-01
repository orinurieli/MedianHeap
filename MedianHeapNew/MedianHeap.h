#pragma once
#ifndef MEDIANHEAP_H
#define MEDIANHEAP_H

#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Pair.h"

class MedianHeap {
private:
    MaxHeap highMaxHeap; // stores half big numbers with pointer to lowMaxHeap
    MaxHeap lowMaxHeap; // stores half small numbers with pointer to highMaxHeap
    MinHeap highMinHeap; // stores half big numbers with pointer to lowMinHeap
    MinHeap lowMinHeap; // stores half small numbers with pointer to highMinHeap

public:
    MedianHeap();
    void Max();
    void DeleteMax();
    void Min();
    void DeleteMin();
    void CreateEmpty();
    void Insert(Pair pair);
    Pair Median();
};

#endif /* MEDIANHEAP_H */
