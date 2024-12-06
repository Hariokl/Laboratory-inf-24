#pragma once
#include <iostream>

namespace Solver {
enum class UserChoice {
    staticArray = '1',
    dynamicArray
};
struct Results {
    int countCompare;
    int countSwap;
};

[[nodiscard]] Results BubbleSort(int* array, size_t size, bool inverted);
[[nodiscard]] Results SelectionSort(int* array, size_t size, bool inverted);
void FillArray(int* array, size_t size);

void StaticArrayMethod();
void DynamicArrayMethod();
void ChooseMethod(char userChoice);
void StartUp();
}  // namespace Solver
