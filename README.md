### 跳表 SkipList
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/c5997d8977034f92b5e9147e07942a67)](https://app.codacy.com/gh/Haibarapink/skip-list/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
### 用法 Usage
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

#### 参考 Reference

https://www.epaperpress.com/sortsearch/download/skiplist.pdf