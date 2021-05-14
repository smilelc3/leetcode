//
// Created by smile on 2021/5/14.
//

#include <stack>

class MinStack {
public:
    MinStack() = default;

    inline void push(int _val) {
        dataStack.emplace(_val);
        if (minStack.empty() or _val <= minStack.top()) {
            minStack.emplace(_val);
        }
    }
    inline void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }

    inline int top() {
        return dataStack.top();
    }

    inline int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> dataStack;
    std::stack<int> minStack;
};
