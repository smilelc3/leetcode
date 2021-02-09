package subsets_ii

import "sort"

func subsetsWithDup(nums []int) [][]int {
	var ans [][]int
	sort.Ints(nums)
	ans = append(ans, []int{})
	subsetsRemoveDupBacktrack(nums, 0, []int{}, &ans)
	return ans
}

func subsetsRemoveDupBacktrack(nums []int, start int, pre []int, pStorage *[][]int) {
	for idx := start; idx < len(nums); idx++ {
		if idx > start && nums[idx] == nums[idx-1] {
			continue
		}
		cur := append(pre, nums[idx])
		curCopy := make([]int, len(cur))
		copy(curCopy, cur)
		*pStorage = append(*pStorage, curCopy)
		subsetsRemoveDupBacktrack(nums, idx+1, cur, pStorage)
	}
}
