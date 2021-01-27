package unique_paths

func uniquePaths(m int, n int) int {
	// method 1: DP space O(m*n)
	//return uniquePathsDPMN(m, n)

	// method 2: DP space O(min(m,n))
	if m > n {
		return uniquePathsDPMin(n, m)
	} else {
		return uniquePathsDPMin(m, n)
	}

}

func uniquePathsDPMin(small, big int) int {
	if small <= 0 {
		return 0
	}

	dp := make([]int, small)

	for idx := 0; idx < small; idx++ {
		dp[idx] = 1
	}
	for i := 1; i < big; i++ {
		for j := 1; j < small; j++ {
			dp[j] = dp[j] + dp[j-1]
		}
	}
	return dp[small-1]
}

func uniquePathsDPMN(m int, n int) int {
	if m <= 0 || n <= 0 {
		return 0
	}

	dp := make([][]int, m)
	for idx := 0; idx < m; idx++ {
		dp[idx] = make([]int, n)
	}

	dp[0][0] = 1
	for i := 1; i < m; i++ {
		dp[i][0] = dp[i-1][0]
	}
	for j := 1; j < n; j++ {
		dp[0][j] = dp[0][j-1]
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
		}
	}
	return dp[m-1][n-1]
}
