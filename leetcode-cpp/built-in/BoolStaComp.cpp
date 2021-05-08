//
// Created by smile on 2021/5/4.
//

#include "BoolStaComp.h"
#include <stdexcept>

void BoolStaComp::setSize(size_t _size) {
    if (_size < 0) {
        throw std::out_of_range("size must >= 0");
    }
    size = _size;

    auto int8sLength = size >> 3;
    if ((size & 0x7) != 0) {
        int8sLength++;
    }
    data = std::vector<uint8_t>(int8sLength, 0);
}

BoolStaComp::BoolStaComp(size_t _size) {
    setSize(_size);
}

void BoolStaComp::SetState(size_t idx, bool state) {
    if (state) {
        SetStateTrue(idx);
    } else {
        SetStateFalse(idx);
    }
}

void BoolStaComp::SetStateTrue(size_t idx) {
    data.at(idx >> 3) |= 1 << (idx & 0x7);
}

void BoolStaComp::SetStateFalse(size_t idx) {
    data.at(idx >> 3) &= ~(1 << (idx & 0x7));
}

void BoolStaComp::ReverseState(size_t idx) {
    data.at(idx >> 3) ^= 1 << (idx & 0x7);
}

bool BoolStaComp::GetState(size_t idx) {
    return data.at(idx >> 3) >> (idx & 0x7) & 1;
}
