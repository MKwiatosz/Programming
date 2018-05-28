/* 2017 Piotr Janczyk */
#include <algorithm>

/// (x,y) - prawy-górny narożnik przekątnej, w której szukany ma być
///   ciąg geometryczny
int findInDiagonal(int t[N][N], int x, int y) {
    int maxLen = 0;
    int len = 2;

    while (y + 2 < N && x - 2 >= 0) {
        long long a1 = t[y][x];
        long long a2 = t[y + 1][x - 1];
        long long a3 = t[y + 2][x - 2];

        if (a1 * a3 == a2 * a2) {
            len++;
        } else {
            maxLen = std::max(maxLen, len);
            len = 2;
        }

        y++;
        x--;
    }

    maxLen = std::max(maxLen, len);

    return maxLen;
}

/// Zwraca długość najdłuższego ciągu geometrycznego lub (-1) w przypadku
/// nie znalezienia żadnego.
int findLongestGeometricSequence(int t[N][N]) {
    int maxLen = 0;

    for (int x = 2; x < N; x++) {
        maxLen = std::max(maxLen, findInDiagonal(t, x, 0));
    }

    for (int y = 1; y < N - 2; y++) {
        maxLen = std::max(maxLen, findInDiagonal(t, N - 1, y));
    }

    if (maxLen >= 3) {
        return maxLen;
    } else {
        return -1;
    }
}
