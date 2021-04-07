//
// Created by smile on 2021/3/17.
//
# include <vector>

class Solution {
public:
    /*
     * 我们把数组中数字的每一位累加起来对3取余，剩下的结果就是那个单独数组该位上的数字，
     * 由于累加的过程都要对3取余，那么每一位上累加的过程就是 0->1->2->0，
     * 换成二进制的表示为 00->01->10->00，可以写出对应关系：
     *
     * 00 (+) 1 = 01
     * 01 (+) 1 = 10
     * 10 (+) 1 = 00 ( mod 3)
     *
     * 用 ab 来表示开始的状态，对于加1操作后，得到的新状态的 ab 的算法如下：
     * b = b xor r & ~a;
     * a = a xor r & ~b;
     * 这里的 ab 就是上面的三种状态 00，01，10 的十位和个位，
     * 刚开始的时候，a和b都是0，当此时遇到数字1的时候，b更新为1，a更新为0，就是 01 的状态；
     * 再次遇到1的时候，b更新为0，a更新为1，就是 10 的状态；
     * 再次遇到1的时候，b更新为0，a更新为0，就是 00 的状态，相当于重置了；
     * 最后的结果保存在b中。
     */
    static int singleNumber(std::vector<int> &nums) {
        int once = 0, twice = 0;
        for (auto num: nums) {
            once = (once ^ num) & ~twice;
            twice = (twice ^ num) & ~once;
        }
        return once;
    }
};

