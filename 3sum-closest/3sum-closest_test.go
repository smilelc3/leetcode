package three_sum_closest

import (
	"testing"
)

func TestThreeSumClosestExample1(t *testing.T) {
	nums := []int{-1, 2, 1, -4}
	target := 1
	ans := threeSumClosest(nums, target)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}
