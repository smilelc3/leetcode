from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans: List[str] = []
        left = 0  # 左边界开始下标
        right = 1  # 右边界结束下标的下一个
        while left < len(nums):
            if right < len(nums) and nums[right - 1] + 1 == nums[right]:
                right += 1
            else:
                if left == right - 1:
                    ans.append(str(nums[left]))
                else:
                    ans.append(f"{nums[left]}->{nums[right - 1]}")
                left = right
                right += 1
        return ans
