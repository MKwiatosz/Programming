/* 2016 Piotr Janczyk */
#include "solution.cpp"
#include <iostream>
#include <cassert>

int main() {
    assert(wyraz("ula", "aexebx") == true);
    assert(wyraz("aaa", "aa") == false);
    std::cout << "OK" << std::endl;
    return 0;
}
