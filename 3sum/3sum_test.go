package three_sum

import (
	"reflect"
	"testing"
)

func TestThreeSumExample1(t *testing.T) {
	nums := []int{-1, 0, 1, 2, -1, -4}
	ans := threeSum(nums)
	rightAns1 := [][]int{{-1, -1, 2}, {-1, 0, 1}}
	rightAns2 := [][]int{{-1, 0, 1}, {-1, -1, 2}}
	if !reflect.DeepEqual(ans, rightAns1) && !reflect.DeepEqual(ans, rightAns2) {
		t.Error("right ans = ", rightAns1, "or", rightAns2, ", current ans = ", ans)
	}
}

func TestThreeSumExample2(t *testing.T) {
	var nums []int
	ans := threeSum(nums)
	var rightAns [][]int
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestThreeSumExample3(t *testing.T) {
	nums := []int{0}
	ans := threeSum(nums)
	var rightAns [][]int
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestThreeSumMyInput1(t *testing.T) {
	nums := []int{-2, 0, 1, 1, 2}
	ans := threeSum(nums)
	rightAns1 := [][]int{{-2, 0, 2}, {-2, 1, 1}}
	rightAns2 := [][]int{{-2, 1, 1}, {-2, 0, 2}}
	if !reflect.DeepEqual(ans, rightAns1) && !reflect.DeepEqual(ans, rightAns2) {
		t.Error("right ans = ", rightAns1, "or", rightAns2, ", current ans = ", ans)
	}
}

func TestThreeSumMyInput2(t *testing.T) {
	nums := []int{-1, 0, 1, 2, -1, -4} //-4, -1, -1, 0, 1, 2
	ans := threeSum(nums)
	rightAns1 := [][]int{{-1, -1, 2}, {-1, 0, 1}}
	rightAns2 := [][]int{{-1, 0, 1}, {-1, -1, 2}}
	if !reflect.DeepEqual(ans, rightAns1) && !reflect.DeepEqual(ans, rightAns2) {
		t.Error("right ans = ", rightAns1, "or", rightAns2, ", current ans = ", ans)
	}
}
