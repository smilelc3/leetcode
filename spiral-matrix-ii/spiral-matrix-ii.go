package spiral_matrix_ii

func generateMatrix(n int) [][]int {
	// O(n^2)

	if n <= 0 {
		return [][]int{}
	}
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}

	matrix[0][0] = 1

	idx := 0
	idxRow := 0 // 记录行号
	idxCol := 0 // 记录列号
	direct := 0 // 记录方向
	/*
		0 -> right
		1 -> down
		2 -> left
		3 -> up
	*/
	// 定义墙
	upWall := 0
	downWall := n - 1
	leftWall := 0
	rightWall := n - 1

	for idx < n*n-1 {
		switch direct {
		case 0:
			for idxCol+1 <= rightWall {
				idx++
				idxCol++
				matrix[idxRow][idxCol] = idx + 1
			}
			upWall++
			direct = 1
		case 1:
			for idxRow+1 <= downWall {
				idx++
				idxRow++
				matrix[idxRow][idxCol] = idx + 1
			}
			rightWall--
			direct = 2
		case 2:
			for idxCol-1 >= leftWall {
				idx++
				idxCol--
				matrix[idxRow][idxCol] = idx + 1
			}
			downWall--
			direct = 3
		case 3:
			for idxRow-1 >= upWall {
				idx++
				idxRow--
				matrix[idxRow][idxCol] = idx + 1
			}
			leftWall++
			direct = 0
		}
	}
	return matrix
}
