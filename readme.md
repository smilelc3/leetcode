# leetcode自由刷题

## 说明
* 代码由C++14或者golang编写，可根据文件后缀判断。C++单元测试使用[Gtest](https://github.com/google/googletest)框架，go单元测试使用自带test工具；
* 全部代码解法**均为时间最优解**，在某些题的代码中，包含多个可AC方法，最终也只采用最优时间解；
* 每个题单独创建以题名为命名的文件夹(package)，下含有源码与单元测试代码，均通过测试；
* 某些题目未给出时间复杂度，其原因多在于存在回溯操作，难以正确估计实际时间复杂度；
* 若题目对空间复杂度有明确要求，例如O(1)，所给代码均按照要求实现。

## 汇总表

| 编号 | 题目 | 代码 | 时间复杂度 | 简述 |  空间复杂度 |
|:---:|:-----:|:---:|:---:|:---:|:---:|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | [two-sum.go](leetcode-go/two-sum/two-sum.go) | O(n) | 哈希Map |  |
| 2 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [add-two-numbers.go](leetcode-go/add-two-numbers/add-two-numbers.go) | O(n) | 单向链表 | |
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [longest-substring-without-repeating-characters.go](leetcode-go/longest-substring-without-repeating-characters/longest-substring-without-repeating-characters.go) | O(n) | DP优化 | |
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [median-of-two-sorted-arrays.go](leetcode-go/median-of-two-sorted-arrays/median-of-two-sorted-arrays.go) | O(log(min(m,n))) | 参考[Grandyang博客](https://www.cnblogs.com/grandyang/p/4465932.html) |  |
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | [longest-palindromic-substring.go](leetcode-go/longest-palindromic-substring/longest-palindromic-substring.go) | O(n) | manacher算法 |  |
| 6 | [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/) | [zigzag-conversion.go](leetcode-go/zigzag-conversion/zigzag-conversion.go) | O(n) | 规律总结 |  |
| 7 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [reverse-integer.go](leetcode-go/reverse-integer/reverse-integer.go) | O(n) | strconv.Itoa()+strconv.Atoi()实现 |  |
| 8 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) | [string-to-integer-atoi.go](leetcode-go/string-to-integer-atoi/string-to-integer-atoi.go) |  | 正则匹配 |  |
| 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | [palindrome-number.go](leetcode-go/palindrome-number/palindrome-number.go) | O(n/2) | strconv.Itoa()实现 |  |
| 10 | [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | [regular-expression-matching.go](leetcode-go/regular-expression-matching/regular-expression-matching.go) | O(n*m) | DP |  |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | [container-with-most-water.go](leetcode-go/container-with-most-water/container-with-most-water.go) | O(n) | two-pointer算法 |  |
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | [integer-to-roman.go](leetcode-go/integer-to-roman/integer-to-roman.go) | O(n) | 打表 |  |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | [roman-to-integer.go](leetcode-go/roman-to-integer/roman-to-integer.go) | O(n) | switch-case |  |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | [longest-common-prefix.go](leetcode-go/longest-common-prefix/longest-common-prefix.go) | O(n*m) | if模拟 |  |
| 15 | [3Sum](https://leetcode.com/problems/3sum/) | [3sum.go](leetcode-go/3sum/3sum.go) | O(n^2) | two-pointer |  |
| 16 | [3Sum Closest](https://leetcode.com/problems/3sum-closest/) | [3sum-closest.go](leetcode-go/3sum-closest/3sum-closest.go) | O(n^2) | two-pointer |  |
| 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | [letter-combinations-of-a-phone-number.go](leetcode-go/letter-combinations-of-a-phone-number/letter-combinations-of-a-phone-number.go) | O(4^n) | 循环 |  |
| 18 | [4Sum](https://leetcode.com/problems/4sum/) | [4sum.go](leetcode-go/4sum/4sum.go) | O(n^3) | two-pointer |  |
| 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [remove-nth-node-from-end-of-list.go](leetcode-go/remove-nth-node-from-end-of-list/remove-nth-node-from-end-of-list.go) | O(n) | 循环数组(one pass) |  |
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | [valid-parentheses.go](leetcode-go/valid-parentheses/valid-parentheses.go) | O(n) | 栈 |  |
| 21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | [merge-two-sorted-lists.go](leetcode-go/merge-two-sorted-lists/merge-two-sorted-lists.go) | O(m+n) | 递归 |  |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | [generate-parentheses.go](leetcode-go/generate-parentheses/generate-parentheses.go) | O(2^n) | 递归 |  |
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | [merge-k-sorted-lists.go](leetcode-go/merge-k-sorted-lists/merge-k-sorted-lists.go) | O(log(n)*m) | 分治 |  |
| 24 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) | [swap-nodes-in-pairs.go](leetcode-go/swap-nodes-in-pairs/swap-nodes-in-pairs.go) | O(n) | 单链表交换节点 |  |
| 25 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) | [reverse-nodes-in-k-group.go](leetcode-go/reverse-nodes-in-k-group/reverse-nodes-in-k-group.go) | O(n) | 记录前驱+后驱节点 | O(1) |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [remove-duplicates-from-sorted-array.go](leetcode-go/remove-duplicates-from-sorted-array/remove-duplicates-from-sorted-array.go) | O(n) | slice传参：带地址的结构体值 | O(1) |
| 27 | [Remove Element](https://leetcode.com/problems/remove-element/) | [remove-element.go](leetcode-go/remove-element/remove-element.go) | O(n) | 单链表删除操作 | O(1) |
| 28 | [Implement strStr()](https://leetcode.com/problems/implement-strstr/) | [implement-strstr.go](leetcode-go/implement-strstr/implement-strstr.go) | O(n+m) | KMP算法 |  |
| 29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | [divide-two-integers.go](leetcode-go/divide-two-integers/divide-two-integers.go) | O(log(n)) | 位操作实现除法 |  |
| 30 | [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) | [substring-with-concatenation-of-all-words.go](leetcode-go/substring-with-concatenation-of-all-words/substring-with-concatenation-of-all-words.go) | O(n) | 滑动窗口+HashMap |  |
| 31 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | [next-permutation_test.go](leetcode-go/next-permutation/next-permutation.go) | O(n) | 参考C++ [std::next_next_permutation](https://en.cppreference.com/w/cpp/algorithm/next_permutation) | O(1) |
| 32 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) | [longest-valid-parentheses.go](leetcode-go/longest-valid-parentheses/longest-valid-parentheses.go) | O(n) | 栈 |  |
| 33 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [search-in-rotated-sorted-array.go](leetcode-go/search-in-rotated-sorted-array/search-in-rotated-sorted-array.go) | O(log(n)) | 二分查找 |  |
| 34 | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [find-first-and-last-position-of-element-in-sorted-array.go](leetcode-go/find-first-and-last-position-of-element-in-sorted-array/find-first-and-last-position-of-element-in-sorted-array.go) | O(log(n)) | 二分查找 |  |
| 35 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [search-insert-position.go](leetcode-go/search-insert-position/search-insert-position.go) | O(log(n)) | 二分查找 |  |
| 36 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | [valid-sudoku.go](leetcode-go/valid-sudoku/valid-sudoku.go) | O(n^2) | 位操作判重 |  |
| 37 | [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | [sudoku-solver.go](leetcode-go/sudoku-solver/sudoku-solver.go) |  | DanceLink X算法，来自本人项目[sudoku-solver](https://github.com/smilelc3/sudoku-solver) |  |
| 38 | [Count and Say](https://leetcode.com/problems/count-and-say/) | [count-and-say.go](leetcode-go/count-and-say/count-and-say.go) |  | 递归 + strings.Builder加速 |  |
| 39 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | [combination-sum.go](leetcode-go/combination-sum/combination-sum.go) |  | DFS |  |
| 40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | [combination-sum-ii.go](leetcode-go/combination-sum-ii/combination-sum-ii.go) |  | DFS+剪枝 |  |
| 41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | [first-missing-positive.go](leetcode-go/first-missing-positive/first-missing-positive.go) | O(n) | 判 nums[idx]=nums[nums[idx]-1] | O(1) |
| 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | [trapping-rain-water.go](leetcode-go/trapping-rain-water/trapping-rain-water.go) | O(n) | 不下降子数组 |  |
| 43 | [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | [multiply-strings.go](leetcode-go/multiply-strings/multiply-strings.go) | O(n+m) | 模拟乘法 |  |
| 44 | [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) | [wildcard-matching.go](leetcode-go/wildcard-matching/wildcard-matching.go) | O(n) | 双指针 |  |
| 45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | [jump-game-ii.go](leetcode-go/jump-game-ii/jump-game-ii.go) | O(n) | 二次扩展 | O(1) |
| 46 | [Permutations](https://leetcode.com/problems/permutations/) | [permutations.go](leetcode-go/permutations/permutations.go) | O(n!) | 全排列 |  |
| 47 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | [permutations-ii.go](leetcode-go/permutations-ii/permutations-ii.go) |  | 不重复全排列 |  |
| 48 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | [rotate-image.go](leetcode-go/rotate-image/rotate-image.go) | O(n^2) | 图像处理：旋转变换矩阵 | O(1) |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | [group-anagrams.go](leetcode-go/group-anagrams/group-anagrams.go) | O(m*n) | HashMap+桶排序思想 |  |
| 50 | [Pow(x, n)](https://leetcode.com/problems/powx-n/) | [powx-n.go](leetcode-go/powx-n/powx-n.go) | O(log(n)) | 快速幂 |  |
| 51 | [N-Queens](https://leetcode.com/problems/n-queens/) | [n-queens.go](leetcode-go/n-queens/n-queens.go) | O(n^n) | 回溯+位操作加速 |  |
| 52 | [N-Queens II](https://leetcode.com/problems/n-queens-ii/) | [n-queens-ii.go](leetcode-go/n-queens-ii/n-queens-ii.go) | O(1) | 打表 | O(1) |
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | [maximum-subarray.go](leetcode-go/maximum-subarray/maximum-subarray.go) | O(n) | 最大和子串 | O(1) |
| 54 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | [spiral-matrix.go](leetcode-go/spiral-matrix/spiral-matrix.go) | O(m*n) | 模拟 |  |
| 55 | [Jump Game](https://leetcode.com/problems/jump-game/) | [jump-game.go](leetcode-go/jump-game/jump-game.go) | O(n) | 二次扩展 | O(1) |
| 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | [merge-intervals.go](leetcode-go/merge-intervals/merge-intervals.go) | O(nlog(n)) | slice排序 |  |
| 57 | [Insert Interval](https://leetcode.com/problems/insert-interval/) | [insert-interval.go](leetcode-go/insert-interval/insert-interval.go) | O(n) | 模拟 |  |
| 58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word/) | [length-of-last-word.go](leetcode-go/length-of-last-word/length-of-last-word.go) | O(n) | 找首次非后导空格符 |  |
| 59 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | [spiral-matrix-ii.go](leetcode-go/spiral-matrix-ii/spiral-matrix-ii.go) | O(n^2) | 模拟 |  |
| 60 | [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | [permutation-sequence.go](leetcode-go/permutation-sequence/permutation-sequence.go) | O(n) | 规律+递归 |  |
| 61 | [Rotate List](https://leetcode.com/problems/rotate-list/) | [rotate-list.go](leetcode-go/rotate-list/rotate-list.go) | O(n) | 旋转单链表 | O(1) |
| 62 | [Unique Paths](https://leetcode.com/problems/unique-paths/) | [unique-paths.go](leetcode-go/unique-paths/unique-paths.go) | O(m*n) | DP+滚动数组 | O(min(m,n)) |
| 63 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | [unique-paths-ii.go](leetcode-go/unique-paths-ii/unique-paths-ii.go) | O(m*n) | DP+滚动数组 | O(min(m,n)) |
| 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | [minimum-path-sum.go](leetcode-go/minimum-path-sum/minimum-path-sum.go) | O(m*n) | DP |  |
| 65 | [Valid Number](https://leetcode.com/problems/valid-number/) | [valid-number.go](leetcode-go/valid-number/valid-number.go) | O(n) | 确定有限状态自动机DFA | O(1) |
| 66 | [Plus One](https://leetcode.com/problems/plus-one/) | [plus-one.go](leetcode-go/plus-one/plus-one.go) | O(n) | 模拟进位 |  |
| 67 | [Add Binary](https://leetcode.com/problems/add-binary/) | [add-binary.go](leetcode-go/add-binary/add-binary.go) | O(n) | 模拟二进制加法 |  |
| 68 | [Text Justification](https://leetcode.com/problems/text-justification/) | [text-justification.go](leetcode-go/text-justification/text-justification.go) | O(m*n) | 格式控制 |  |
| 69 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | [sqrtx.go](leetcode-go/sqrtx/sqrtx.go) | O(log(n)) | 二叉搜索树 | O(1) |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | [climbing-stairs.go](leetcode-go/climbing-stairs/climbing-stairs.go) | O(n) | 斐波那契数列(递推) | O(1) |
| 71 | [Simplify Path](https://leetcode.com/problems/simplify-path/) | [simplify-path.go](leetcode-go/simplify-path/simplify-path.go) | O(n) | 栈 |  |
| 72 | [Edit Distance](https://leetcode.com/problems/edit-distance/) | [edit-distance.go](leetcode-go/edit-distance/edit-distance.go) | O(m*n) | 编辑距离DP | O(m*n) |
| 73 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) | [set-matrix-zeroes.go](leetcode-go/set-matrix-zeroes/set-matrix-zeroes.go) | O(m*n) | 表头标记 | O(1) |
| 74 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) | [search-a-2d-matrix.go](leetcode-go/search-a-2d-matrix/search-a-2d-matrix.go) | O(log(m*n)) | 二分查找 | O(1) |
| 75 | [Sort Colors](https://leetcode.com/problems/sort-colors/) | [sort-colors.go](leetcode-go/sort-colors/sort-colors.go) | O(n) | 桶排序 | O(1) |
| 76 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | [minimum-window-substring.go](leetcode-go/minimum-window-substring/minimum-window-substring.go) | O(n) | 滑动窗口+数组代替HashMap优化 |  |
| 77 | [Combinations](https://leetcode.com/problems/combinations/) | [combinations.go](leetcode-go/combinations/combinations.go) | O((n-k)!) | 排列：递归 |  |
| 78 | [Subsets](https://leetcode.com/problems/subsets/) | [subsets.go](leetcode-go/subsets/subsets.go) | O(2^n) | 全子集：递归 |  |
| 79 | [Word Search](https://leetcode.com/problems/word-search/) | [word-search.go](leetcode-go/word-search/word-search.go) |  | DFS |  |
| 80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [remove-duplicates-from-sorted-array-ii.go](leetcode-go/remove-duplicates-from-sorted-array-ii/remove-duplicates-from-sorted-array-ii.go) | O(n) | 遍历 | O(1) |
| 81 | [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | [search-in-rotated-sorted-array-ii.go](leetcode-go/search-in-rotated-sorted-array-ii/search-in-rotated-sorted-array-ii.go) | O(n) | 二分搜索 |  |
| 82 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | [remove-duplicates-from-sorted-list-ii.go](leetcode-go/remove-duplicates-from-sorted-list-ii/remove-duplicates-from-sorted-list-ii.go) | O(n) | 维护单链表preNode |  |
| 83 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) | [remove-duplicates-from-sorted-list.go](leetcode-go/remove-duplicates-from-sorted-list/remove-duplicates-from-sorted-list.go) | O(n) | 保证pNode.Val != pNode.Next.Val |  |
| 84 | [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) | [largest-rectangle-in-histogram.go](leetcode-go/largest-rectangle-in-histogram/largest-rectangle-in-histogram.go) | O(n) | 单调栈 |  |
| 85 | [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) | [maximal-rectangle.go](leetcode-go/maximal-rectangle/maximal-rectangle.go) | O(m*n) | 转换为直方图求最大矩形：单调栈 |  |
| 86 | [Partition List](https://leetcode.com/problems/partition-list/) | [partition-list.go](leetcode-go/partition-list/partition-list.go) | O(n) | 双指针 | O(1) |
| 87 | [Scramble String](https://leetcode.com/problems/scramble-string/) | [scramble-string.go](leetcode-go/scramble-string/scramble-string.go) |  | 分治 |  |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | [merge-sorted-array.go](leetcode-go/merge-sorted-array/merge-sorted-array.go) | O(n) | 从后向前遍历 |  |
| 89 | [Gray Code](https://leetcode.com/problems/gray-code/) | [gray-code.go](leetcode-go/gray-code/gray-code.go) [gray-code.cpp](leetcode-cpp/gray-code/gray-code.cpp) | O(2^n) | 格雷码 |  |
| 90 | [Subsets II](https://leetcode.com/problems/subsets-ii/) | [subsets-ii.go](leetcode-go/subsets-ii/subsets-ii.go) | O(2^n) | 去重全子集：递归 |  |
| 91 | [Decode Ways](https://leetcode.com/problems/decode-ways/) | [decode-ways.go](leetcode-go/decode-ways/decode-ways.go) | O(n) | 斐波那契变形+滚动数组 | O(1) |
| 92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) | [reverse-linked-list-ii.go](leetcode-go/reverse-linked-list-ii/reverse-linked-list-ii.go) | O(n) |  单链表部分翻转 | O(1) |
| 93 | [Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/) | [restore-ip-addresses.go](leetcode-go/restore-ip-addresses/restore-ip-addresses.go) |  |  DFS |  |
| 94 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | [binary-tree-inorder-traversal.go](leetcode-go/binary-tree-inorder-traversal/binary-tree-inorder-traversal.go) | O(N) | 中序遍历(Morris遍历) | O(1) |
| 95 | [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/) | [unique-binary-search-trees-ii.go](leetcode-go/unique-binary-search-trees-ii/unique-binary-search-trees-ii.go) |  | 异构二叉搜索树 |  |
| 96 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/) | [unique-binary-search-trees.go](leetcode-go/unique-binary-search-trees/unique-binary-search-trees.go) | O(1) | 卡特兰数 | O(1) |
| 97 | [Interleaving String](https://leetcode.com/problems/interleaving-string/) | [interleaving-string.go](leetcode-go/interleaving-string/interleaving-string.go) | O(mn) | DP+滚动数组+状态压缩 | O(1) |
| 98 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | [validate-binary-search-tree.go](leetcode-go/validate-binary-search-tree/validate-binary-search-tree.go) | O(n) | 判定二叉搜索树 |  |
| 99 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) | [recover-binary-search-tree.go](leetcode-go/recover-binary-search-tree/recover-binary-search-tree.go) | O(n) | Morris中序遍历 | O(1) |
| 100 | [Same Tree](https://leetcode.com/problems/same-tree/) | [same-tree.go](leetcode-go/same-tree/same-tree.go) | O(n) | 树的遍历 |  |
| 101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) | [symmetric-tree.go](leetcode-go/symmetric-tree/symmetric-tree.go) | O(n) | 相同层子树递归比较 | O(n) |
| 102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | [binary-tree-level-order-traversal.go](leetcode-go/binary-tree-level-order-traversal/binary-tree-level-order-traversal.go) | O(n) | 二叉树层级遍历 | O(log(n)) |
| 103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) | [binary-tree-zigzag-level-order-traversal.go](leetcode-go/binary-tree-zigzag-level-order-traversal/binary-tree-zigzag-level-order-traversal.go) | O(n) | 二叉树层级遍历 | O(log(n)) |
| 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | [maximum-depth-of-binary-tree.go](leetcode-go/maximum-depth-of-binary-tree/maximum-depth-of-binary-tree.go) | O(n) | DFS+BFS | O(n) |
| 105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [construct-binary-tree-from-preorder-and-inorder-traversal.cpp](leetcode-cpp/construct-binary-tree-from-preorder-and-inorder-traversal/construct-binary-tree-from-preorder-and-inorder-traversal.cpp) | O(n) | 先序+中序构造二叉树 | O(n) |
| 106 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | [construct-binary-tree-from-inorder-and-postorder-traversal.cpp](leetcode-cpp/construct-binary-tree-from-inorder-and-postorder-traversal/construct-binary-tree-from-inorder-and-postorder-traversal.cpp) | O(n) | 中序+后序构造二叉树 | O(n) |
| 107 | [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) | [binary-tree-level-order-traversal-ii.cpp](leetcode-cpp/binary-tree-level-order-traversal-ii/binary-tree-level-order-traversal-ii.cpp) | O(n) | BFS | O(n) |
| 110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | [balanced-binary-tree.cpp](leetcode-cpp/balanced-binary-tree/balanced-binary-tree.cpp) | O(n) | 判平衡二叉树：递归 |  |
| 111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/) | [minimum-depth-of-binary-tree.cpp](leetcode-cpp/minimum-depth-of-binary-tree/minimum-depth-of-binary-tree.cpp) |       O(n)       | 二叉树最小深度：DFS+剪枝 | |
| 112 | [Path Sum](https://leetcode.com/problems/path-sum/) | [path-sum.cpp](leetcode-cpp/path-sum-ii/path-sum-ii.cpp) | O(n) | DFS遍历树 | |
| 118 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | [pascals-triangle.cpp](leetcode-cpp/pascals-triangle/pascals-triangle.cpp) | O(n^2) | 构建帕斯卡三角 | O(n^2) |
| 119 | [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) | [pascals-triangle-ii.cpp](leetcode-cpp/pascals-triangle-ii/pascals-triangle-ii.cpp) | O(n^2) | 构建帕斯卡三角单行 | O(n) |
| 120 | [Triangle](https://leetcode.com/problems/triangle/) | [triangle.cpp](leetcode-cpp/triangle/triangle.cpp) | O(n^2) | DP+滚动数组 | O(n) |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [best-time-to-buy-and-sell-stock.cpp](leetcode-cpp/best-time-to-buy-and-sell-stock/best-time-to-buy-and-sell-stock.cpp) | O(n) | 维护前驱最小 | O(1) |
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | [valid-palindrome.cpp](leetcode-cpp/valid-palindrome/valid-palindrome.cpp) | O(n) | 判断回文字串 | O(1) |
| 128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | [longest-consecutive-sequence.cpp](leetcode-cpp/longest-consecutive-sequence/longest-consecutive-sequence.cpp) | O(n) | HashMap | O(n) |
| 136 | [Single Number](https://leetcode.com/problems/single-number/) | [single-number.cpp](leetcode-cpp/single-number/single-number.cpp) | O(n) | 异或判重 | O(1) |
| 137 | [Single Number II](https://leetcode.com/problems/single-number-ii/) | [single-number-ii.cpp](leetcode-cpp/single-number-ii/single-number-ii.cpp) | O(n) | 位操作模拟三进制 | O(1) |
| 139 | [Word Break](https://leetcode.com/problems/word-break/) | [word-break.cpp](leetcode-cpp/word-break/word-break.cpp) | O(n^2) | HashMap + DP | O(n) |
| 141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | [linked-list-cycle.go](leetcode-go/linked-list-cycle/linked-list-cycle.go) [linked-list-cycle.cpp](leetcode-cpp/linked-list-cycle/linked-list-cycle.cpp) | O(n) | 链表判环：快慢指针 | O(1) |
| 148 | [Sort List](https://leetcode.com/problems/sort-list/) | [sort-list.cpp](leetcode-cpp/sort-list/sort-list.cpp) | O(nlog(n)) | 单链表归并排序 | O(1) |
| 537 | [Complex Number Multiplication](https://leetcode.com/problems/complex-number-multiplication/) | [complex-number-multiplication.go](leetcode-go/complex-number-multiplication/complex-number-multiplication.go) | O(n) | 复数相乘 | O(1) |

## 补充

* [37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) 存在`DFS`和`Dance Link X`
  两种解法，虽然DFS对简单数独（LeetCode测试样例）处理更快，但是Dance Link X在复杂数独的求解速度远远优于DFS，故采用后者。
* [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)  若使用`HashMap`
  ，在频繁调用时候性能欠佳，因题目给出key仅为英文字母，所以采用了固定数组来统计出现次数。
* [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)  借助单调栈实现O(n)
  算法，且已尽可能优化。但是测试样例存在[bug](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/2295)
  ，即使使用提交页面提供的0ms代码，在当前测试样例下，至少也有80ms耗时，与本人结果一致，怀疑存在后期加入其他复杂测试样例。
* [89. Gray Code](https://leetcode.com/problems/gray-code/)  已做到时间+空间最优解，运算全部位运算，不论golang还是C++都做不到0ms解或则最优空间。
