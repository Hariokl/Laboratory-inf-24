#include <iostream>
#include "myobject.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Ещё я умею умножать! Зацени 2*2=";
    std::cout << myobject::product(10, 32) << std::endl;

    return 0;
}
