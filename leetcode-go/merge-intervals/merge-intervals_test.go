package merge_intervals

import (
	"reflect"
	"testing"
)

func TestMergeExample1(t *testing.T) {
	intervals := [][]int{
		{1, 3},
		{2, 6},
		{8, 10},
		{15, 18}}
	ans := merge(intervals)
	rightAns := [][]int{{1, 6}, {8, 10}, {15, 18}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMergeExample2(t *testing.T) {
	intervals := [][]int{
		{1, 4},
		{4, 5}}
	ans := merge(intervals)
	rightAns := [][]int{{1, 5}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMergeTest0(t *testing.T) {
	intervals := [][]int{
		{1, 4},
		{2, 3}}
	ans := merge(intervals)
	rightAns := [][]int{{1, 4}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
