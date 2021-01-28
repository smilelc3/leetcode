package minimum_path_sum

import "testing"

func TestMinPathSumExample1(t *testing.T) {
	grid := [][]int{
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}}
	ans := minPathSum(grid)
	rightAns := 7
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinPathSumExample2(t *testing.T) {
	grid := [][]int{
		{1, 2, 3},
		{4, 5, 6}}
	ans := minPathSum(grid)
	rightAns := 12
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
