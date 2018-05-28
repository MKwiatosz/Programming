#include <iostream>
using namespace std;

void buduj(int a, int b, int &n) {
    if (a == 0 && b == 0) {
        n++;
        return;
    }

    if (a > 0) buduj(a - 1, b, n);
    if (b > 0) buduj(a, b - 1, n);
}

int zadanie(int a, int b) {
    int ilosc = 0;
    buduj(a - 1, b, ilosc);
    return ilosc;
}

int main() {
    cout << zadanie(5, 3) << endl;
    return 0;
}