/* 2016 Piotr Janczyk */
#include <iostream>
using namespace std;

const int N = 2;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    int d = 2;
    while (d * d <= n) {
        if (n % d == 0) {
            return false;
        }
        d++;
    }
    return true;
}

int generate_rec(int t1[N], int t2[N], int choice[N], int n, int sum) {
    if (n == N) {
        if (is_prime(sum)) {
            for (int i = 0; i < N; i++) {
                if (i != 0) {
                    cout << "+";
                }

                if (choice[i] == 1) {
                    cout << t1[i];
                } else if (choice[i] == 2) {
                    cout << t2[i];
                } else { // 3
                    cout << t1[i] << "+" << t2[i];
                }
            }
            cout << endl;
            return 1;
        } else {
            return 0;
        }
    }

    int result = 0;
    choice[n] = 1;
    result += generate_rec(t1, t2, choice, n + 1, sum + t1[n]);
    choice[n] = 2;
    result += generate_rec(t1, t2, choice, n + 1, sum + t2[n]);
    choice[n] = 3;
    result += generate_rec(t1, t2, choice, n + 1, sum + t1[n] + t2[n]);
    return result;
}

int generate(int t1[N], int t2[N]) {
    int choice[N];
    return generate_rec(t1, t2, choice, 0, 0);
}

int main() {
    int t1[] = {1, 2};
    int t2[] = {3, 4};
    cout << "Total: " << generate(t1, t2) << endl;
    return 0;
}
