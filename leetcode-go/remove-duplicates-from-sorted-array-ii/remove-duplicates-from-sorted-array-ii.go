package remove_duplicates_from_sorted_array_ii

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	preNum := nums[0]
	duplicateTime := 0
	idx := 1
	for idx < len(nums) {
		if nums[idx] == preNum {
			duplicateTime++
			if duplicateTime >= 2 {
				nums = append(nums[0:idx], nums[idx+1:]...)
			} else {
				idx++
			}
		} else {
			preNum = nums[idx]
			duplicateTime = 0
			idx++
		}
	}
	return len(nums)
}
