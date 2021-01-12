package four_sum

import (
	"reflect"
	"sort"
	"testing"
)

func TestFourSumExample1(t *testing.T) {
	nums := []int{1, 0, -1, 0, -2, 2}
	target := 0
	ans := fourSum(nums, target)
	rightAnsSet := map[[4]int]bool{}
	rightAnsSet[[4]int{-2, -1, 1, 2}] = true
	rightAnsSet[[4]int{-2, 0, 0, 2}] = true
	rightAnsSet[[4]int{-1, 0, 0, 1}] = true

	if len(ans) != 3 {
		t.Error("right ans = ", rightAnsSet, ", current ans = ", ans)
	} else {
		for _, quadrupletSlice := range ans {
			sort.Ints(quadrupletSlice)
			quadruplet := [4]int{}
			if len(quadrupletSlice) != 4 {
				t.Error("right ans = ", rightAnsSet, ", current ans = ", ans)
			}
			for idx, val := range quadrupletSlice {
				quadruplet[idx] = val
			}
			if _, exist := rightAnsSet[quadruplet]; !exist {
				t.Error("right ans = ", rightAnsSet, ", current ans = ", ans)
				return
			}
		}
	}
}

func TestThreeSumFourZero(t *testing.T) {
	nums := []int{0, 0, 0, 0}
	target := 0
	ans := fourSum(nums, target)
	rightAns := [][]int{{0, 0, 0, 0}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestThreeSumTest0(t *testing.T) {
	nums := []int{-2, -1, -1, 1, 1, 2, 2}
	target := 0
	ans := fourSum(nums, target)
	rightAns := [][]int{{-2, -1, 1, 2}, {-1, -1, 1, 1}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
