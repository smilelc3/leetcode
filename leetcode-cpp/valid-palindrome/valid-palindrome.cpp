//
// Created by smile on 2021/4/9.
//
#include <string>


class Solution {
public:
    static bool isPalindrome(const std::string &s) {
        bool ans = true;
        if (s.empty()) {
            return ans;
        }
        int64_t left = 0, right = s.length() - 1;
        while (left < right) {
            if (not(isalpha(s[left]) or isalnum(s[left]))) {
                left++;
                continue;
            }
            if (not(isalpha(s[right]) or isalnum(s[right]))) {
                right--;
                continue;
            }
            if (std::tolower(s[left]) == std::tolower(s[right])) {  // digital or letter
                left++;
                right--;
            } else {
                ans = false;
                break;
            }
        }

        return ans;
    }
};