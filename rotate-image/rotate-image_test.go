package rotate_image

import (
	"reflect"
	"testing"
)

func TestRotateExample1(t *testing.T) {
	matrix := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	rotate(matrix)
	ans := matrix
	rightAns := [][]int{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRotateExample2(t *testing.T) {
	matrix := [][]int{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}}
	rotate(matrix)
	ans := matrix
	rightAns := [][]int{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRotateExample3(t *testing.T) {
	matrix := [][]int{{1}}
	rotate(matrix)
	ans := matrix
	rightAns := [][]int{{1}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRotateExample4(t *testing.T) {
	matrix := [][]int{{1, 2}, {3, 4}}
	rotate(matrix)
	ans := matrix
	rightAns := [][]int{{3, 1}, {4, 2}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMatrixMulMyTest0(t *testing.T) {
	a := [][]float64{
		{1, 2},
		{3, 4},
		{5, 6},
	}
	b := [][]float64{
		{1, 2, 3},
		{3, 4, 1},
	}
	ans := matrixMul(a, b)
	rightAns := [][]float64{{7, 10, 5}, {15, 22, 13}, {23, 34, 21}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
