#include <cmath>
#include "solver.h"
#include "random"
#include <iostream>
#include <iterator>

namespace Solver{

[[nodiscard]] int* RandomArrayGenerator(size_t size) {
    int* array = new int[size];
    std::random_device r{}; // инициализация std::random_device
    std::default_random_engine randomEngine(r()); // создание random engine с сидом, сгенерированным r
    std::uniform_int_distribution distribution(0, 99); // равномерное распределение от 1 до 12
    for (size_t i = 0; i < size; ++i) {
        array[i] = distribution(randomEngine);
    }
    return array;
}

void BubbleSort(int* array, size_t size) {
    bool earlyStopBool = true;
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
                earlyStopBool = false;
            }
        }
        if (earlyStopBool) {
            break;
        }
    }
}

void SelectionSort(int* array, size_t size) {
    int minI = 0;
    for (size_t i = 0; i < size - 1; ++i) {
        minI = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (array[minI] > array[j]) {
                minI = j;
            }
        }
        std::swap(array[i], array[minI]);
    }
}

void StaticArrayBubbleSort(){
    size_t staticArrayN = 10;

    int* tempArray[staticArrayN];
    int* staticArrayBubble[staticArrayN];
    int* staticArraySelection[staticArrayN];

    tempArray = RandomArrayGenerator(staticArrayN);
    for (size_t i = 0; i < staticArrayN; ++i){
        staticArrayBubble[i] = tempArray[i];
        staticArraySelection[i] = tempArray[i];
    }


    for (size_t i = 0; i < staticArrayN; ++i){
        std::cout << staticArrayBubble[i] << " ";
    }
    BubbleSort(&staticArrayBubble, staticArrayN);
    std::cout << '\n';
    for (size_t i = 0; i < staticArrayN; ++i){
        std::cout << staticArraySelection[i] << " ";
    }
    std::cout << '\n';
    delete[] tempArray;
    delete[] staticArrayBubble;
    delete[] staticArraySelection;

}

void StartUp(){
    StaticArrayBubbleSort();
}

}
