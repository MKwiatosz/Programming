/* 2017 Piotr Janczyk */
#include <iostream>
#include "solution.cpp"
#include "../../../misc/piotr-janczyk/linked-list-helper.cpp"
using helper = linked_list_helper<Node, int, &Node::val, &Node::next>;

int main() {
    Node* src1 = helper::make_list({1, 2, 3, 3, 1, 2});
    removeLongestIncreasingSubsequence(src1);
    Node* expected1 = helper::make_list({3, 1, 2});
    helper::assert_lists_equal(expected1, src1);

    Node* src2 = helper::make_list({3, 2, 1});
    removeLongestIncreasingSubsequence(src2);
    Node* expected2 = helper::make_list({3, 2, 1});
    helper::assert_lists_equal(expected2, src2);

    Node* src3 = helper::make_list({1});
    removeLongestIncreasingSubsequence(src3);
    Node* expected3 = helper::make_list({});
    helper::assert_lists_equal(expected3, src3);

    std::cout << "OK" << std::endl;
    return 0;
}
