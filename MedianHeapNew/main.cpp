#include <iostream>
#include <string>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Pair.h"
#include "MedianHeap.h"

/*
6
e
f 3 hi
f 2 why
f 9 bye
f 7 day
g
*/
int main() {
    MedianHeap medianHeap;

    int numOperations;
    int priority;
    std::string value;

    std::cin >> numOperations;

    for (int i = 0; i < numOperations; i++) {
        std::string operation;
        std::cin >> operation;

        if (operation == "e") {
            medianHeap.CreateEmpty();
        }
        else if (operation == "a") {
            medianHeap.Max();
        }
        else if (operation == "b") {
            medianHeap.DeleteMax();
        }
        else if (operation == "c") {
            medianHeap.Min();
        }
        else if (operation == "d") {
            medianHeap.DeleteMin();
        }
        else if (operation == "f") {
            std::cin >> priority;
            std::getline(std::cin >> std::ws, value);

            Pair pair;
            pair.priority = priority;
            pair.data = value;
            pair.currIndex = 0;
            pair.indexInOtherHeap = 0;

            medianHeap.Insert(pair);
        }
        else if (operation == "g") {
            Pair median = medianHeap.Median();
            std::cout << median.priority << std::endl;
        }
        else {
            std::cout << "wrong input." << std::endl;
            return 0;
        }
    }

    return 0;
}
