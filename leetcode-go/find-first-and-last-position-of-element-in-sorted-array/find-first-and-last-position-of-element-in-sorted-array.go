package find_first_and_last_position_of_element_in_sorted_array

func searchRange(nums []int, target int) []int {
	if len(nums) == 0 {
		return []int{-1, -1}
	}
	left, right := binarySearch(nums, target)
	return []int{left, right}
}

func binarySearch(nums []int, target int) (int, int) {
	left := 0
	right := len(nums) - 1

	// 边界条件
	if right-left <= 1 {
		var start, end int
		if target != nums[left] && nums[right] != target {
			start = -1
			end = -1
		} else if target == nums[left] && target != nums[right] {
			start = left
			end = left
		} else if target != nums[left] && target == nums[right] {
			start = right
			end = right
		} else {
			// target == nums[left] && target == nums[right]
			start = left
			end = right
		}
		return start, end
	}

	mid := (left + right) / 2

	if nums[mid] > target {
		return binarySearch(nums[:mid], target)
	} else if nums[mid] < target {
		nextLeft, nextRight := binarySearch(nums[mid+1:], target)
		if nextLeft != -1 {
			nextLeft += mid + 1
		}
		if nextRight != -1 {
			nextRight += mid + 1
		}
		return nextLeft, nextRight
	} else {
		// nums[mid] == target
		nextLeft, _ := binarySearch(nums[:mid+1], target) // 一定包含mid, 且nextLeft != -1
		_, nextRight := binarySearch(nums[mid:], target)  // 一定包含mid, 且nextRight != -1
		return nextLeft, mid + nextRight
	}
}
