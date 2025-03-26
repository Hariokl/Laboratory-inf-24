#include <iostream>
#include "myobject/myobject.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Ещё я умею умножать! Зацени 2*2=";
    std::cout << myobject::product(10, 10) << std::endl;

    return 0;
}
