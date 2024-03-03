#include "../skiplist.hpp"
#include <string>
#include <iostream>
using namespace haibarapink;
int main(int , char**) {
    skip_list<std::string, std::string> kv;

    kv.insert("hello", "github");
    kv.insert("author", "haibarapink");
    kv.insert("email", "haibarapink@gmail.com");

    for (auto [k, v] : kv) {
        std::cout << k << " " << v << std::endl;
    }

    kv.erase("author");
    assert(kv.erase("sasha") == false);

    for (auto iter = kv.begin();iter != kv.end(); ++iter) {
        auto [k,v] = *iter;
        std::cout << k << " " << v << std::endl;
    }
}