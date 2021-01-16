package search_in_rotated_sorted_array

func searchNormal(nums []int, target int) int {
	location := -1
	for idx, num := range nums {
		if num == target {
			location = idx
			break
		}
	}
	return location
}

func searchHalfBinary(nums []int, target int) int {
	start := 0
	end := len(nums) - 1
	mid := (start + end) / 2
	if nums[start] > nums[mid] {
		// nums[mid,end] in order
		if nums[mid] <= target && target <= nums[end] {
			tempLoc := searchFullBinary(nums[mid:end+1], target)
			if tempLoc != -1 {
				return mid + tempLoc
			} else {
				return -1
			}
		} else {
			return searchHalfBinary(nums[start:mid], target)
		}
	} else if nums[mid] > nums[end] {
		// nums[start,mid] in order
		if nums[start] <= target && target <= nums[mid] {
			return searchFullBinary(nums[start:mid+1], target)
		} else {
			tempLoc := searchHalfBinary(nums[mid+1:end+1], target)
			if tempLoc != -1 {
				return mid + 1 + tempLoc
			} else {
				return -1
			}
		}
	} else {
		// nums[start,end] in order
		return searchFullBinary(nums, target)
	}
}

func searchFullBinary(nums []int, target int) int {
	start := 0
	end := len(nums) - 1
	if end-start <= 1 {
		if nums[start] == target {
			return start
		} else if nums[end] == target {
			return end
		} else {
			return -1
		}
	}
	mid := (start + end) / 2
	if target == nums[mid] {
		return mid
	} else if target < nums[mid] {
		return searchFullBinary(nums[start:mid], target)
	} else {
		// target > nums[mid]
		tempLoc := searchFullBinary(nums[mid+1:end+1], target)
		if tempLoc != -1 {
			return mid + 1 + tempLoc
		} else {
			return -1
		}

	}
}

func search(nums []int, target int) int {
	// method 1: O(n)
	//return searchNormal(nums, target)

	// method 2: O(log(n))
	return searchHalfBinary(nums, target)
}
