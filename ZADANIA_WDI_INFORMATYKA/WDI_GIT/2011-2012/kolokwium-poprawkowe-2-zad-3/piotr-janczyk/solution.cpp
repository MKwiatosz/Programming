/* 2016 Piotr Janczyk */
#include <iostream>
using namespace std;

struct Node {
    int klucz;
    Node* next;
};

// Sprawdza, czy liczba jest wielokrotnością kwadratu liczby pierwszej.
bool isPrimeSquareMultiple(int num) {
    num = abs(num);
    if (num == 0) {
        return true;
    }

    int d = 2;
    while (d * d <= num) {
        if (num % (d * d) == 0) {
            // Jeśli liczba jest podzielna przez kwadrat liczby naturalnej,
            // to jest też w szczegolności podzielna przez
            // kwadrat liczby pierwszej.
            return true;
        }
        d++;
    }
    return false;
}

void split(Node* src, Node*& matching, Node*& others) {
    matching = NULL;
    others = NULL;
    Node* matchingEnd = NULL;
    Node* othersEnd = NULL;

    while (src != NULL) {
        if (isPrimeSquareMultiple(src->klucz)) {
            if (matching == NULL) {
                matching = src;
            } else {
                matchingEnd->next = src;
            }
            matchingEnd = src;
        } else {
            if (others == NULL) {
                others = src;
            } else {
                othersEnd->next = src;
            }
            othersEnd = src;
        }
        src = src->next;
    }

    if (matchingEnd != NULL) {
        matchingEnd->next = NULL;
    }
    if (othersEnd != NULL) {
        othersEnd->next = NULL;
    }
}
