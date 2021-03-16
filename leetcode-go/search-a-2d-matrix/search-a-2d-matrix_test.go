package search_a_2d_matrix

import "testing"

func TestSearchMatrixExample1(t *testing.T) {
	matrix := [][]int{
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}}
	target := 3
	ans := searchMatrix(matrix, target)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchMatrixExample2(t *testing.T) {
	matrix := [][]int{
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}}
	target := 13
	ans := searchMatrix(matrix, target)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
