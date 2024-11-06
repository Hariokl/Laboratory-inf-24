#include <iostream>
#include <coroutine>
#include <a.h>


int main(int, char**) {
    for (int i = 0; i < 10; i++){
        std::cout << focus() << '\n';
    }
}


int focus(){
    for (int i = 0; i < 100; i++){
        co_ i;
    }
}
