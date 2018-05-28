/* 2016 Piotr Janczyk */
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    double k;
    cin >> k;
    double a = 1;
    double b = 2;
    double best = 1;
    char bestSeq = 'a';

    while (a <= k || b <= k) {
        if (fabs(a - k) < fabs(best - k)) {
            best = a;
            bestSeq = 'a';
        }
        if (fabs(b - k) < fabs(best - k)) {
            best = b;
            bestSeq = 'b';
        }
        b = b + a; // b[n] = b[n-1] + a[n-1]
        a = a + b / 3.0; // a[n] = a[n-1] + b[n-1] / 3
    }
    // po wyjściu z pętli a > k && b > k

    if (fabs(a - k) < fabs(best - k)) {
        best = a;
        bestSeq = 'a';
    }
    if (fabs(b - k) < fabs(best - k)) {
        best = b;
        bestSeq = 'b';
    }

    cout << bestSeq << ", " << best << endl;
    return 0;
}
