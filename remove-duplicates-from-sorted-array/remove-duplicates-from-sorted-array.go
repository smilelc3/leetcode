package remove_duplicates_from_sorted_array

func removeDuplicates(nums []int) int {
	uniqueIdx := 0
	for idx := 1; idx < len(nums); idx++ {
		if nums[idx-1] != nums[idx] {
			uniqueIdx++
			nums[uniqueIdx] = nums[idx]
		}
	}
	if len(nums) > 0 {
		nums = nums[:uniqueIdx+1]
	}
	return len(nums)
}
