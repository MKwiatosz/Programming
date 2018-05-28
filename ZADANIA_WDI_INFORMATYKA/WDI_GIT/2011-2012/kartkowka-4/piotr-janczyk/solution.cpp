/* 2016 Piotr Janczyk */
#include <cstdlib>

struct Node {
    int val;
    Node* next;
};

int getNumberType(int num) {
    unsigned int a = (unsigned int) num;
    int ones = 0; // liczba jedynek w zapisie binarnym
    while (a > 0) {
        if ((a & 1) == 1) {
            ones++;
        }
        a >>= 1;
    }

    if (ones < 8) {
        return 0; // liczba "niskobitowa"
    } else if (ones <= 24) {
        return 1; // liczba "średniobitowa"
    } else {
        return 2; // liczba "wysokobitowa"
    }
}

Node* splitJoin(Node* src) {
    Node* heads[3]; // początki podzielonych list
    Node* tails[3]; // końce podzielonych list

    for (int i = 0; i < 3; i++) {
        heads[i] = NULL;
        tails[i] = NULL;
    }

    // podzial listy
    Node* p = src;
    while (p != NULL) {
        int type = getNumberType(p->val);
        if (heads[type] == NULL) {
            heads[type] = p;
            tails[type] = p;
        } else {
            tails[type]->next = p;
            tails[type] = p;
        }
        p = p->next;
    }

    // scalenie podzialów w listę wynikową
    Node* resultHead = NULL; // początek listy wynikowej
    Node* resultTail = NULL; // koniec listy wynikowej
    for (int i = 0; i < 3; i++) {
        if (heads[i] != NULL) {
            if (resultHead == NULL) {
                resultHead = heads[i];
                resultTail = tails[i];
            } else {
                resultTail->next = heads[i];
                resultTail = tails[i];
            }
        }
    }

    if (resultTail != NULL) {
        resultTail->next = NULL;
    }

    return resultHead;
}
