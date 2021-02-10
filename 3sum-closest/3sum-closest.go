package three_sum_closest

import (
	. "leetcode-go/built-in"
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	threeSum := math.MaxInt32
	sort.Ints(nums)
	for idx, num := range nums {
		if idx > 0 && num == nums[idx-1] {
			continue
		}
		left := idx + 1
		right := len(nums) - 1
		for left < right {
			curSum := num + nums[left] + nums[right]
			if Abs(curSum-target) < Abs(threeSum-target) {
				threeSum = curSum
			}
			if curSum > target {
				right--
			} else if curSum < target {
				left++
			} else { //  == target
				return target
			}
		}
	}
	return threeSum
}
