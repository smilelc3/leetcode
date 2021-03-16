package maximal_rectangle

import . "leetcode-go/largest-rectangle-in-histogram"

func maximalRectangle(matrix [][]byte) int {
	// 借助largest-rectangle-in-histogram题实现，O(mn)
	maxRectArea := 0
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}

	heights := make([][]int, len(matrix))
	for idx := 0; idx < len(matrix); idx++ {
		heights[idx] = make([]int, len(matrix[idx]))
	}

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			if matrix[i][j] == '0' {
				heights[i][j] = 0
			} else {
				if i == 0 {
					heights[i][j] = 1
				} else {
					heights[i][j] = heights[i-1][j] + 1
				}
			}
		}
	}
	for idx := 0; idx < len(matrix); idx++ {
		curArea := LargestRectangleAreaStackIdx(heights[idx])
		if curArea > maxRectArea {
			maxRectArea = curArea
		}
	}
	return maxRectArea
}
