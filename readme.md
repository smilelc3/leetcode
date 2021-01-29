# leetcode自由刷题——go版本

* 若无特殊说明，所给代码解法**均为时间最优解**，在某些题的代码中，包含多个可AC方法，最终也只采用最优时间解；
* 每个题单独创建以题名为命名的文件夹(package)，下含有源码与单元测试代码，均通过测试；
* 某些题目未给出时间复杂度，其原因多在于存在回溯操作，难以正确估计实际时间复杂度；
* 若题目对空间复杂度有明确要求，例如O(1)，所给代码均按照要求实现。

| 编号 | 题目 | 代码 | 时间复杂度 | 简述 |  空间复杂度 |
|:---:|:-----:|:---:|:---:|:---:|:---:|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | [two-sum.go](two-sum/two-sum.go) | O(n) | 哈希Map |  |
| 2 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [add-two-numbers.go](add-two-numbers/add-two-numbers.go) | O(n) | 单向链表 | |
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [longest-substring-without-repeating-characters.go](longest-substring-without-repeating-characters/longest-substring-without-repeating-characters.go) | O(n) | DP优化 | |
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [median-of-two-sorted-arrays.go](median-of-two-sorted-arrays/median-of-two-sorted-arrays.go) | O(log(min(m,n))) | 参考[Grandyang博客](https://www.cnblogs.com/grandyang/p/4465932.html) |  |
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | [longest-palindromic-substring.go](longest-palindromic-substring/longest-palindromic-substring.go) | O(n) | manacher算法 |  |
| 6 | [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/) | [zigzag-conversion.go](zigzag-conversion/zigzag-conversion.go) | O(n) | 规律总结 |  |
| 7 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [reverse-integer.go](reverse-integer/reverse-integer.go) | O(n) | strconv.Itoa()+strconv.Atoi()实现 |  |
| 8 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) | [string-to-integer-atoi.go](string-to-integer-atoi/string-to-integer-atoi.go) |  | 正则匹配 |  |
| 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | [palindrome-number.go](palindrome-number/palindrome-number.go) | O(n/2) | strconv.Itoa()实现 |  |
| 10 | [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | [regular-expression-matching.go](regular-expression-matching/regular-expression-matching.go) | O(n*m) | DP |  |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | [container-with-most-water.go](container-with-most-water/container-with-most-water.go) | O(n) | two-pointer算法 |  |
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | [integer-to-roman.go](integer-to-roman/integer-to-roman.go) | O(n) | 打表 |  |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | [roman-to-integer.go](roman-to-integer/roman-to-integer.go) | O(n) | switch-case |  |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | [longest-common-prefix.go](longest-common-prefix/longest-common-prefix.go) | O(n*m) | if模拟 |  |
| 15 | [3Sum](https://leetcode.com/problems/3sum/) | [3sum.go](3sum/3sum.go) | O(n^2) | two-pointer |  |
| 16 | [3Sum Closest](https://leetcode.com/problems/3sum-closest/) | [3sum-closest.go](3sum-closest/3sum-closest.go) | O(n^2) | two-pointer |  |
| 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | [letter-combinations-of-a-phone-number.go](letter-combinations-of-a-phone-number/letter-combinations-of-a-phone-number.go) | O(4^n) |  |  |
| 18 | [4Sum](https://leetcode.com/problems/4sum/) | [4sum.go](4sum/4sum.go) | O(n^3) | two-pointer |  |
| 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [remove-nth-node-from-end-of-list.go](remove-nth-node-from-end-of-list/remove-nth-node-from-end-of-list.go) | O(n) | 循环数组(one pass) |  |
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | [valid-parentheses.go](valid-parentheses/valid-parentheses.go) | O(n) | 栈 |  |
| 21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | [merge-two-sorted-lists.go](merge-two-sorted-lists/merge-two-sorted-lists.go) | O(m+n) | 递归 |  |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | [generate-parentheses.go](generate-parentheses/generate-parentheses.go) | O(2^n) | 递归 |  |
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | [merge-k-sorted-lists.go](merge-k-sorted-lists/merge-k-sorted-lists.go) | O(log(n)*m) | 分治 |  |
| 24 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) | [swap-nodes-in-pairs.go](swap-nodes-in-pairs/swap-nodes-in-pairs.go) | O(n) | 单链表交换节点 |  |
| 25 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) | [reverse-nodes-in-k-group.go](reverse-nodes-in-k-group/reverse-nodes-in-k-group.go) | O(n) | 记录前驱+后驱节点 | O(1) |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [remove-duplicates-from-sorted-array.go](remove-duplicates-from-sorted-array/remove-duplicates-from-sorted-array.go) | O(n) | slice传参：带地址的结构体值 | O(1) |
| 27 | [Remove Element](https://leetcode.com/problems/remove-element/) | [remove-element.go](remove-element/remove-element.go) | O(n) |  | O(1) |
| 28 | [Implement strStr()](https://leetcode.com/problems/implement-strstr/) | [implement-strstr.go](implement-strstr/implement-strstr.go) | O(n+m) | KMP算法 |  |
| 29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | [divide-two-integers.go](divide-two-integers/divide-two-integers.go) | O(log(n)) | 位操作实现除法 |  |
| 30 | [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) | [substring-with-concatenation-of-all-words.go](substring-with-concatenation-of-all-words/substring-with-concatenation-of-all-words.go) | O(n) | 滑动窗口+HashMap |  |
| 31 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | [next-permutation_test.go](next-permutation/next-permutation_test.go) | O(n) | 参考C++ [std::next_next_permutation](https://en.cppreference.com/w/cpp/algorithm/next_permutation) | O(1) |
| 32 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) | [longest-valid-parentheses.go](longest-valid-parentheses/longest-valid-parentheses.go) | O(n) | 栈 |  |
| 33 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [search-in-rotated-sorted-array.go](search-in-rotated-sorted-array/search-in-rotated-sorted-array.go) | O(log(n)) | 二分查找 |  |
| 34 | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [find-first-and-last-position-of-element-in-sorted-array.go](find-first-and-last-position-of-element-in-sorted-array/find-first-and-last-position-of-element-in-sorted-array.go) | O(log(n)) | 二分查找 |  |
| 35 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [search-insert-position.go](search-insert-position/search-insert-position.go) | O(log(n)) | 二分查找 |  |
| 36 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | [valid-sudoku.go](valid-sudoku/valid-sudoku.go) | O(n^2) | 位操作判重 |  |
| 37 | [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | [sudoku-solver.go](sudoku-solver/sudoku-solver.go) |  | DanceLink X算法，来自本人项目[sudoku-solver](https://github.com/smilelc3/sudoku-solver) |  |
| 38 | [Count and Say](https://leetcode.com/problems/count-and-say/) | [count-and-say.go](count-and-say/count-and-say.go) |  | 递归 + strings.Builder加速 |  |
| 39 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | [combination-sum.go](combination-sum/combination-sum.go) |  | DFS |  |
| 40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | [combination-sum-ii.go](combination-sum-ii/combination-sum-ii.go) |  | DFS+剪枝 |  |
| 41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | [first-missing-positive.go](first-missing-positive/first-missing-positive.go) | O(n) | 判 nums[idx]=nums[nums[idx]-1] | O(1) |
| 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | [trapping-rain-water.go](trapping-rain-water/trapping-rain-water.go) | O(n) | 不下降子数组 |  |
| 43 | [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | [multiply-strings.go](multiply-strings/multiply-strings.go) | O(n+m) | 模拟乘法 |  |
| 44 | [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) | [wildcard-matching.go](wildcard-matching/wildcard-matching.go) | O(n) | 双指针 |  |
| 45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | [jump-game-ii.go](jump-game-ii/jump-game-ii.go) | O(n) | 二次扩展 | O(1) |
| 46 | [Permutations](https://leetcode.com/problems/permutations/) | [permutations.go](permutations/permutations.go) | O(n!) | 全排列 |  |
| 47 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | [permutations-ii.go](permutations-ii/permutations-ii.go) |  | 不重复全排列 |  |
| 48 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | [rotate-image.go](rotate-image/rotate-image.go) | O(n^2) | 图像处理：旋转变换矩阵 | O(1) |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | [group-anagrams.go](group-anagrams/group-anagrams.go) | O(m*n) | HashMap+桶排序思想 |  |
| 50 | [Pow(x, n)](https://leetcode.com/problems/powx-n/) | [powx-n.go](powx-n/powx-n.go) | O(log(n)) | 快速幂 |  |
| 51 | [N-Queens](https://leetcode.com/problems/n-queens/) | [n-queens.go](n-queens/n-queens.go) | O(n^n) | 回溯+位操作加速 |  |
| 52 | [N-Queens II](https://leetcode.com/problems/n-queens-ii/) | [n-queens-ii.go](n-queens-ii/n-queens-ii.go) | O(1) | 打表 | O(1) |
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | [maximum-subarray.go](maximum-subarray/maximum-subarray.go) | O(n) | 最大和子串 | O(1) |
| 54 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | [spiral-matrix.go](spiral-matrix/spiral-matrix.go) | O(m*n) | 模拟 |  |
| 55 | [Jump Game](https://leetcode.com/problems/jump-game/) | [jump-game.go](jump-game/jump-game.go) | O(n) | 二次扩展 | O(1) |
| 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | [merge-intervals.go](merge-intervals/merge-intervals.go) | O(nlog(n)) | slice排序 |  |
| 57 | [Insert Interval](https://leetcode.com/problems/insert-interval/) | [insert-interval.go](insert-interval/insert-interval.go) | O(n) | 模拟 |  |
| 58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word/) | [length-of-last-word.go](length-of-last-word/length-of-last-word.go) | O(n) | 找首次非后导空格符 |  |
| 59 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | [spiral-matrix-ii.go](spiral-matrix-ii/spiral-matrix-ii.go) | O(n^2) | 模拟 |  |
| 60 | [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | [permutation-sequence.go](permutation-sequence/permutation-sequence.go) | O(n) | 规律+递归 |  |
| 61 | [Rotate List](https://leetcode.com/problems/rotate-list/) | [rotate-list.go](rotate-list/rotate-list.go) | O(n) | 旋转单链表 | O(1) |
| 62 | [Unique Paths](https://leetcode.com/problems/unique-paths/) | [unique-paths.go](unique-paths/unique-paths.go) | O(m*n) | DP | O(min(m,n)) |
| 63 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | [unique-paths-ii.go](unique-paths-ii/unique-paths-ii.go) | O(m*n) | DP | O(min(m,n)) |
| 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | [minimum-path-sum.go](minimum-path-sum/minimum-path-sum.go) | O(m*n) | DP |  |
| 65 | [Valid Number](https://leetcode.com/problems/valid-number/) | [valid-number.go](valid-number/valid-number.go) | O(n) | 确定有限状态自动机DFA |  |
| 66 | [Plus One](https://leetcode.com/problems/plus-one/) | [plus-one.go](plus-one/plus-one.go) | O(n) | 模拟进位 |  |
| 67 | [Add Binary](https://leetcode.com/problems/add-binary/) | [add-binary.go](add-binary/add-binary.go) | O(n) | 模拟二进制加法 |  |
| 68 | [Text Justification](https://leetcode.com/problems/text-justification/) | [text-justification.go](text-justification/text-justification.go) | O(m*n) | 格式控制 |  |
| 69 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | [sqrtx.go](sqrtx/sqrtx.go) | O(log(n)) | 二叉搜索树 | O(1) |
