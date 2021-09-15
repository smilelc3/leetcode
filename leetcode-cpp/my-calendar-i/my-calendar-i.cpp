//
// Created by l30014168 on 2021/9/11.
//

#include <map>

class MyCalendar {
public:
    std::map<int, int> end2StartMap;

    MyCalendar() = default;

    // 将end作为key，start作为value
    // 在map中找到第一个key(end)大于start的item,只要存在且item->second < end 就不能添加新的日程安排。
    bool book(int start, int end) {
        auto item = end2StartMap.lower_bound(start);
        if (item != end2StartMap.end() and item->first == start) {
            item++;
        }
        if (item != end2StartMap.end() and item->second < end) {
            return false;
        }
        end2StartMap[end] = start;
        return true;
    }
};