### SkipList

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/c5997d8977034f92b5e9147e07942a67)](https://app.codacy.com/gh/Haibarapink/skip-list/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)

📕 Support iterator

🚀 Pretty fast skiplist

### Usage

include `skiplist.hpp` in your projects.

```
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
```
#### Benchmark
env: intel core i5-10th, linux , g++11.4.0.

Insert 1 hundred thousand records

| std::map  | skip_list |
|-----------|-----------|
| 0.106978s | 0.147196s |

Search 1 hundred thousand records

| std::map   | skip_list |
|------------|-----------|
| 0.0372792s | 0.132071s |


#### Reference

https://www.epaperpress.com/sortsearch/download/skiplist.pdf