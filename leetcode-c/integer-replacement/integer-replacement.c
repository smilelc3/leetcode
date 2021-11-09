//
// Created by l30014168 on 2021/11/9.
//

int integerReplacementUint(uint32_t n) {
    int cnt = 0;
    while (n > 3) {
        if ((n & 1) == 1) {
            if ((n & 3) == 3) {     // 尽可能将末尾二进制归0
                n++;
            } else {
                n--;
            }
            cnt++;
        }
        n >>= 1;
        cnt++;
    }
    if (n == 3) {
        cnt += 2;
    } else if (n == 2) {
        cnt += 1;
    }
    return cnt;
}

int integerReplacement(int n) {
    return integerReplacementUint(n);
}