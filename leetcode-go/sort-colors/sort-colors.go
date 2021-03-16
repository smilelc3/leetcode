package sort_colors

func sortColors(nums []int) {
	numOfNums := [3]int{}
	for idx := 0; idx < len(nums); idx++ {
		if nums[idx] != 0 && nums[idx] != 1 && nums[idx] != 2 {
			panic("nums[]数值错误")
		}
		numOfNums[nums[idx]]++
	}
	numIdx := 0
	for idx := 0; idx <= 2; idx++ {
		for numOfNums[idx] != 0 {
			nums[numIdx] = idx
			numIdx++
			numOfNums[idx]--
		}
	}
}
