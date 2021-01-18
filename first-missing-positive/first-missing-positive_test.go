package first_missing_positive

import "testing"

func TestFirstMissingPositiveExample1(t *testing.T) {
	nums := []int{1, 2, 0}
	ans := firstMissingPositive(nums)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFirstMissingPositiveExample2(t *testing.T) {
	nums := []int{3, 4, -1, 1}
	ans := firstMissingPositive(nums)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFirstMissingPositiveExample3(t *testing.T) {
	nums := []int{7, 8, 9, 11, 12}
	ans := firstMissingPositive(nums)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFirstMissingPositiveTest1(t *testing.T) {
	var nums []int
	ans := firstMissingPositive(nums)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
