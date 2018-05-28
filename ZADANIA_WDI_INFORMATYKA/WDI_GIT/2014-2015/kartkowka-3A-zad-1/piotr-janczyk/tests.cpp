/* 2017 Piotr Janczyk */
#include <iostream>
#include <cassert>

#define N 4
#include "solution.cpp"

int main() {
    int t1[N][N] = {
        1, 1, 1, 1,
        2, 1, 5, 1,
        1, 1, 1, 1,
        3, 1, 7, 1,
    };
    int k1 = 2 * 3 * 5 * 7;

    int t2[N][N] = {
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
    };
    int k2 = 13;

    int row, col;

    findMachingCorners(t1, k1, row, col);
    assert(row == 2 && col == 1);

    findMachingCorners(t2, k2, row, col);
    assert(row == -1 && col == -1);

    std::cout << "OK" << std::endl;
    return 0;
}
