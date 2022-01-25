//
// Created by smile on 2021/8/30.
//

#include <unordered_map>
#include <list>
#define NOT_FIND (-1)

typedef int keyType;
typedef int valType;


class Node {
public:
    keyType key;
    valType val;
    size_t cnt;
    explicit Node(keyType key, valType val) : key(key), val(val), cnt(1) {}
    explicit Node(keyType key, valType val, size_t cnt) : key(key), val(val), cnt(cnt) {}
};


class LFUCache {
public:
    size_t cap;        // 容量
    // 链表中存Node{值，key出现次数}
    std::unordered_map<keyType, std::list<Node>::iterator> cacheMap;      // key到双向链接位置的Map
    std::unordered_map<size_t, std::list<Node>> freqMap;                  // freq到双向链表的Map

    explicit LFUCache(int capacity) {
        if (capacity < 0) {
            throw std::out_of_range("LFUCache's capacity must be >= 0");
        }
        this->cap = capacity;
        this->minFreq = 0;
    }

    // 获取key对应val，时间O(1)
    valType get(keyType key) {
        if (this->cap == 0) {
            return NOT_FIND;
        }
        auto iter = cacheMap.find(key);
        if (iter == cacheMap.end()) {
            return NOT_FIND;
        }
        valType val = iter->second->val;        // // 这里用到node.val
        updateExistNode(iter, key, val);
        return val;
    }

    // 设置key/val，时间O(1)
    void put(keyType key, valType value) {
        if (this->cap == 0) {
            return;
        }
        auto iter = cacheMap.find(key);
        if (iter != cacheMap.end()) {
            // 已存在该节点，该链表删除该节点，在新cnt+1链表中，头插入该更新后的节点，并更新cacheMap
            updateExistNode(iter, key, value);
        } else {
            if (cacheMap.size() == this->cap) { // 空间满，删除最小频次链表末尾
                cacheMap.erase(freqMap[this->minFreq].back().key);      // 这里用到node.key
                freqMap[this->minFreq].pop_back();
            }
            freqMap[1].emplace_front(Node(key, value));
            cacheMap[key] = freqMap[1].begin();
            this->minFreq = 1;
        }
    }

private:
    size_t minFreq;  // 最小频率，方便删除

    // 更新已存在的Node
    inline void updateExistNode(decltype(cacheMap.begin()) iter, keyType key, valType val) {
        auto node = iter->second;
        size_t cnt = node->cnt;     // // 这里用到node.cnt
        // 该链表删除该节点，在新cnt+1链表中，头插入该节点，并更新cacheMap
        freqMap[cnt].erase(node);
        if (freqMap[cnt].empty() and this->minFreq == cnt) {
            this->minFreq++;
        }
        freqMap[cnt + 1].emplace_front(Node(key, val, cnt +1));
        cacheMap[key] = freqMap[cnt + 1].begin();
    }
};
