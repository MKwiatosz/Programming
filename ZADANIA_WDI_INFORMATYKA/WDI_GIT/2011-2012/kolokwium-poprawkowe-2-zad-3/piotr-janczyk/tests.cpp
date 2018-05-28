/* 2016 Piotr Janczyk */
#include "solution.cpp"
#include "../../../misc/piotr-janczyk/linked-list-helper.cpp"
using helper = linked_list_helper<Node, int, &Node::klucz, &Node::next>;

int main() {
    Node* src = NULL;
    for (int i = -10; i <= 10; i++) {
        helper::list_push_back(src, i);
    }

    Node* expectedMatching = helper::make_list({
        -9, -8, -4, 0, 4, 8, 9
    });
    Node* expectedOthers = helper::make_list({
        -10, -7, -6, -5, -3, -2, -1, 1, 2, 3, 5, 6, 7, 10
    });

    Node* actualMatching;
    Node* actualOthers;
    split(src, actualMatching, actualOthers);

    helper::assert_lists_equal(expectedMatching, actualMatching);
    helper::assert_lists_equal(expectedOthers, actualOthers);

    cout << "OK" << endl;
    return 0;
}
