package set_matrix_zeroes

import (
	"reflect"
	"testing"
)

func TestSetZeroesExample1(t *testing.T) {
	matrix := [][]int{
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1}}
	setZeroes(matrix)
	ans := matrix
	rightAns := [][]int{
		{1, 0, 1},
		{0, 0, 0},
		{1, 0, 1}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSetZeroesExample2(t *testing.T) {
	matrix := [][]int{
		{0, 1, 2, 0},
		{3, 4, 5, 2},
		{1, 3, 1, 5}}
	setZeroes(matrix)
	ans := matrix
	rightAns := [][]int{
		{0, 0, 0, 0},
		{0, 4, 5, 0},
		{0, 3, 1, 0}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
