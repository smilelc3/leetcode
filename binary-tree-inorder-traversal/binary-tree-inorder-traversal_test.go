package binary_tree_inorder_traversal

import (
	. "leetcode-go/built-in"
	"reflect"
	"testing"
)

func TestInorderTraversalExample1(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Right = &TreeNode{Val: 2}
	root.Right.Left = &TreeNode{Val: 3}
	ans := inorderTraversal(root)
	rightAns := []int{1, 3, 2}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Tree")
	}
}

func TestInorderTraversalExample2(t *testing.T) {
	var root *TreeNode
	ans := inorderTraversal(root)
	var rightAns []int
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Tree")
	}
}

func TestInorderTraversalExample3(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Left = &TreeNode{Val: 2}
	ans := inorderTraversal(root)
	rightAns := []int{2, 1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Tree")
	}
}
func TestInorderTraversalExample4(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Right = &TreeNode{Val: 2}
	ans := inorderTraversal(root)
	rightAns := []int{1, 2}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Tree")
	}
}
