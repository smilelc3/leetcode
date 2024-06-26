//
// Created by smile on 24-6-25.
//

int clumsy(int n) {
    const int ansTable[4 + 1] = {0, 1, 2, 6, 7};
    if (n <= 4) {
        return ansTable[n];
    }
    int mid = 0;
    int head = 2 * n - 2;
    int m = n / 4 - 1;
    if (m >= 1) { // 代表有中间部分
        mid = -4 * m;
        if (n % 4 == 0) {   // 如果整除 多减1
            mid -= 1;
        }
    }
    int tail = -ansTable[n % 4];
    return head + mid + tail;
}
