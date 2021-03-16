package search_in_rotated_sorted_array_ii

func search(nums []int, target int) bool {
	// best O(log(n))  worst O(n)
	start := 0
	end := len(nums) - 1
	for start < end && nums[start] == nums[end] {
		end--
	}

	mid := (start + end) / 2
	if nums[start] > nums[mid] {
		// nums[mid,end] in order
		if nums[mid] <= target && target <= nums[end] {
			return searchBinary(nums[mid:end+1], target)
		} else {
			return search(nums[start:mid], target)
		}
	} else if nums[mid] > nums[end] {
		// nums[start,mid] in order
		if nums[start] <= target && target <= nums[mid] {
			return searchBinary(nums[start:mid+1], target)
		} else {
			return search(nums[mid+1:end+1], target)
		}
	} else {
		// nums[start,end] in order
		return searchBinary(nums[start:end+1], target)
	}
}

func searchBinary(nums []int, target int) bool {
	start := 0
	end := len(nums) - 1
	if end-start <= 1 {
		if nums[start] == target {
			return true
		} else if nums[end] == target {
			return true
		} else {
			return false
		}
	}
	mid := (start + end) / 2
	if target == nums[mid] {
		return true
	} else if target < nums[mid] {
		return searchBinary(nums[start:mid], target)
	} else {
		// target > nums[mid]
		return searchBinary(nums[mid+1:end+1], target)
	}
}
