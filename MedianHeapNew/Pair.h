#pragma once

#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>

using namespace std;

typedef struct pair
{
public:
    int priority;
    const string& value;
    int currIndex;
    int indexInOtherHeap;
}Pair;

#endif
