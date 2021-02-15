package binary_tree_level_order_traversal

import (
	. "leetcode-go/built-in"
	"reflect"
	"testing"
)

func TestLevelOrderExample1(t *testing.T) {
	nums := []int{3, 9, 20, -1, -1, 15, 7}
	root := GenTreeByNums(nums, -1)
	ans := levelOrder(root)
	rightAns := [][]int{
		{3},
		{9, 20},
		{15, 7},
	}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
