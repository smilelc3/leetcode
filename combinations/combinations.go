package combinations

func combine(n int, k int) [][]int {
	var ans [][]int
	if k == 1 {
		for idx := 1; idx <= n; idx++ {
			ans = append(ans, []int{idx})
		}
		return ans
	}

	for idx := k; idx <= n; idx++ {
		next := combine(idx-1, k-1)
		for j := 0; j < len(next); j++ {
			next[j] = append(next[j], idx)
			ans = append(ans, next[j])
		}
	}
	return ans
}
