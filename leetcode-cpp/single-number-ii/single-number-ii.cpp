//
// Created by smile on 2021/3/17.
//
# include <vector>

class Solution {
public:
    static int singleNumber(std::vector<int> &nums) {
        int once = 0, twice = 0;
        for (auto num: nums) {
            once = (once ^ num) & ~twice;
            twice = (twice ^ num) & ~once;
        }
        return once;
    }
};