package two_sum

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.

func twoSumLoop(nums []int, target int) []int {
	for idxA, numA := range nums[:len(nums)-1] {
		for idxB, numB := range nums[idxA+1:] {
			if numA+numB == target {
				return []int{idxA, idxA + idxB + 1}
			}
		}
	}
	return []int{0, 0}
}

func twoSumMap(nums []int, target int) []int {
	intToIdxMap := map[int]int{}
	for idx, num := range nums {
		if _, ok := intToIdxMap[num]; ok {
			return []int{idx, intToIdxMap[num]}
		} else {
			intToIdxMap[target-num] = idx
		}
	}
	return []int{0, 0}
}

func twoSum(nums []int, target int) []int {
	return twoSumMap(nums, target)
}
