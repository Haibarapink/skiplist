#include "../skiplist.hpp"
void test_skiplist_operations() {
    haibarapink::skip_list<int, int> skiplist;

    // SkipList initialization
    skiplist.print();

    // Perform operations
    skiplist.insert(9, 0);
    skiplist.insert(4, 0);
    skiplist.insert(5, 0);
    skiplist.insert(6, 0);
    skiplist.insert(9, 0);  // Note: This inserts a duplicate key, you might want to handle duplicates in your implementation
    skiplist.erase(2);
    skiplist.erase(1);
    skiplist.insert(2, 0);

    assert(skiplist.search(7) == std::nullopt);
    assert(skiplist.search(4) == std::make_optional(0));

    skiplist.insert(5, 0);
    skiplist.insert(6, 0);
    skiplist.insert(7, 0);
    skiplist.erase(4);

    assert(skiplist.search(3) == std::nullopt);

    skiplist.erase(6);

    assert(skiplist.search(3) == std::nullopt);
    assert(skiplist.search(4) == std::nullopt);
    assert(skiplist.search(7) != std::nullopt);

    skiplist.erase(6);
    skiplist.erase(1);

    assert(skiplist.search(0) == std::nullopt);

    skiplist.insert(3, 0);
    skiplist.insert(4, 0);
    skiplist.erase(7);
    skiplist.insert(6, 0);

    assert(skiplist.search(3) == std::make_optional(0));
    assert(skiplist.search(4) == std::make_optional(0));
    assert(skiplist.search(7) == std::nullopt);
    assert(skiplist.search(6) == std::make_optional(0));

    skiplist.erase(1);

    assert(skiplist.search(0) == std::nullopt);
}

int main(int, char**) {
    test_skiplist_operations();
}