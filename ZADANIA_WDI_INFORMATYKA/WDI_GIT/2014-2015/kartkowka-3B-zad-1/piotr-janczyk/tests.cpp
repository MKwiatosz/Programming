/* 2017 Piotr Janczyk */
#include <iostream>
#include <cassert>

#define N 5
#include "solution.cpp"

int main() {
    int t1[N][N] = {
         2,  2,  2,  2,  2,
         2,  2,  2,  1,  2,
         2,  2,  3,  2,  2,
         2,  9,  2,  2,  2,
        27,  2,  2,  2,  2,
    };

    int t2[N][N] = {
        1, 1, 1, 1, 1,
        2, 2, 2, 2, 2,
        1, 1, 1, 1, 1,
        2, 2, 2, 2, 2,
        1, 1, 1, 1, 1
    };

    assert(findLongestGeometricSequence(t1) == 4);
    assert(findLongestGeometricSequence(t2) == -1);

    std::cout << "OK" << std::endl;
    return 0;
}
