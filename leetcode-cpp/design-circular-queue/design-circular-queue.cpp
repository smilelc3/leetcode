//
// Created by l30014168 on 2021/10/14.
//

#include <vector>

class MyCircularQueue {
private:
    std::vector<int> circleQueue;
    size_t queueSize;
    size_t frontIdx;        // 头指针位置，指向第一个元素
    size_t rearIdx;         // 尾指针位置，指向尾元素的下一个元素

public:
    explicit MyCircularQueue(int k) {
        queueSize = k + 1;      // 多预留一个位置，用于判空和判满
        circleQueue.resize(queueSize);
        frontIdx = rearIdx = 0;
    }

    // 向循环队列插入一个元素。如果成功插入则返回真。
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        circleQueue[rearIdx] = value;
        rearIdx = rearIdx + 1 == queueSize ? 0 : rearIdx + 1;
        return true;
    }

    // 从循环队列中删除一个元素。如果成功删除则返回真。
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        frontIdx = frontIdx + 1 == queueSize ? 0 : frontIdx + 1;
        return true;
    }

    // 从队首获取元素。如果队列为空，返回 -1
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return circleQueue[frontIdx];
    }

    // 获取队尾元素。如果队列为空，返回 -1 。
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return circleQueue[rearIdx == 0 ? queueSize - 1 : rearIdx - 1];
    }

    // 检查循环队列是否为空。
    bool isEmpty() const {
        return frontIdx == rearIdx;
    }

    // 检查循环队列是否已满。
    bool isFull() const {
        return frontIdx == (rearIdx + 1 == queueSize ? 0 : rearIdx + 1);
    }
};
