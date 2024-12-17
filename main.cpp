#include <iostream>

int main() {
    int lastNumber = 1;
    int array[5] = {0, 0, 0, 0, 0};
    int count = 0;
    int maxSum = 0;

    while (true) {
        std::cin >> lastNumber;

        // обновление максимума и вывод
        if (count >= 5) {
            maxSum = maxSum > array[0] + lastNumber ? maxSum : array[0] + lastNumber;
            std::cout << "Max sum: " << maxSum << '\n';
        }

        // обновление массива
        for (int i = 0; i < 4; ++i){
            array[i] = array[i + 1];
        }
        array[4] = lastNumber > array[3] ? lastNumber : array[3];

        ++count;
    }
}
