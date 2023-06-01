#pragma once

#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>

using namespace std;

typedef struct pair
{
public:
    int priority = -1;
    std::string data = "";
    int currIndex = -1;
    int indexInOtherHeap = -1;
}Pair;

#endif
