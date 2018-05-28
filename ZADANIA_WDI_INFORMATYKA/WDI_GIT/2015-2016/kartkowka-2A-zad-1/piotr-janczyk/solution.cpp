/* 2016 Piotr Janczyk */
#include <string>
using namespace std;

bool find_operations_rec(int x, int y, char seq[], int n) {
    if (x == y) {
        seq[n] = '\0';
        return true;
    }
    if (n == 7) {
        return false;
    }

    if (x >= 10) {
        seq[n] = 'C';
        int mask = 1;
        for (int i = x; i > 0; i /= 10) {
            mask *= 10;
        }
        mask /= 10;
        // np. dla x==1234:  mask==1000
        int x2 = x - ((x / mask) * mask);

        if (find_operations_rec(x2, y, seq, n + 1)) {
            return true;
        }
    }

    if (x >= 10) {
        seq[n] = 'A';
        int d1 = x % 10; // cyfra jednosci
        int d2 = (x / 10) % 10; // cyfra dziesiatek
        int k = x / 100; // pozostale cyfry
        int x2 = 100 * k + 10 * d1 + d2;

        if (find_operations_rec(x2, y, seq, n + 1)) {
            return true;
        }
    }

    seq[n] = 'B';
    if (find_operations_rec(3 * x, y, seq, n + 1)) {
        return true;
    }

    return false;
}

string find_operations(int x, int y) {
    char sequence[8];
    if (find_operations_rec(x, y, sequence, 0)) {
        return string(sequence);
    } else {
        return "";
    }
}
