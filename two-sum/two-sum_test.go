package two_sum

import (
	"reflect"
	"sort"
	"testing"
)

func TestTwoSumExample1(t *testing.T) {
	nums := []int{3, 2, 4}
	target := 6
	ans := twoSum(nums, target)
	rightAns := []int{1, 2}
	sort.Ints(ans)
	sort.Ints(rightAns)
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestTwoSumExample2(t *testing.T) {
	nums := []int{3, 3}
	target := 6
	ans := twoSum(nums, target)
	rightAns := []int{0, 1}
	sort.Ints(ans)
	sort.Ints(rightAns)
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
