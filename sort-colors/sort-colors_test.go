package sort_colors

import (
	"reflect"
	"testing"
)

func TestSortColorsExample1(t *testing.T) {
	nums := []int{2, 0, 2, 1, 1, 0}
	ans := nums
	sortColors(nums)
	rightAns := []int{0, 0, 1, 1, 2, 2}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSortColorsExample2(t *testing.T) {
	nums := []int{2, 0, 1}
	ans := nums
	sortColors(nums)
	rightAns := []int{0, 1, 2}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSortColorsExample3(t *testing.T) {
	nums := []int{0}
	ans := nums
	sortColors(nums)
	rightAns := []int{0}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSortColorsExample4(t *testing.T) {
	nums := []int{1}
	ans := nums
	sortColors(nums)
	rightAns := []int{1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
