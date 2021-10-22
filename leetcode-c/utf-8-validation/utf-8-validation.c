//
// Created by l30014168 on 2021/10/22.
//

#include <stdbool.h>

bool validUtf8(const int *data, int dataSize) {
    int cursor = 0;
    while (cursor < dataSize) {
        uint8_t bytesLength = 0;
        if (data[cursor] <= 0b01111111) {
            bytesLength = 1;
        } else if (0b11000000 <= data[cursor] && data[cursor] <= 0b11011111) {
            bytesLength = 2;
        } else if (0b11100000 <= data[cursor] && data[cursor] <= 0b11101111) {
            bytesLength = 3;
        } else if (0b11110000 <= data[cursor] && data[cursor] <= 0b11110111) {
            bytesLength = 4;
        }
        if (bytesLength == 0) {
            return false;
        }
        if (cursor + bytesLength > dataSize) {
            return false;
        }
        for (uint8_t i = 1; i < bytesLength; ++i) {
            if (data[cursor + i] < 0b10000000 || data[cursor + i] > 0b10111111) {
                return false;
            }
        }
        cursor += bytesLength;
    }
    return true;
}