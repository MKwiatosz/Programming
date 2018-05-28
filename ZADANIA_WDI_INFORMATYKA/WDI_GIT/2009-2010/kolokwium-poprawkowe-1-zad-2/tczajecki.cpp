#include <iostream>
using namespace std;

// a - suma elementow
// b - suma indeksow
// c - ilosc elementow
void podzbior(
    int tab[], int n, int a, int b, int c, int i, int &min_rozmiar, int &suma) {
    if (c > 0 && a == b && c < min_rozmiar) {
        min_rozmiar = c;
        suma = a;
    }

    if (i == n) {
        return;
    }

    podzbior(tab, n, a + tab[i], b + i, c + 1, i + 1, min_rozmiar, suma);
    podzbior(tab, n, a, b, c, i + 1, min_rozmiar, suma);
}

int zadanie(int tab[], int n) {
    int min_rozmiar = 10e8;
    int suma = 0;

    podzbior(tab, n, 0, 0, 0, 0, min_rozmiar, suma);
    return suma;
}

int main() {
    int tab[] = { 6, 2, 4, 10, 1 };
    cout << zadanie(tab, 5) << endl;
    return 0;
}