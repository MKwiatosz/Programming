/* 2017 Piotr Janczyk */
#include <cstdlib>

struct node {
    int w;
    node* next;
};

void removeNode(node* n, node* parent) {
    parent->next = n->next;
    delete n;
}

// Usuwa z posortowanej rosnąco listy zaczynającej się wartownikiem
// element o wartości "val". Jeśli element nie został znaleziony, zwraca false.
bool removeIfExist(node& sentinel, int val) {
    node* p = &sentinel;
    while (p->next != NULL && p->next->w <= val) {
        if (p->next->w == val) {
            removeNode(p->next, p);
            return true;
        }
        p = p->next;
    }
    return false;
}

int removeCommonValues(node*& head1, node*& head2) {
    int removed = 0;

    node sentinel1;
    sentinel1.next = head1;
    node sentinel2;
    sentinel2.next = head2;

    // Przeglądamy drugą, nieposortowaną listę
    node* p = &sentinel2;

    while (p->next != NULL) {
        if (removeIfExist(sentinel1, p->next->w)) {
            // Jeżeli bieżąca wartość została znaleziona w pierwszej liście
            // (i usunięta z niej), to usuwamy ją też z drugiej listy
            removeNode(p->next, p);
        } else {
            p = p->next;
        }
    }

    head1 = sentinel1.next;
    head2 = sentinel2.next;
}
