//
// Created by smile on 2022/1/9.
//

#include <string>
#include <vector>

class Solution {
public:
    static std::string simplifyPath(const std::string &path) {
        std::vector<std::pair<size_t, size_t>> dirStack; // 存储目录的栈，内容为：开始位置和长度
        size_t start = 0, end = 0;
        while (start < path.size()) {
            if (end == path.size() or path[end] == '/') {
                auto length = end - start;
                if (length == 2 and path.substr(start, length) == "..") {
                    if (not dirStack.empty()) {
                        dirStack.pop_back();
                    }
                } else if (length > 0 and not(length == 1 and path[start] == '.')) {
                    dirStack.emplace_back(std::make_pair(start, length));
                }
                start = end + 1;
            }
            end++;
        }
        if (dirStack.empty()) {
            return "/";
        }
        std::string ans;
        ans.reserve(path.size());
        // 从栈底遍历到栈顶
        for (const auto &item: dirStack) {
            ans += '/' + path.substr(item.first, item.second);
        }
        return ans;
    }
};