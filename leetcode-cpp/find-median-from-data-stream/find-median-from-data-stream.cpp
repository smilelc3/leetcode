//
// Created by smile on 2021/8/28.
//

#include <queue>

class MedianFinder {
public:
    // 两个优先队列
    std::priority_queue<int, std::vector<int>, std::less<>> leftQueue;
    std::priority_queue<int, std::vector<int>, std::greater<>> rightQueue;

    MedianFinder() = default;

    void addNum(int num) {
        if (leftQueue.size() > rightQueue.size()) { // 左边长度 > 右边长度
            auto leftTop = leftQueue.top();
            if (leftTop < num) {
                rightQueue.emplace(num);
            } else {
                rightQueue.emplace(leftTop);
                leftQueue.pop();
                leftQueue.emplace(num);
            }
        } else if (leftQueue.size() < rightQueue.size()) {  // 左边长度 < 右边长度
            auto rightTop = rightQueue.top();
            if (rightTop > num) {
                leftQueue.emplace(num);
            } else {
                leftQueue.emplace(rightTop);
                rightQueue.pop();
                rightQueue.emplace(num);
            }
        } else {    // 左边长度 == 右边长度
            if (leftQueue.empty() and rightQueue.empty()) {
                leftQueue.emplace(num);
            } else {
                if (leftQueue.top() > num) {
                    leftQueue.emplace(num);
                } else {
                    rightQueue.emplace(num);
                }
            }
        }
    }

    inline double findMedian() const {
        if (leftQueue.size() > rightQueue.size()) {
            return leftQueue.top();
        } else if (leftQueue.size() < rightQueue.size()) {
            return rightQueue.top();
        } else {
            return (leftQueue.top() + rightQueue.top()) * 0.5;
        }
    }

};

