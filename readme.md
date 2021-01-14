# leetcode自由刷题——go版本

* 若无特殊说明，所给代码解法**均为时间最优解**，在某些题的代码中，包含多个可AC方法，最终也只采用最优时间解。
* 每个题单独创建以题名为命名的文件夹，下含有源码与单元测试代码，均通过测试

| 编号 | 题目 | 代码 | 时间复杂度 | 简述 |  空间复杂度 |
|:---:|:-----:|:---:|:---:|:---:|:---:|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | [two-sum.go](two-sum/two-sum.go) | O(n) | 哈希Map |  |
| 2 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [add-two-numbers.go](add-two-numbers/add-two-numbers.go) | O(n) | 单向链表 | |
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [longest-substring-without-repeating-characters.go](longest-substring-without-repeating-characters/longest-substring-without-repeating-characters.go) | O(n) | DP优化 | |
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [median-of-two-sorted-arrays.go](median-of-two-sorted-arrays/median-of-two-sorted-arrays.go) | O(log(min(N1,N2))) | 参考[Grandyang博客](https://www.cnblogs.com/grandyang/p/4465932.html) |  |
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | [longest-palindromic-substring.go](longest-palindromic-substring/longest-palindromic-substring.go) | O(n) | manacher算法 |  |



5. `Longest Palindromic Substring` [题目](https://leetcode.com/problems/longest-palindromic-substring/) [代码](longest-palindromic-substring/longest-palindromic-substring.go)
   manacher算法 O(n)

6. `ZigZag Conversion` [题目](https://leetcode.com/problems/zigzag-conversion/) [代码](zigzag-conversion/zigzag-conversion.go)
   规律总结 O(n)

7. `Reverse Integer` [题目](https://leetcode.com/problems/reverse-integer/) [代码](reverse-integer/reverse-integer.go)
   strconv.Itoa() strconv.Atoi() 实现

8. `String to Integer (atoi)` [题目](https://leetcode.com/problems/string-to-integer-atoi/) [代码](string-to-integer-atoi/string-to-integer-atoi.go)
   正则匹配

9. `Palindrome Number` [题目](https://leetcode.com/problems/palindrome-number/) [代码](palindrome-number/palindrome-number.go)
   strconv.Itoa()实现 O(n/2)

10. `Regular Expression Matching` [题目](https://leetcode.com/problems/regular-expression-matching/) [代码](regular-expression-matching/regular-expression-matching.go)
    DP O(n*m)

11. `Container With Most Water` [题目](https://leetcode.com/problems/container-with-most-water/) [代码](container-with-most-water/container-with-most-water.go)
    two-pointer算法 O(n)

12. `Integer to Roman` [题目](https://leetcode.com/problems/integer-to-roman/) [代码](integer-to-roman/integer-to-roman.go)
    打表 ≈O(1)

13. `Roman to Integer` [题目](https://leetcode.com/problems/roman-to-integer/) [代码](roman-to-integer/roman-to-integer.go)
    switch-case O(n)

14. `Longest Common Prefix` [题目](https://leetcode.com/problems/longest-common-prefix/) [代码](longest-common-prefix/longest-common-prefix.go)
    if模拟 O(n*m)

15. `3Sum`  [题目](https://leetcode.com/problems/3sum/) [代码](3sum/3sum.go) two-pointer O(n^2)

16. `3Sum Closest` [题目](https://leetcode.com/problems/3sum-closest/) [代码](3sum-closest/3sum-closest.go) two-pointer O(
    n^2)

17. `Letter Combinations of a Phone Number` [题目](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) [代码](letter-combinations-of-a-phone-number/letter-combinations-of-a-phone-number.go)
    O(4^n)

18. `4Sum` [题目](https://leetcode.com/problems/4sum/) [代码](4sum/4sum.go) two-pointer O(n^3)

19. `Remove Nth Node From End of List` [题目](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) [代码](remove-nth-node-from-end-of-list/remove-nth-node-from-end-of-list.go)
    循环数组 O(n)

20. `Valid Parentheses` [题目](https://leetcode.com/problems/valid-parentheses/) [代码](valid-parentheses/valid-parentheses.go)
    栈 O(n)

21. `Merge Two Sorted Lists` [题目](https://leetcode.com/problems/merge-two-sorted-lists/) [代码](merge-two-sorted-lists/merge-two-sorted-lists.go)
    递归 O(m+n)

22. `Generate Parentheses` [题目](https://leetcode.com/problems/generate-parentheses/) [代码](generate-parentheses/generate-parentheses.go)
    递归 O(2^n)

23. `Merge k Sorted Lists` [题目](https://leetcode.com/problems/merge-k-sorted-lists/) [代码](merge-k-sorted-lists/merge-k-sorted-lists.go)
    分治O(log(n)*m)

24. `Swap Nodes in Pairs` [题目](https://leetcode.com/problems/swap-nodes-in-pairs/) [代码](swap-nodes-in-pairs/swap-nodes-in-pairs.go)
    链表交换节点 O(n)

25. `Reverse Nodes in k-Group` [题目](https://leetcode.com/problems/reverse-nodes-in-k-group/) [代码](reverse-nodes-in-k-group/reverse-nodes-in-k-group.go)
    记录前驱+后驱节点 时间O(n) 空间O(1)

26. `Remove Duplicates from Sorted Array` [题目](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) [代码](remove-duplicates-from-sorted-array/remove-duplicates-from-sorted-array.go)
    O(n) slice传参：带地址的结构体值

27. `Remove Element` [题目](https://leetcode.com/problems/remove-element/) [代码](remove-element/remove-element.go) 空间 O(1)

28. `Implement strStr()` [题目](https://leetcode.com/problems/implement-strstr/) [代码](implement-strstr/implement-strstr.go)
    KMP算法 O(n+m)

29. `Divide Two Integers` [题目](https://leetcode.com/problems/divide-two-integers/) [代码](divide-two-integers/divide-two-integers.go)
    位操作实现除法 O(log(n))


35. `Search Insert Position` [题目](https://leetcode.com/problems/search-insert-position/) [代码](search-insert-position/search-insert-position.go)
    二分查找 O(log(n))