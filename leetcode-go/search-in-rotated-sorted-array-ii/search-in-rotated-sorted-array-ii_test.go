package search_in_rotated_sorted_array_ii

import "testing"

func TestSearchExample1(t *testing.T) {
	nums := []int{2, 5, 6, 0, 0, 1, 2}
	target := 0
	ans := search(nums, target)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchExample2(t *testing.T) {
	nums := []int{2, 5, 6, 0, 0, 1, 2}
	target := 3
	ans := search(nums, target)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchTest0(t *testing.T) {
	nums := []int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1}
	target := 2
	ans := search(nums, target)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
