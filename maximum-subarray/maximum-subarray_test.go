package maximum_subarray

import "testing"

func TestMaxSubArrayExample1(t *testing.T) {
	nums := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	ans := maxSubArray(nums)
	rightAns := 6
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxSubArrayExample2(t *testing.T) {
	nums := []int{1}
	ans := maxSubArray(nums)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxSubArrayExample3(t *testing.T) {
	nums := []int{0}
	ans := maxSubArray(nums)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxSubArrayExample4(t *testing.T) {
	nums := []int{-1}
	ans := maxSubArray(nums)
	rightAns := -1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxSubArrayExample5(t *testing.T) {
	nums := []int{-100000}
	ans := maxSubArray(nums)
	rightAns := -100000
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxSubArrayTest0(t *testing.T) {
	nums := []int{-2, -1}
	ans := maxSubArray(nums)
	rightAns := -1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
