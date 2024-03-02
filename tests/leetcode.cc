#include "../skiplist.hpp"

class Skiplist {
public:

    haibarapink::skip_list<int,int> sl;

    Skiplist() {}

    bool search(int target) {
        auto opt = sl.search(target);
        if (opt.has_value()) {
            return true;
        }
        return false;
    }

    void add(int num) {
        sl.insert(num, num);
    }

    bool erase(int num) {
        bool ok = search(num);
        if (!ok) {
            return ok;
        }
        sl.erase(num);
        return true;
    }
};

int main(int, char**) {
    Skiplist skiplist;
    skiplist.add(1);
    skiplist.add(2);
    skiplist.add(3);
    assert(skiplist.search(0) == false);   // 返回 false
    skiplist.add(4);
    assert(skiplist.search(1));   // 返回 true
    skiplist.sl.print();
    assert(skiplist.erase(0) == false);    // 返回 false，0 不在跳表中
    assert(skiplist.erase(1));    // 返回 true
    assert(skiplist.search(1) == false);   // 返回 false，1 已被擦
    skiplist.sl.print();

}