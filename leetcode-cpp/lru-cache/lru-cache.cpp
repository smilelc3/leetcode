//
// Created by smile on 2021/4/30.
//

#include <unordered_map>
#include <stdexcept>

class LRUCache {
public:
    explicit LRUCache(int capacity) {
        if (capacity < 0) {
            throw std::out_of_range("capacity must be >= 0");
        }
        cap = capacity;
    }

    int get(int key) {
        try {

            return hashMap.at(key);
        } catch (const std::out_of_range &err) {
            return -1;
        }
    }

    void put(int key, int value) {
        if (hashMap.size() == cap) {
            // 删除最久未使用的数据值

        }
        hashMap[key] = value;
        cap = hashMap.size();
    }

private:
    std::unordered_map<int, int> hashMap;
    decltype(hashMap.size()) cap = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */