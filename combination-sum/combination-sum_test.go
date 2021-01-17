package combination_sum

import (
	"reflect"
	"testing"
)

func TestCombinationSumExample1(t *testing.T) {
	candidates := []int{2, 3, 6, 7}
	target := 7
	ans := combinationSum(candidates, target)
	rightAns := [][]int{{2, 2, 3}, {7}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestCombinationSumExample2(t *testing.T) {
	candidates := []int{2, 3, 5}
	target := 8
	ans := combinationSum(candidates, target)
	rightAns := [][]int{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestCombinationSumExample4(t *testing.T) {
	candidates := []int{2}
	target := 1
	ans := combinationSum(candidates, target)
	var rightAns [][]int
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestCombinationSumExample5(t *testing.T) {
	candidates := []int{1}
	target := 1
	ans := combinationSum(candidates, target)
	rightAns := [][]int{{1}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestCombinationSumExample6(t *testing.T) {
	candidates := []int{1}
	target := 2
	ans := combinationSum(candidates, target)
	rightAns := [][]int{{1, 1}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestCombinationSumTest0(t *testing.T) {
	candidates := []int{3, 5, 8}
	target := 11
	ans := combinationSum(candidates, target)
	rightAns := [][]int{{3, 3, 5}, {3, 8}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
