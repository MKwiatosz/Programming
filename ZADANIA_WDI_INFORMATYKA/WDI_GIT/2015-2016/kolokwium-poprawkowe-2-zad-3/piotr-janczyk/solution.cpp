/* 2017 Piotr Janczyk */
#include <cstdlib>

struct Coords {
    int x;
    int y;
};

struct Node {
    Coords coords;
    Node* next;
};

// Zwraca numer ćwiartki układu współrzędnych lub -1, jeśli punkt leży
// na osiach układu współrzędnych
int getQuadrant(Coords coords) {
    if (coords.x == 0 || coords.y == 0) {
        return -1;
    } else {
        if (coords.x > 0) {
            if (coords.y > 0) {
                return 1;
            } else {
                return 4;
            }
        } else {
            if (coords.y > 0) {
                return 2;
            } else {
                return 3;
            }
        }
    }
}

// Rozdziela listę punktów na 4 listy względem ćwiartki układu współrzędnych.
// Po wywołaniu funkcji:
//   results[0] - lista punktów z I ćw.
//   results[1] - lista punktów z II ćw.
//   results[2] - lista punktów z III ćw.
//   results[3] - lista punktów z IV ćw.
void splitByQuadrants(Node* src, Node* results[4]) {
    Node* ends[4];
    for (int i = 0; i < 4; i++) {
        ends[i] = NULL;
        results[i] = NULL;
    }

    while (src != NULL) {
        Node* next = src->next;

        int quadrant = getQuadrant(src->coords);
        if (quadrant == -1) {
            delete src;
        } else {
            int idx = quadrant - 1;
            if (results[idx] == NULL) {
                results[idx] = src;
            } else {
                ends[idx]->next = src;
            }
            ends[idx] = src;
            ends[idx]->next = NULL;
        }

        src = next;
    }
}
