//
// Created by smile on 2021/5/4.
//

#ifndef LEETCODE_CPP_BOOLSTACOMP_H
#define LEETCODE_CPP_BOOLSTACOMP_H

#include <vector>
#include <cstdint>

class BoolStaComp {
private:
    int size{};
    std::vector<uint8_t> data{};

    void setSize(int size);

public:
    // 构造函数
    explicit BoolStaComp(int size);

    // 指定idx位状态
    void SetState(int idx, bool state);

    // 指定idx位状态，置true
    void SetStateTrue(int idx);

    // 指定idx位状态，置false
    void SetStateFalse(int idx);

    // 指定idx位状态，取反
    void ReverseState(int idx);

    // 获取idx位状态
    bool GetState(int idx);
};


#endif //LEETCODE_CPP_BOOLSTACOMP_H
