### 跳表 SkipList

实现一个支持并发的 skip_list

### 用法 usage
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

#### 参考 reference

https://www.epaperpress.com/sortsearch/download/skiplist.pdf