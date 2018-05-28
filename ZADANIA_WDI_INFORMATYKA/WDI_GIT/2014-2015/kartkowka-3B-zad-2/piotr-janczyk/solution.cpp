/* 2017 Piotr Janczyk */
#include <cstdlib>

struct node {
    int w;
    node* next;
};

void removeNode(node* parent, node* node) {
    parent->next = node->next;
    delete node;
}

int removeUncommonElements(node*& head1, node*& head2) {
    node sentinel1, sentinel2;
    sentinel1.next = head1;
    sentinel2.next = head2;

    int removed = 0;

    node* p = &sentinel1;
    node* q = &sentinel2;

    while (p->next != NULL || q->next != NULL) {
        if (p->next != NULL && (q->next == NULL || p->next->w < q->next->w)) {
            removeNode(p, p->next);
            removed++;
        } else if (q->next != NULL && (p->next == NULL || q->next->w < p->next->w)) {
            removeNode(q, q->next);
            removed++;
        } else {  // p->next != NULL && q->next != NULL && p->next->w == q->next->w
            p = p->next;
            q = q->next;
        }
    }

    head1 = sentinel1.next;
    head2 = sentinel2.next;
}
