/* 2017 Piotr Janczyk */
#include <cstdlib>

struct Node {
    int val;
    Node* next;
};

// Zakładam, że podłańcuch składający się z tylko jednego węzła
// jest również podłańcuchem rosnącym.

void removeLongestIncreasingSubsequence(Node*& head) {
    if (head == NULL) {
        return;
    }

    int maxLength = 0; // długość najdłuższego podłańcucha rosnącego
    Node** maxStart = NULL; // początek najdłuższego podłańcucha
    Node* maxEnd = NULL; // koniec najdłuższego podłańcucha
    bool repeated = true; // czy istnieje więcej niż jeden
                          // najdłuższy podłańcuch rosnący

    int length = 1;
    Node** start = &head;
    Node* q = head;

    for (;;) {
        if (q->next == NULL || q->val >= q->next->val) {
            if (length == maxLength) {
                repeated = true;
            } else if (length > maxLength) {
                repeated = false;
                maxLength = length;
                maxStart = start;
                maxEnd = q;
            }
            if (q->next != NULL) {
                length = 1;
                start = &q->next;
                q = q->next;
            }
        }

        if (q->next == NULL) {
            break;
        }

        if (q->val < q->next->val) {
            length++;
            q = q->next;
        }
    }

    if (!repeated) {
        *maxStart = maxEnd->next;
    }
}
