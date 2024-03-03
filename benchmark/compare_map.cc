#include <iostream>
#include <map>
#include <chrono>
#include "../skiplist.hpp"

int main() {
    // 测试数据
    const int N = 100000;
    std::vector<int> keys;
    for (int i = 0; i < N; ++i) {
        keys.push_back(rand());
    }

    // 使用 std::map 进行插入操作性能测试
    {
        std::map<int, int> stdMap;
        auto start = std::chrono::high_resolution_clock::now();
        for (int key : keys) {
            stdMap[key] = key;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "std::map insertion time: " << duration.count() << " seconds" << std::endl;
    }

    // 使用自定义 skip_list 进行插入操作性能测试
    {
        haibarapink::skip_list<int, int> customSkipList;
        auto start = std::chrono::high_resolution_clock::now();
        for (int key : keys) {
            customSkipList.insert(key, key);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Custom skip_list insertion time: " << duration.count() << " seconds" << std::endl;
    }

    // 使用 std::map 进行查找操作性能测试
    {
        std::map<int, int> stdMap;
        for (int key : keys) {
            stdMap[key] = key;
        }

        auto start = std::chrono::high_resolution_clock::now();
        for (int key : keys) {
            stdMap.find(key);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "std::map search time: " << duration.count() << " seconds" << std::endl;
    }

    // 使用自定义 skip_list 进行查找操作性能测试
    {
        haibarapink::skip_list<int, int> customSkipList;
        for (int key : keys) {
            customSkipList.insert(key, key);
        }

        auto start = std::chrono::high_resolution_clock::now();
        for (int key : keys) {
            customSkipList.search(key);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Custom skip_list search time: " << duration.count() << " seconds" << std::endl;
    }

    return 0;
}

