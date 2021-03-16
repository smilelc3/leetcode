package search_insert_position

import (
	"testing"
)

func TestSearchInsertExample1(t *testing.T) {
	nums := []int{1, 3, 5, 6}
	target := 5
	ans := searchInsert(nums, target)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchInsertExample2(t *testing.T) {
	nums := []int{1, 3, 5, 6}
	target := 2
	ans := searchInsert(nums, target)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchInsertExample3(t *testing.T) {
	nums := []int{1, 3, 5, 6}
	target := 7
	ans := searchInsert(nums, target)
	rightAns := 4
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchInsertExample4(t *testing.T) {
	nums := []int{1, 3, 5, 6}
	target := 0
	ans := searchInsert(nums, target)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSearchInsertExample5(t *testing.T) {
	nums := []int{1}
	target := 0
	ans := searchInsert(nums, target)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
