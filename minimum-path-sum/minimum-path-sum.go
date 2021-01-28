package minimum_path_sum

func minPathSum(grid [][]int) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	height := len(grid)
	width := len(grid[0])

	for idx := 1; idx < width; idx++ {
		grid[0][idx] = grid[0][idx-1] + grid[0][idx]
	}
	for idx := 1; idx < height; idx++ {
		grid[idx][0] = grid[idx-1][0] + grid[idx][0]
	}

	for i := 1; i < height; i++ {
		for j := 1; j < width; j++ {
			grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j]
		}
	}
	return grid[height-1][width-1]
}

func min(x int, y int) int {
	if x > y {
		return y
	} else {
		return x
	}
}
