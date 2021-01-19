package permutations_ii

import "sort"

func permuteUnique(nums []int) [][]int {
	var uniquePermutations [][]int
	sort.Ints(nums)
	getUniquePermutation(&uniquePermutations, nums, 0)
	return uniquePermutations
}

func getUniquePermutation(pStorage *[][]int, nums []int, idx int) {
	if idx == len(nums)-1 {
		numsCopy := make([]int, len(nums))
		copy(numsCopy, nums)
		*pStorage = append(*pStorage, numsCopy)
	} else {
		for i := idx; i < len(nums); i++ {
			if i > idx && (nums[i-1] == nums[i] || nums[i] == nums[idx]) {
				continue
			}
			nums[i], nums[idx] = nums[idx], nums[i]
			numsCopy := make([]int, len(nums))
			copy(numsCopy, nums)
			getUniquePermutation(pStorage, numsCopy, idx+1)
		}
	}
}
