//
// Created by smile on 2022/2/9.
//

#include <string>
#include <array>

class Solution {
public:
    static bool isIsomorphic(const std::string &s, const std::string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::array<unsigned char, 128> charMap{};
        charMap.fill(UNDEF_CHAR_MAP);
        for (size_t i = 0; i < s.size(); ++i) {
            if (charMap[s[i]] == UNDEF_CHAR_MAP) {
                charMap[s[i]] = t[i];
            } else if (charMap[s[i]] != t[i]) {
                return false;
            }
        }
        charMap.fill(UNDEF_CHAR_MAP);
        for (size_t i = 0; i < t.size(); ++i) {
            if (charMap[t[i]] == UNDEF_CHAR_MAP) {
                charMap[t[i]] = s[i];
            } else if (charMap[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }

    static const unsigned char UNDEF_CHAR_MAP;

};

const unsigned char Solution::UNDEF_CHAR_MAP = 0xFF;
static_assert(Solution::UNDEF_CHAR_MAP >= std::numeric_limits<unsigned char>::max(), "UNDEF_CHAR_MAP must >= 255");