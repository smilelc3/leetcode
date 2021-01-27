package spiral_matrix_ii

import (
	"reflect"
	"testing"
)

func TestGenerateMatrixExample1(t *testing.T) {
	n := 3
	ans := generateMatrix(n)
	rightAns := [][]int{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestGenerateMatrixExample2(t *testing.T) {
	n := 1
	ans := generateMatrix(n)
	rightAns := [][]int{{1}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
