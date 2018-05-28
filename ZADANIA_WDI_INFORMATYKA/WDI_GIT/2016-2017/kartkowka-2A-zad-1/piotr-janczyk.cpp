/* 2016 Piotr Janczyk */
#include <iostream>
using namespace std;

// odwraca kolejnosc cyfr
int reverse(int n) {
    int k = 0;
    while (n > 0) {
        k = (10 * k) + (n % 10);
        n /= 10;
    }
    return k;
}

// najwiekszy wspolny dzielnik
int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

/// src - liczba wejściowa z odwróconą kolejnością cyfr
/// a - pierwsza generowana liczba
/// b - druga generowana liczba
/// last_added_to_a - cyfra, która została dopisana do "a" w poprzednim
///   w wywołaniu funkcji lub -1 jeśli w poprzednim wywołaniu "a" pozostało
///   niezmienione
int generate_recursive(int src, int a, int b, int last_added_to_a) {
    if (src == 0) {
        if (a != 0 && b != 0 && gcd(a, b) == 1) {
            cout << a << "," << b << endl;
            return 1;
        } else {
            return 0;
        }
    }

    int digit = src % 10; // ostatnia cyfra
    int new_src = src / 10; // pozostale cyfry

    int new_a = (10 * a) + digit;
    int new_b = (10 * b) + digit;

    int result = 0;

    result += generate_recursive(new_src, new_a, b, digit); // dopisanie cyfry do "a"

    if (digit != last_added_to_a) { // wymagane sprawdzenie, aby nie wypisywać zduplikowanych wyników
        result += generate_recursive(new_src, a, new_b, -1); // dopisanie cyfry do "b"
    }

    return result;
}

int generate(int n) {
    n = reverse(n);
    return generate_recursive(n, 0, 0, -1);
}

// przykladowy program:
int main() {
    int n;
    cin >> n;
    cout << "Total: " << generate(n) << endl;
    return 0;
}
