package four_sum

import "sort"

func fourSum(nums []int, target int) [][]int {
	var quadruplets [][]int
	sort.Ints(nums)
	// Loop 1
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		// Loop 2
		for j := i + 1; j < len(nums)-1; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			// two-pointer
			left := j + 1
			right := len(nums) - 1
			for left < right {
				diff := nums[i] + nums[j] + nums[left] + nums[right] - target
				if diff > 0 {
					right--
				} else if diff < 0 {
					left++
				} else { // diff == 0
					quadruplets = append(quadruplets, []int{nums[i], nums[j], nums[left], nums[right]})
					left++
					for nums[left] == nums[left-1] && left < right {
						left++
					}
				}
			}
		}
	}
	return quadruplets
}
