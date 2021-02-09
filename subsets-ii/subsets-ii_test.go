package subsets_ii

import (
	"reflect"
	"sort"
	"testing"
)

func TestSubsetsWithDupExample1(t *testing.T) {
	nums := []int{1, 2, 2}
	ans := subsetsWithDup(nums)
	rightAns := [][]int{
		{},
		{1},
		{2},
		{1, 2},
		{1, 2, 2},
		{2, 2}}
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

func TestSubsetsWithDupExample2(t *testing.T) {
	nums := []int{0}
	ans := subsetsWithDup(nums)
	rightAns := [][]int{
		{},
		{0}}
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
