//
// Created by l30014168 on 2021/11/8.
//

int brokenCalc(int startValue, int target) {
    int ans = 0;
    while (startValue < target) {
        if ((target & 1) == 1) {
            target++;
            ans++;
        }
        target >>= 1;
        ans++;
    }
    ans += startValue - target;
    return ans;
}