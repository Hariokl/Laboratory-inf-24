#include "solver.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>

#include "random"

namespace {
void PrintArray(int* array, size_t size) {
    std::cout << "[ ";
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << ']';
}

void PrintResults(Solver::Results results) {
    std::cout << " || количество перестановок:" << results.countSwap << " || количество сравнений:" << results.countCompare;
}

void Menu() {
    std::cout << "\nВыберите работу с массивом:";
    std::cout << "\n\t1. Статическим";
    std::cout << "\n\t2. Динамический\n";
}

void ContinueProgram() {
    std::cout << "\nПродолжить программу? (y/n)";
}
}  // namespace

namespace Solver {

void FillArray(int* array, size_t size) {
    const int kMinDistributionIRange = 0;
    const int kMaxDistributionIRange = 99;
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution distribution(kMinDistributionIRange, kMaxDistributionIRange);
    for (size_t i = 0; i < size; ++i) {
        array[i] = distribution(randomEngine);
    }
}

[[nodiscard]] Results BubbleSort(int* array, size_t size, bool inverted) {
    bool earlyStopBool = true;
    int countSwap = 0;
    int countCompare = 0;
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if ((array[i] > array[j]) && !inverted) {
                std::swap(array[i], array[j]);
                earlyStopBool = false;
                ++countSwap;
            } else if ((array[i] < array[j]) && inverted) {
                std::swap(array[i], array[j]);
                earlyStopBool = false;
                ++countSwap;
            }
            ++countCompare;
        }
        if (earlyStopBool) {
            break;
        }
    }
    return Results{countCompare, countSwap};
}

[[nodiscard]] Results SelectionSort(int* array, size_t size, bool inverted) {
    size_t minI = 0;
    int countSwap = 0;
    int countCompare = 0;
    for (size_t i = 0; i < size - 1; ++i) {
        minI = i;
        for (size_t j = i + 1; j < size; ++j) {
            if ((array[minI] > array[j]) && !inverted) {
                minI = j;
            } else if ((array[minI] < array[j]) && inverted) {
                minI = j;
            }
            ++countCompare;
        }
        std::swap(array[i], array[minI]);
        ++countSwap;
    }
    return Results{countCompare, countSwap};
}

void StaticArrayMethod() {
    const size_t kStaticArrayN = 10;
    Results resultsOfSort{};
    int* tempArray = new int[kStaticArrayN];
    int* staticArrayBubble = new int[kStaticArrayN];
    int* staticArraySelection = new int[kStaticArrayN];

    FillArray(tempArray, kStaticArrayN);
    for (size_t i = 0; i < kStaticArrayN; ++i) {
        staticArrayBubble[i] = tempArray[i];
        staticArraySelection[i] = tempArray[i];
    }

    std::cout << "\n---------------МЕТОД ПУЗЫРЬКА---------------";
    std::cout << "\nисходный массив:                                                  ";
    PrintArray(staticArrayBubble, kStaticArrayN);
    resultsOfSort = BubbleSort(staticArrayBubble, kStaticArrayN, false);
    std::cout << "\nсортировка массива методом пузырька по возрастанию:               ";
    PrintArray(staticArrayBubble, kStaticArrayN);
    PrintResults(resultsOfSort);
    resultsOfSort = BubbleSort(staticArrayBubble, kStaticArrayN, false);
    std::cout << "\nсортировка получившегося массива методом пузырька по возрастанию: ";
    PrintArray(staticArrayBubble, kStaticArrayN);
    PrintResults(resultsOfSort);
    resultsOfSort = BubbleSort(staticArrayBubble, kStaticArrayN, true);
    std::cout << "\nсортировка получившегося массива методом пузырька по убыванию:    ";
    PrintArray(staticArrayBubble, kStaticArrayN);
    PrintResults(resultsOfSort);

    std::cout << "\n\n---------------МЕТОД ВЫБОРКИ---------------";
    std::cout << "\nисходный массив:                                                ";
    PrintArray(staticArraySelection, kStaticArrayN);
    resultsOfSort = SelectionSort(staticArraySelection, kStaticArrayN, false);
    std::cout << "\nсортировка массива методом выбора по возрастанию:               ";
    PrintArray(staticArraySelection, kStaticArrayN);
    PrintResults(resultsOfSort);
    resultsOfSort = SelectionSort(staticArraySelection, kStaticArrayN, false);
    std::cout << "\nсортировка получившегося массива методом выбора по возрастанию: ";
    PrintArray(staticArraySelection, kStaticArrayN);
    PrintResults(resultsOfSort);
    resultsOfSort = SelectionSort(staticArraySelection, kStaticArrayN, true);
    std::cout << "\nсортировка получившегося массива методом выбора по убыванию:    ";
    PrintArray(staticArraySelection, kStaticArrayN);
    PrintResults(resultsOfSort);

    delete[] tempArray;
    delete[] staticArrayBubble;
    delete[] staticArraySelection;
}

void DynamicArrayMethod() {
    size_t dynamicArrayN = 0;
    Results resultsOfSort{};
    int* tempArray;
    int* dynamicArrayBubble;
    int* dynamicArraySelection;

    std::cout << "Введите длину динамического массива: ";
    std::cin >> dynamicArrayN;

    tempArray = new int[dynamicArrayN];
    dynamicArrayBubble = new int[dynamicArrayN];
    dynamicArraySelection = new int[dynamicArrayN];


    FillArray(tempArray, dynamicArrayN);
    for (size_t i = 0; i < dynamicArrayN; ++i) {
        dynamicArrayBubble[i] = tempArray[i];
        dynamicArraySelection[i] = tempArray[i];
    }

    std::cout << "\n---------------МЕТОД ПУЗЫРЬКА---------------";
    std::cout << "\nисходный массив:                                        ";
    PrintArray(dynamicArrayBubble, dynamicArrayN);
    resultsOfSort = BubbleSort(dynamicArrayBubble, dynamicArrayN, false);
    std::cout << "\nсортировка массива методом пузырька по возрастанию:     ";
    PrintArray(dynamicArrayBubble, dynamicArrayN);
    PrintResults(resultsOfSort);

    std::cout << "\n\n---------------МЕТОД ВЫБОРКИ---------------";
    std::cout << "\nисходный массив:                                        ";
    PrintArray(dynamicArraySelection, dynamicArrayN);
    resultsOfSort = SelectionSort(dynamicArraySelection, dynamicArrayN, false);
    std::cout << "\nсортированный массив сортировкой выбора по возрастанию: ";
    PrintArray(dynamicArraySelection, dynamicArrayN);
    PrintResults(resultsOfSort);

    delete[] tempArray;
    delete[] dynamicArrayBubble;
    delete[] dynamicArraySelection;
}

void ChooseMethod(char userChoice) {
    switch (static_cast<UserChoice>(userChoice)) {
        case UserChoice::staticArray:
            StaticArrayMethod();
            break;
        case UserChoice::dynamicArray:
            DynamicArrayMethod();
            break;
    }
}

void StartUp() {
    char choiceToContinue = 'y';
    char userChoice = '1';
    while (choiceToContinue == 'y') {
        Menu();
        std::cin >> userChoice;
        ChooseMethod(userChoice);
        ContinueProgram();
        std::cin >> choiceToContinue;
    }
}

}  // namespace Solver
