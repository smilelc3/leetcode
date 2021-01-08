package three_sum_closest

import (
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
			if abs(curSum-target) < abs(threeSum-target) {
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

func abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}
