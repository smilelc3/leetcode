package search_insert_position

func searchInsert(nums []int, target int) int {
	// method 1 Single Loop
	//return searchInsertNormal(nums, target)

	// method 2 Binary Search
	return searchInsertBinarySearch(nums, target)
}

func searchInsertNormal(nums []int, target int) int {
	insertIdx := -1
	if nums[0] > target {
		insertIdx = 0
	} else if nums[len(nums)-1] < target {
		insertIdx = len(nums)
	} else {
		for idx, num := range nums {
			if num >= target {
				insertIdx = idx
				break
			}
		}
	}
	return insertIdx
}

func searchInsertBinarySearch(nums []int, target int) int {
	start := 0
	end := len(nums) - 1
	if end-start <= 1 {
		if target <= nums[start] {
			return start
		} else if target <= nums[end] {
			return end
		} else {
			return end + 1
		}
	}
	mid := (start + end) / 2

	if nums[mid] > target {
		return searchInsertBinarySearch(nums[:mid], target)
	} else if nums[mid] < target {
		return mid + searchInsertBinarySearch(nums[mid:], target)
	} else {
		return mid
	}
}
