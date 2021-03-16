package unique_paths_ii

import "testing"

func TestUniquePathsExample1(t *testing.T) {
	obstacleGrid := [][]int{
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}}
	ans := uniquePathsWithObstacles(obstacleGrid)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestUniquePathsExample2(t *testing.T) {
	obstacleGrid := [][]int{
		{0, 1},
		{0, 0}}
	ans := uniquePathsWithObstacles(obstacleGrid)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestUniquePathsTest0(t *testing.T) {
	obstacleGrid := [][]int{
		{0, 1}}
	ans := uniquePathsWithObstacles(obstacleGrid)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestUniquePathsTest1(t *testing.T) {
	obstacleGrid := [][]int{
		{0, 0},
		{1, 0}}
	ans := uniquePathsWithObstacles(obstacleGrid)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestUniquePathsTest2(t *testing.T) {
	obstacleGrid := [][]int{
		{0, 0},
		{1, 1},
		{0, 0}}
	ans := uniquePathsWithObstacles(obstacleGrid)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
