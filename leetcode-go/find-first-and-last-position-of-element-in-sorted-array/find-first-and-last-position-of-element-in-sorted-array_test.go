package find_first_and_last_position_of_element_in_sorted_array

import (
	"reflect"
	"testing"
)

func TestSearchRangeExample1(t *testing.T) {
	nums := []int{5, 7, 7, 8, 8, 10}
	target := 8
	ans := searchRange(nums, target)
	rightAns := []int{3, 4}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchRangeExample2(t *testing.T) {
	nums := []int{5, 7, 7, 8, 8, 10}
	target := 6
	ans := searchRange(nums, target)
	rightAns := []int{-1, -1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchRangeExample3(t *testing.T) {
	var nums []int
	target := 0
	ans := searchRange(nums, target)
	rightAns := []int{-1, -1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
