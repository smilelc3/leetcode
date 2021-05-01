//
// Created by smile on 2021/4/30.
//

#include <unordered_map>
#include <list>
#include <stdexcept>

class LRUCache {

private:
    std::list<std::pair<int, int>> cache;   // 存keys的顺序
    std::unordered_map<int, decltype(cache.begin())> cacheMap;
    decltype(cacheMap.size()) cap = 0;

public:
    explicit LRUCache(int capacity) {
        if (capacity <= 0) {
            throw std::out_of_range("LRUCache's capacity must be > 0");
        }
        cap = capacity;
    }

    int get(int key) {
        try {
            auto res = cacheMap.at(key);
            // 移动到链表首位
            cache.splice(cache.begin(), cache, res);
            return res->second;        // 返回迭代器指向的值
        } catch (const std::out_of_range &) {
            return -1;
        }
    }

    void put(int key, int value) {
        // key不存在于map，且size < cap  -> 在链表首插入，并建立索引
        // key不存在于map，且size == cap -> 删除索引，删除链表末尾，[然后在链表首插入，并建立索引]
        // key存在于map -> 移动链表中索引元素至首位置，修改元素，修改索引
        auto iter = cacheMap.find(key);
        if (iter != cacheMap.end()) {
            // 如果key 存在于 map
            cache.splice(cache.begin(), cache, iter->second);
            cache.front() = {key, value};
            iter->second = cache.begin();
        } else {
            // key 不存在于 map
            if (cache.size() == cap) {
                // cap已满，删除最近使用
                cacheMap.erase(cacheMap.find(cache.back().first));
                cache.pop_back();
            }
            cache.emplace_front(std::make_pair(key, value));
            cacheMap[key] = cache.begin();
        }
    }
};
