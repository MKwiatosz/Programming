/* 2017 Piotr Janczyk */
#include <iostream>
#include "solution.cpp"
#include "../../../misc/piotr-janczyk/linked-list-helper.cpp"

using helper = linked_list_helper<node, int, &node::w, &node::next>;

int main() {
    node* src1 = helper::make_list({1, 3, 5});
    node* src2 = helper::make_list({1, 2, 4, 5});

    node* expected1 = helper::make_list({1, 5});
    node* expected2 = helper::make_list({1, 5});

    removeUncommonElements(src1, src2);

    helper::assert_lists_equal(expected1, src1);
    helper::assert_lists_equal(expected2, src2);

    std::cout << "OK" << std::endl;
    return 0;
}
