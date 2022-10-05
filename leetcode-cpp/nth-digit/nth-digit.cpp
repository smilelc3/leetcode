//
// Created by smile on 2022/10/5.
//

class Solution {
public:
    int findNthDigit(int n) {
        int width = 1;
        int64_t widthNum = 9;
        int num = n - 1;
        while (num >= width * widthNum) {
            num -= static_cast<decltype(num)>(width * widthNum);
            width++;
            widthNum *= 10;
        }
        auto divRet = std::div(num, width);
        return getWidthNthPlaceDigit(width, divRet.quot, divRet.rem);
    }

private:
    int getWidthNthPlaceDigit(int width, int nth, int place) {
        if (place + 1 == width) {
            return width == 1 ? nth + 1 : nth % 10;
        }
        return getWidthNthPlaceDigit(width - 1, nth / 10, place);
    }
};