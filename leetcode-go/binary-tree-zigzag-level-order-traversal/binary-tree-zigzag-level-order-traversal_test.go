package binary_tree_zigzag_level_order_traversal

import (
	. "leetcode-go/built-in"
	"reflect"
	"testing"
)

func TestLevelOrderExample1(t *testing.T) {
	nums := []int{3, 9, 20, -1, -1, 15, 7}
	root := GenTreeByNums(nums, -1)
	ans := zigzagLevelOrder(root)
	rightAns := [][]int{
		{3},
		{20, 9},
		{15, 7}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLevelOrderTest0(t *testing.T) {
	nums := []int{1, 2, 3, 4, -1, -1, 5}
	root := GenTreeByNums(nums, -1)
	ans := zigzagLevelOrder(root)
	rightAns := [][]int{
		{1},
		{3, 2},
		{4, 5}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
