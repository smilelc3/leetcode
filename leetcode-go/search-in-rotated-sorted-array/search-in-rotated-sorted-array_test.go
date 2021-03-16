package search_in_rotated_sorted_array

import "testing"

func TestSearchExample1(t *testing.T) {
	nums := []int{4, 5, 6, 7, 0, 1, 2}
	target := 0
	ans := search(nums, target)
	rightAns := 4
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchExample2(t *testing.T) {
	nums := []int{4, 5, 6, 7, 0, 1, 2}
	target := 3
	ans := search(nums, target)
	rightAns := -1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchExample3(t *testing.T) {
	nums := []int{1}
	target := 0
	ans := search(nums, target)
	rightAns := -1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
