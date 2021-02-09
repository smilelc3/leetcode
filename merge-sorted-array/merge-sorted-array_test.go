package merge_sorted_array

import (
	"reflect"
	"testing"
)

func TestMergeExample1(t *testing.T) {
	nums1 := []int{1, 2, 3, 0, 0, 0}
	m := 3
	nums2 := []int{2, 5, 6}
	n := 3
	merge(nums1, m, nums2, n)
	ans := nums1
	rightAns := []int{1, 2, 2, 3, 5, 6}
	if !reflect.DeepEqual(rightAns, nums1) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMergeExample2(t *testing.T) {
	nums1 := []int{1}
	m := 1
	var nums2 []int
	n := 0
	merge(nums1, m, nums2, n)
	ans := nums1
	rightAns := []int{1}
	if !reflect.DeepEqual(rightAns, nums1) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMergeTest0(t *testing.T) {
	nums1 := []int{0}
	m := 0
	nums2 := []int{1}
	n := 1
	merge(nums1, m, nums2, n)
	ans := nums1
	rightAns := []int{1}
	if !reflect.DeepEqual(rightAns, nums1) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
