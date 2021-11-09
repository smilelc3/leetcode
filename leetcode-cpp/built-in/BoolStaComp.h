//
// Created by smile on 2021/5/4.
//

#ifndef LEETCODE_CPP_BOOLSTACOMP_H
#define LEETCODE_CPP_BOOLSTACOMP_H

#include <vector>
#include <cstdint>
#include <cstddef>

class BoolStaComp {
private:
    size_t size{};
    std::vector<uint8_t> data{};

    void setSize(size_t size);

public:
    // 构造函数
    explicit BoolStaComp(size_t size);

    // 指定idx位状态
    void SetState(size_t idx, bool state);

    // 指定idx位状态，置true
    void SetStateTrue(size_t idx);

    // 指定idx位状态，置false
    void SetStateFalse(size_t idx);

    // 指定idx位状态，取反
    void ReverseState(size_t idx);

    // 获取idx位状态
    bool GetState(size_t idx);
};


#endif //LEETCODE_CPP_BOOLSTACOMP_H
