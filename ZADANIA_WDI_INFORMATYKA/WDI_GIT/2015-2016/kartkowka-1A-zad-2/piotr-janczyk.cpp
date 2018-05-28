/* 2016 Piotr Janczyk */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Zakładam, że ciąg arytmetyczny rosnący/malejący musi mieć długość >= 1

int main() {
    const int N = 10;
    int t[N];
    srand(time(NULL)); // zainicjalizowanie gen. liczb pseudolosowych

    // Wypełnienie tablicy liczbami pseudolosowymi
    for (int i = 0; i < N; i++) {
        int k = rand() % 50; // k=0,1,2...,49
        k *= 2; // k=0,2,4,...,98
        k += 1; // k=1,3,5,...,99
        t[i] = k;
    }

    if (N <= 1) {
        // najdłuższy ciąg arytmetyczny rosnący ma długość 1
        // najdłuższy ciąg arytmetyczny malejący ma długość 1
        cout << 0 << endl;
        return 0;
    }

    int maxIncLength = 1;
    int maxDecLength = 1;
    int diff = t[1] - t[0];
    int length = 2;

    for (int i = 2; i < N; i++) {
        if (t[i - 1] + diff == t[i]) {
            length++;
        } else {
            if (diff > 0) { // ciąg arytmetyczny rosnący
                maxIncLength = max(maxIncLength, length);
            } else if (diff < 0) { // ciąg arytmetyczny malejący
                maxDecLength = max(maxDecLength, length);
            }
            diff = t[i] - t[i - 1];
            length = 2;
        }
    }

    if (diff > 0) {
        maxIncLength = max(maxIncLength, length);
    } else if (diff < 0) {
        maxDecLength = max(maxDecLength, length);
    }

    cout << (maxIncLength - maxDecLength) << endl;
    return 0;
}
