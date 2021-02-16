package maximum_depth_of_binary_tree

import (
	. "leetcode-go/built-in"
	"testing"
)

func TestMaxDepthExample1(t *testing.T) {
	nums := []int{3, 9, 20, -1, -1, 15, 7}
	root := GenTreeByNums(nums, -1)
	ans := maxDepth(root)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxDepthExample2(t *testing.T) {
	nums := []int{1, -1, 2}
	root := GenTreeByNums(nums, -1)
	ans := maxDepth(root)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxDepthExample3(t *testing.T) {
	var nums []int
	root := GenTreeByNums(nums, -1)
	ans := maxDepth(root)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxDepthExample4(t *testing.T) {
	nums := []int{0}
	root := GenTreeByNums(nums, -1)
	ans := maxDepth(root)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
