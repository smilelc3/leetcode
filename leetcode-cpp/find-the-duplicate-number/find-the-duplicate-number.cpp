//
// Created by l30014168 on 2022/3/22.
//

#include <vector>

class Solution {
public:
    static int findDuplicate(std::vector<int> &nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};