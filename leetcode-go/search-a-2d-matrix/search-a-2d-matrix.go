package search_a_2d_matrix

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	height := len(matrix)
	width := len(matrix[0])
	start := 0
	end := height*width - 1

	for start <= end {
		mid := (start + end) / 2
		ceil := matrix[mid/width][mid%width]
		if ceil == target {
			return true
		} else if ceil > target {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}
	return false
}
