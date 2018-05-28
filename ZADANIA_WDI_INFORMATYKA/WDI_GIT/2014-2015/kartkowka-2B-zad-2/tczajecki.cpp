#include <iostream>
using namespace std;

bool czy_pierwsza(int a) {
    if (a < 2) {
        return false;
    }
    
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

// a, b - zadane liczby
// c - budowana liczba
// n - kolejne potegi 10 potrzebne do przesuwania cyfr
// ilosc - zliczanie
void wyznacz(int a, int b, int c, int n, int &ilosc) {
    if (a == 0 && b == 0) {
        cout << c << endl;
        if (czy_pierwsza(c)) {
            ilosc++;
        }

        return;
    }

    if (a > 0) wyznacz(a / 10, b, c + n * (a % 10), n * 10, ilosc);
    if (b > 0 && b % 10 != a % 10) wyznacz(a, b / 10, c + n * (b % 10), n * 10, ilosc);
}

int zadanie(int a, int b) {
    int ilosc = 0;
    cout << "Wygenerowane liczby: " << endl;
    wyznacz(a, b, 0, 1, ilosc);
    return ilosc;
}

int main() {
    cout << "\nIlosc liczb spelniajacych warunki zadania: "
         << zadanie(11, 10)
         << endl;

    // Test dla 0.
    cout << "\n\nTesty:\n";
    zadanie(0, 0);
    zadanie(1, 0);
    zadanie(10, 0);
    zadanie(0, 11);
    return 0;
}