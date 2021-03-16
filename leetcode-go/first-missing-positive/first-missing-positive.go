package first_missing_positive

func firstMissingPositive(nums []int) int {
	for idx, num := range nums {
		if idx+1 == num {
			continue
		}
		// 待调整的数字, 不使用num,改而使用nums[idx]
		for nums[idx] > 0 && nums[idx] <= len(nums) && nums[idx] != nums[nums[idx]-1] {
			nums[nums[idx]-1], nums[idx] = nums[idx], nums[nums[idx]-1]
		}
	}
	ans := len(nums) + 1
	for idx, num := range nums {
		if idx != num-1 {
			ans = idx + 1
			break
		}
	}
	return ans
}
