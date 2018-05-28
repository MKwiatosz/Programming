/* 2016 Piotr Janczyk */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int tab[MAX];

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        tab[i] = (rand() % 900) + 100; // zakres 100-999
        cout << tab[i] << " ";
    }
    cout << endl;

    int result = 0;

    for (int start = 0; start < MAX; start++) { // start - początek ciągu
        for (int r_start = MAX - 1; r_start >= 0; r_start--) { // r_start - początek rewersu
            int i = 0;
            while (start + i < MAX && r_start - i >= 0 && tab[start + i] == tab[r_start - i]) {
                i++;
            }

            result = max(result, i);
        }
    }

    cout << result << endl;

    return 0;
}
