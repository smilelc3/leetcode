//
// Created by smile on 2022/1/1.
//

#include <vector>
#include <list>

class Solution {
public:
    static int findTheWinner(int n, int k) {
        return findTheWinnerDpMethod(n, k);
    }
    static int findTheWinnerVectorSimMethod(int n, int k) {
        std::vector<int> loop;
        loop.reserve(n);
        for (int i = 1; i <= n; ++i) {
            loop.emplace_back(i);
        }
        auto iter = loop.begin();
        auto remainK = k;
        while (loop.size() > 1) {
            if (iter == loop.end()) {
                iter = loop.begin();
            }
            if (remainK == 1) {     // 移除元素，导致迭代器指向元素变更，size 减小
                iter = loop.erase(iter);
                remainK = k;
            } else {
                iter++;
                remainK--;
            }
        }
        return loop.front();
    }

    static int findTheWinnerVectorSkipMethod(int n, int k) {
        std::vector<int> loop;
        loop.reserve(n);
        for (int i = 1; i <= n; ++i) {
            loop.emplace_back(i);
        }
        auto iter = loop.begin();
        while (loop.size() > 1) {
            auto remainLen = loop.end() - iter - 1;
            auto remainStep = decltype(remainLen)((k - 1) % loop.size());
            iter = remainStep > remainLen ? loop.begin() + remainStep - remainLen - 1 : iter + remainStep;
            iter = loop.erase(iter);
            if (iter == loop.end()) {       // 如果删除最后一个，跳回开始
                iter = loop.begin();
            }
        }
        return loop.front();
    }

    static int findTheWinnerLinkSkipMethod(int n, int k) {
        std::list<int> loop;
        for (int i = 1; i <= n; ++i) {
            loop.emplace_back(i);
        }
        auto iter = loop.begin();
        while (loop.size() > 1) {
            auto remainStep = (k - 1) % loop.size();
            while (remainStep > 0) {
                iter++;
                remainStep--;
                if (iter == loop.end()) {       // 跳回开始
                    iter = loop.begin();
                }
            }
            iter = loop.erase(iter);
            if (iter == loop.end()) {       // 跳回开始
                iter = loop.begin();
            }
        }
        return loop.front();
    }

    static int findTheWinnerDpMethod(int n, int k) {
        // dp[n] 表示每次跳k步，有n个人的最终幸存者编号
        // 若已知n-1人的幸存者编号为dp[n-1]，整体编号为1, 2 ... n-2, n-1; (eq1)
        // 复盘n人的情况，编号为1, 2 ... n-1, n, 会删除第k个人，剩余为 1, 2 ... k-1, k+1 ... n-1, n;
        // 这时候进行下一轮会重新编号把k+1当作新的第一位，整体编号为k+1, k+2, ... n, 1 ... k-1; (eq2)
        // eq2这时候与eq1等价，整体偏移k位，若超出n对n取余数。例如原始最后一位 n-1 = (n-1 + k) % n = k-1
        // 需要特殊注意下偏移k位刚好等于n的情况，此时结果应该为n，修正一下转换方程 f(n) = (f(n-1) + k-1) % n + 1
        // 则若n-1人的幸存者编号为dp[n-1]，那么dp[n] = (dp[n-1] + k - 1) % n + 1
        // 又因为dp[n]只与dp[n-1]有关，可以压缩
        int ans = 1;    // n=1时答案
        for (int i = 2; i <= n; ++i) {
            ans = (ans + k - 1) % i + 1;
        }
        return ans;
    }
};