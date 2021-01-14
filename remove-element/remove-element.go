package remove_element

func removeElement(nums []int, val int) int {
	notValIdx := 0
	for idx := 0; idx < len(nums); idx++ {
		// notValIdx always <= idx
		if nums[idx] != val {
			nums[notValIdx] = nums[idx]
			notValIdx++
		}
	}
	nums = nums[:notValIdx]
	return len(nums)
}
