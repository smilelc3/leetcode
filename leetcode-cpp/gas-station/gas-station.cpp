//
// Created by smile on 2021/4/29.
//
#include <vector>

/*
    如果一个数组的总和非负，那么一定可以找到一个起始位置，从他开始绕数组一圈，累加和一直都是非负的
    现象：
        1. 假如从位置i开始，i+1，i+2...，一路开过来一路油箱都没有空。说明什么？说明从i到i+1，i+2，...肯定是正积累。
        2. 现在突然发现开往位置j时油箱空了。这说明什么？说明从位置i开始没法走完全程。
        但不需要从位置i+1开始重新尝试，因为前面已经知道，位置i肯定是正积累，如果从位置i+1开始走更加没法走完全程了，因为没有位置i的正积累了。
        同理，也不用从i+2，i+3，...开始尝试。所以我们可以放心地从位置j+1开始尝试。
 */
class Solution {
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        int startIdx = 0;       // 起始位置
        int debtGas = 0;        // 前面的路欠的汽油
        int remainGas = 0;      // 当前剩余汽油

        for (auto idx = 0; idx < gas.size(); idx++) {
            remainGas += gas[idx] - cost[idx];
            if (remainGas < 0) {
                debtGas += remainGas;
                startIdx = idx + 1;
                remainGas = 0;
            }
        }
        return remainGas + debtGas >= 0 ? startIdx : -1;
    }
};