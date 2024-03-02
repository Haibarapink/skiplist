#include <iostream>
#include <map>
#include "../skiplist.hpp"

int main(int, char**) {
    haibarapink::skip_list<int, int> sk;
    std::map<int, int> kv;
    for (int i = 0; i < 100; ++i ) {
        int rnd = rand();
        sk.insert(i, rnd);
        kv.emplace(i, rnd);
    }
    for (auto [k,v] : kv) {
        assert(sk.search(k).value() == v);
    }

    sk.erase(12);
    kv.erase(12);
    sk.erase(21);
    kv.erase(21);

    for (auto [k,v] : kv) {
        assert(sk.search(k).value() == v);
    }
}