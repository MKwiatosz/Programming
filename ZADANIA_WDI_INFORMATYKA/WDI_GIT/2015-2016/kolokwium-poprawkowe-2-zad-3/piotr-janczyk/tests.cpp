/* 2017 Piotr Janczyk */
#include <iostream>
#include "solution.cpp"
#include "../../../misc/piotr-janczyk/linked-list-helper.cpp"
using helper = linked_list_helper<Node, Coords, &Node::coords, &Node::next>;

bool operator==(const Coords& lhs, const Coords& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::ostream& operator<<(std::ostream& stream, const Coords& coords) {
    return stream << "(" << coords.x << "," << coords.y << ")";
}

int main() {
    Node* src = helper::make_list({ {-1, -1}, {1, 1}, {1, 2}, {0, 1}, {-1, 1} });
    Node* expected[4] = {
        helper::make_list({ {1, 1}, {1, 2} }), // I ćw.
        helper::make_list({ {-1, 1} }), // II ćw.
        helper::make_list({ {-1, -1} }), // III ćw.
        helper::make_list({}) // IV ćw.
    };

    Node* actual[4];
    splitByQuadrants(src, actual);

    for (int i = 0; i < 4; i++) {
        helper::assert_lists_equal(expected[i], actual[i]);
    }

    std::cout << "OK" << std::endl;
    return 0;
}
