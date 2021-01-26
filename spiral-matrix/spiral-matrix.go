package spiral_matrix

func spiralOrder(matrix [][]int) []int {
	if matrix == nil {
		return []int{}
	}
	width := len(matrix[0])
	height := len(matrix)

	order := make([]int, width*height)

	for i, row := range matrix {
		for j, num := range row {
			// nums(i,j)
		}
	}
	return order
}
