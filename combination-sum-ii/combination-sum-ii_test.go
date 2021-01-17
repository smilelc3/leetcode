package combination_sum_ii

import (
	"reflect"
	"testing"
)

func TestCombinationSum2Example1(t *testing.T) {
	candidates := []int{10, 1, 2, 7, 6, 1, 5}
	target := 8
	ans := combinationSum2(candidates, target)
	rightAns := [][]int{
		{1, 1, 6},
		{1, 2, 5},
		{1, 7},
		{2, 6}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestCombinationSum2Example2(t *testing.T) {
	candidates := []int{2, 5, 2, 1, 2}
	target := 5
	ans := combinationSum2(candidates, target)
	rightAns := [][]int{
		{1, 2, 2},
		{5}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestTransCombination2String(t *testing.T) {
	candidates := []int{2, 5, 2, 1, 2}
	ans := transCombination2String(candidates)
	rightAns := "2 5 2 1 2"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
