package recover_binary_search_tree

import (
	. "leetcode-go/built-in"
	"reflect"
)
import "testing"

func TestRecoverTreeExample1(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Left = &TreeNode{Val: 3}
	root.Left.Right = &TreeNode{Val: 2}
	recoverTree(root)
	ans := root
	rightAns := &TreeNode{Val: 3}
	rightAns.Left = &TreeNode{Val: 1}
	rightAns.Left.Right = &TreeNode{Val: 2}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong tree")
	}
}

func TestRecoverTreeExample2(t *testing.T) {
	root := &TreeNode{Val: 3}
	root.Left = &TreeNode{Val: 1}
	root.Right = &TreeNode{Val: 4}
	root.Right.Left = &TreeNode{Val: 2}
	recoverTree(root)
	ans := root
	rightAns := &TreeNode{Val: 2}
	rightAns.Left = &TreeNode{Val: 1}
	rightAns.Right = &TreeNode{Val: 4}
	rightAns.Right.Left = &TreeNode{Val: 3}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong tree")
	}
}
