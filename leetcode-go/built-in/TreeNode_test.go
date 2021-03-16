package built_in

import (
	"reflect"
	"testing"
)

func TestPreorderTraversalMorrisTest0(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Left = &TreeNode{Val: 2}
	root.Right = &TreeNode{Val: 3}
	root.Left.Left = &TreeNode{Val: 4}
	root.Left.Right = &TreeNode{Val: 5}
	root.Right.Left = &TreeNode{Val: 6}
	root.Right.Right = &TreeNode{Val: 7}

	var ans []int
	visitFunc := func(node *TreeNode) {
		ans = append(ans, node.Val)
	}
	PreorderTraversalMorris(root, visitFunc)
	rightAns := []int{1, 2, 4, 5, 3, 6, 7}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Tree")
	}
}

func TestInorderTraversalMorrisTest0(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Left = &TreeNode{Val: 2}
	root.Right = &TreeNode{Val: 3}
	root.Left.Left = &TreeNode{Val: 4}
	root.Left.Right = &TreeNode{Val: 5}
	root.Right.Left = &TreeNode{Val: 6}
	root.Right.Right = &TreeNode{Val: 7}

	var ans []int
	visitFunc := func(node *TreeNode) {
		ans = append(ans, node.Val)
	}
	InorderTraversalMorris(root, visitFunc)
	rightAns := []int{4, 2, 5, 1, 6, 3, 7}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Tree")
	}
}

func TestPostorderTraversalMorrisTest0(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Left = &TreeNode{Val: 2}
	root.Right = &TreeNode{Val: 3}
	root.Left.Left = &TreeNode{Val: 4}
	root.Left.Right = &TreeNode{Val: 5}
	root.Right.Left = &TreeNode{Val: 6}
	root.Right.Right = &TreeNode{Val: 7}

	var ans []int
	visitFunc := func(node *TreeNode) {
		ans = append(ans, node.Val)
	}
	PostorderTraversalMorris(root, visitFunc)
	rightAns := []int{4, 5, 2, 6, 7, 3, 1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Tree")
	}
}
