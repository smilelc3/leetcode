package spiral_matrix

func spiralOrder(matrix [][]int) []int {
	if matrix == nil {
		return []int{}
	}
	width := len(matrix[0])
	height := len(matrix)

	order := make([]int, width*height)
	order[0] = matrix[0][0]

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
	downWall := height - 1
	leftWall := 0
	rightWall := width - 1

	for idx < width*height-1 {
		switch direct {
		case 0:
			for idxCol+1 <= rightWall {
				idx++
				idxCol++
				order[idx] = matrix[idxRow][idxCol]
			}
			upWall++
			direct = 1
		case 1:
			for idxRow+1 <= downWall {
				idx++
				idxRow++
				order[idx] = matrix[idxRow][idxCol]
			}
			rightWall--
			direct = 2
		case 2:
			for idxCol-1 >= leftWall {
				idx++
				idxCol--
				order[idx] = matrix[idxRow][idxCol]
			}
			downWall--
			direct = 3
		case 3:
			for idxRow-1 >= upWall {
				idx++
				idxRow--
				order[idx] = matrix[idxRow][idxCol]
			}
			leftWall++
			direct = 0
		}
	}
	return order
}
