#include <cstdlib>
#include <iostream>

template<typename TNode, typename TVal, TVal TNode::* fieldVal, TNode* TNode::* fieldNext>
struct linked_list_helper {
    static TNode* make_list(std::initializer_list<TVal> values) {
        TNode* head = NULL;
        TNode* tail = NULL;
        for (TVal val : values) {
            TNode* n = new TNode;
            n->*fieldVal = val;
            n->*fieldNext = NULL;
            if (head == NULL) {
                head = tail = n;
            } else {
                tail->*fieldNext = n;
                tail = n;
            }
        }
        return head;
    }

    static TNode* list_join(TNode* head1, TNode* head2) {
        TNode** tail1 = &head1;
        while (*tail1 != NULL) {
            tail1 = &((*tail1)->*fieldNext);
        }
        *tail1 = head2;
        return head1;
    }

    static void list_push_back(TNode*& head, TVal val) {
        TNode* newNode = new TNode;
        newNode->*fieldNext = NULL;
        newNode->*fieldVal = val;
        head = list_join(head, newNode);
    }

    static bool lists_equal(TNode* p, TNode* q) {
        while (p != NULL && q != NULL && p->*fieldVal == q->*fieldVal) {
            p = p->*fieldNext;
            q = q->*fieldNext;
        }
        return p == NULL && q == NULL;
    }

    static void print_list(TNode* p) {
        std::cout << "[";
        if (p != NULL) {
            std::cout << p->*fieldVal;
            p = p->*fieldNext;
        }
        while (p != NULL) {
            std::cout << ", " << p->*fieldVal;
            p = p->*fieldNext;
        }
        std::cout << "]" << std::endl;
    }

    static void assert_lists_equal(TNode* expected, TNode* actual) {
        if (!lists_equal(expected, actual)) {
            std::cout << "Expected: " << std::endl;
            print_list(expected);
            std::cout << "Actual: " << std::endl;
            print_list(actual);
            exit(-1);
        }
    }
};
