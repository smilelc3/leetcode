package climbing_stairs

func climbStairs(n int) int {
	beforeN := 1
	beforeBeforeN := 1
	ans := 1 // default n <= 1
	for idx := 2; idx <= n; idx++ {
		ans = beforeBeforeN + beforeN
		beforeBeforeN, beforeN = beforeN, ans
	}
	return ans
}
