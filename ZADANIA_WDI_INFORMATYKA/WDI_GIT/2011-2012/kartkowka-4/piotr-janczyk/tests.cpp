/* 2016 Piotr Janczyk */
#include <iostream>
#include "solution.cpp"
#include "../../../misc/piotr-janczyk/linked-list-helper.cpp"

using helper = linked_list_helper<Node, int, &Node::val, &Node::next>;

int main() {
    Node* src = helper::make_list({
        0x00FF00FF, // (a) liczba średniobitowa (16 jedynek)
        0x0000000F, // (b) liczba niskobitowa (4 jedynki)
        0x0FFFFFFF, // (c) liczba wysokobitowa (28 jedynek)
        0x0000FF00, // (d) liczba średniobitowa (8 jedynek)
        0x00000000, // (e) liczba niskobitowa (0 jedynek)
        0x00F00000  // (f) liczba niskobitowa (4 jedynki)
    });

    Node* expected = helper::make_list({
        0x0000000F, // (b) liczba niskobitowa
        0x00000000, // (e) liczba niskobitowa
        0x00F00000, // (f) liczba niskobitowa
        0x00FF00FF, // (a) liczba średniobitowa
        0x0000FF00, // (d) liczba średniobitowa
        0x0FFFFFFF  // (c) liczba wysokobitowa
    });

    Node* actual = splitJoin(src);

    helper::assert_lists_equal(expected, actual);
    std::cout << "OK" << std::endl;
    return 0;
}
