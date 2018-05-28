/* 2017 Piotr Janczyk */
#include "solution.cpp"
#include <cassert>
#include <iostream>

int main() {
    assert(checkNumber(0xDB7532) == true);
    assert(checkNumber(1) == false);
    std::cout << "OK" << std::endl;
    return 0;
}
