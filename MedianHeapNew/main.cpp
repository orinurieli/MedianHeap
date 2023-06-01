#include <iostream>
#include <string>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Pair.h"
#include "MedianHeap.h"


int main() {
    MedianHeap medianHeap;

    int numOperations;
    int priority;
    std::string value;

    std::cin >> numOperations;

    for (int i = 0; i < numOperations; i++) {
        std::string operation;
        std::cin >> operation;

        // todo: handle case e after e
        if (operation == "e")
            medianHeap.CreateEmpty();
        else if (operation == "a")
        {
            medianHeap.Max();
        }
        else if (operation == "b")
        {
            medianHeap.DeleteMax();
        }
        else if (operation == "c")
        {
            medianHeap.Min();
        }
        else if (operation == "d")
        {
            medianHeap.DeleteMin();
        }
        else if (operation == "f") {
            std::cin >> priority;
            std::getline(std::cin >> std::ws, value);

            medianHeap.Insert(value, priority);
        }
        else if (operation == "g") {
            Pair* median = medianHeap.Median();
            cout << median->priority;
        }
        else {
            std::cout << "Invalid operation." << std::endl;
            return 0;
        }
    }

    return 0;
}
