package subsets

func subsets(nums []int) [][]int {
	var ans [][]int
	ans = append(ans, []int{})
	subsetsBacktrack(nums, 0, []int{}, &ans)
	return ans
}

func subsetsBacktrack(nums []int, start int, pre []int, pStorage *[][]int) {
	for idx := start; idx < len(nums); idx++ {
		cur := append(pre, nums[idx])
		curCopy := make([]int, len(cur))
		copy(curCopy, cur)
		*pStorage = append(*pStorage, curCopy)
		subsetsBacktrack(nums, idx+1, cur, pStorage)
	}
}
