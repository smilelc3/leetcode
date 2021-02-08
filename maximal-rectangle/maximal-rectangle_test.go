package maximal_rectangle

import "testing"

func TestMaximalRectangleExample1(t *testing.T) {
	matrix := [][]byte{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}}
	ans := maximalRectangle(matrix)
	rightAns := 6
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaximalRectangleExample2(t *testing.T) {
	matrix := [][]byte{}
	ans := maximalRectangle(matrix)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaximalRectangleExample3(t *testing.T) {
	matrix := [][]byte{
		{'0'}}
	ans := maximalRectangle(matrix)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaximalRectangleExample4(t *testing.T) {
	matrix := [][]byte{
		{'1'}}
	ans := maximalRectangle(matrix)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaximalRectangleExample5(t *testing.T) {
	matrix := [][]byte{
		{'0', '0'}}
	ans := maximalRectangle(matrix)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
