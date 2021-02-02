package subsets

import (
	"reflect"
	"sort"
	"testing"
)

func TestSubsetsExample1(t *testing.T) {
	nums := []int{1, 2, 3}
	ans := subsets(nums)
	rightAns := [][]int{
		{},
		{1},
		{2},
		{1, 2},
		{3},
		{1, 3},
		{2, 3},
		{1, 2, 3}}
	sort.Slice(ans, func(i int, j int) bool {
		return lessSubset(ans[i], ans[j])
	})
	sort.Slice(rightAns, func(i int, j int) bool {
		return lessSubset(rightAns[i], rightAns[j])
	})
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func lessSubset(subsetA []int, subsetB []int) bool {
	if len(subsetA) != len(subsetB) {
		return len(subsetA) < len(subsetB)
	} else {
		for idx := 0; idx < len(subsetA); idx++ {
			if subsetA[idx] != subsetB[idx] {
				return subsetA[idx] < subsetB[idx]
			}
		}
		return true
	}
}

func TestSubsetsExample2(t *testing.T) {
	nums := []int{0}
	ans := subsets(nums)
	rightAns := [][]int{
		{},
		{0}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSubsetsTest0(t *testing.T) {
	nums := []int{9, 0, 3, 5, 7}
	ans := subsets(nums)
	rightAns := [][]int{{}, {9}, {0}, {0, 9}, {3}, {3, 9}, {0, 3}, {0, 3, 9}, {5}, {5, 9}, {0, 5}, {0, 5, 9}, {3, 5}, {3, 5, 9}, {0, 3, 5}, {0, 3, 5, 9}, {7}, {7, 9}, {0, 7}, {0, 7, 9}, {3, 7}, {3, 7, 9}, {0, 3, 7}, {0, 3, 7, 9}, {5, 7}, {5, 7, 9}, {0, 5, 7}, {0, 5, 7, 9}, {3, 5, 7}, {3, 5, 7, 9}, {0, 3, 5, 7}, {0, 3, 5, 7, 9}}
	for idx := 0; idx < len(ans); idx++ {
		sort.Ints(ans[idx])
	}
	sort.Slice(ans, func(i int, j int) bool {
		return lessSubset(ans[i], ans[j])
	})
	for idx := 0; idx < len(rightAns); idx++ {
		sort.Ints(rightAns[idx])
	}
	sort.Slice(rightAns, func(i int, j int) bool {
		return lessSubset(rightAns[i], rightAns[j])
	})
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
	for idx := 0; idx < len(ans); idx++ {
		if !reflect.DeepEqual(ans[idx], rightAns[idx]) {
			t.Error("idx=", idx, "right ans[idx] = ", rightAns[idx], ", current ans[idx] = ", ans[idx])
		}
	}
}
