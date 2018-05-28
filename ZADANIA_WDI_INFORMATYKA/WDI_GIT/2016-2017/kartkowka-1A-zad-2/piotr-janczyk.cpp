/* 2016 Piotr Janczyk */
#include <stdio.h>
#include <time.h>
#include <iostream>

const int MAX = 12;

// Znajduje największy element w tablicy będący jednocześnie mniejszy od "limit"
// oraz liczbę jego wystąpień
void find_max_less_than(const int tab[MAX],
                        int limit,
                        /*out*/ int& max,
                        /*out*/ int& count) {
    max = -1;

    for (int i = 0; i < MAX; i++) {
        if (tab[i] < limit) {
            if (tab[i] > max) {
                max = tab[i];
                count = 1;
            } else if (tab[i] == max) {
                count++;
            }
        }
    }
}

int main() {
    int tab[MAX];

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        tab[i] = (rand() % 1000) + 1;
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;

    int sum = 0;
    int n = 0;

    int limit = 1001;

    while (n < 10) {
        int max, maxCount;
        find_max_less_than(tab, limit, max, maxCount);
        maxCount = std::min(maxCount, 10 - n);
        n += maxCount;
        sum += max * maxCount;
        limit = max;
    }

    std::cout << sum << std::endl;
}
