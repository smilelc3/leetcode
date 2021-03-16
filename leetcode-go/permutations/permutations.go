package permutations

func permute(nums []int) [][]int {
	var permutations [][]int
	getPermutation(&permutations, nums, 0)
	return permutations
}

func getPermutation(pStorage *[][]int, nums []int, idx int) {
	if idx == len(nums)-1 {
		numsCopy := make([]int, len(nums))
		copy(numsCopy, nums)
		*pStorage = append(*pStorage, numsCopy)
	} else {
		for i := idx; i < len(nums); i++ {
			nums[i], nums[idx] = nums[idx], nums[i]
			numsCopy := make([]int, len(nums))
			copy(numsCopy, nums)
			getPermutation(pStorage, numsCopy, idx+1)
		}
	}
}
