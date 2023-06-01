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
    std::string data;
    int currIndex;
    int indexInOtherHeap;
}Pair;

#endif
