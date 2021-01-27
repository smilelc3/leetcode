package unique_paths_ii

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	if len(obstacleGrid) == 0 || len(obstacleGrid[0]) == 0 {
		return 0
	}
	m := len(obstacleGrid)
	n := len(obstacleGrid[0])
	// 保证 高度大于等于宽度
	if m > n {
		return uniquePathsWithObstaclesDPMin(n, m, obstacleGrid, false)
	} else {
		return uniquePathsWithObstaclesDPMin(m, n, obstacleGrid, true)
	}
}

func uniquePathsWithObstaclesDPMin(small, big int, obstacleGri [][]int, isSwap bool) int {
	// 高度始终大于等于宽度
	// small 代表 宽度
	// big 代表 高度
	if small <= 0 {
		return 0
	}

	dp := make([]int, small)

	for idx := 0; idx < small; idx++ {
		if !isSwap && obstacleGri[0][idx] == 1 {
			break
		} else if isSwap && obstacleGri[idx][0] == 1 {
			break
		} else {
			dp[idx] = 1
		}
	}

	for i := 1; i < big; i++ {
		for j := 0; j < small; j++ {
			if !isSwap && obstacleGri[i][j] == 1 {
				dp[j] = 0
			} else if isSwap && obstacleGri[j][i] == 1 {
				dp[j] = 0
			} else {
				if j > 0 {
					dp[j] = dp[j] + dp[j-1]
				}
			}
		}
	}
	return dp[small-1]
}
