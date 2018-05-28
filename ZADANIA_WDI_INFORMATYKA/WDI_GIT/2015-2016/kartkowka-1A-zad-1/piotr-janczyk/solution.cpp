/* 2016 Piotr Janczyk */

// sprawdza czy cyfra (w systemie o podstawie 2-16) jest liczbą pierwszą
bool isPrimeDigit(int d) {
    const int PRIMES[6] = {2, 3, 5, 7, 11, 13};
    for (int i = 0; i < 6; i++) {
        if (PRIMES[i] == d) {
            return true;
        }
    }
    return false;
}

// zwraca true, jeśli liczba n spełnia warunki zadania
bool checkNumber(int n) {
    for (int base = 2; base <= 16; base++) {
        bool allDigitsPrime = true;

        int tmp = n;
        while (tmp != 0 && allDigitsPrime) {
            allDigitsPrime = isPrimeDigit(tmp % base);
            tmp /= base;
        }

        if (allDigitsPrime) {
            return true;
        }
    }

    return false;
}
