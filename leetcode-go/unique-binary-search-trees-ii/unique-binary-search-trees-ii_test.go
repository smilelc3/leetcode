package unique_binary_search_trees_ii

import (
	. "leetcode-go/built-in"
	"reflect"
	"sort"
	"testing"
)

func TestGenerateTreesExample1(t *testing.T) {
	n := 3
	ans := generateTrees(n)

	if len(ans) != 5 {
		t.Error("wrong len(ans), current = ", len(ans), "expect = ", 6)
	}
	sort.Slice(ans, func(i, j int) bool {
		return lessBST(ans[i], ans[j])
	})

	Tree0 := &TreeNode{Val: 1}
	Tree0.Right = &TreeNode{Val: 3}
	Tree0.Right.Left = &TreeNode{Val: 2}
	Tree1 := &TreeNode{Val: 1}
	Tree1.Right = &TreeNode{Val: 2}
	Tree1.Right.Right = &TreeNode{Val: 3}
	Tree2 := &TreeNode{Val: 2}
	Tree2.Left = &TreeNode{Val: 1}
	Tree2.Right = &TreeNode{Val: 3}
	Tree3 := &TreeNode{Val: 3}
	Tree3.Left = &TreeNode{Val: 2}
	Tree3.Left.Left = &TreeNode{Val: 1}
	Tree4 := &TreeNode{Val: 3}
	Tree4.Left = &TreeNode{Val: 1}
	Tree4.Left.Right = &TreeNode{Val: 2}
	rightAns := []*TreeNode{Tree0, Tree1, Tree2, Tree3, Tree4}

	sort.Slice(rightAns, func(i, j int) bool {
		return lessBST(rightAns[i], rightAns[j])
	})
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Tree")
	}
}

func lessBST(treeA *TreeNode, treeB *TreeNode) bool {
	if treeA.Val != treeB.Val {
		return treeA.Val < treeB.Val
	} else {
		if treeA.Left != nil && treeB.Left != nil {
			return lessBST(treeA.Left, treeB.Left)
		}
		if treeA.Right != nil && treeB.Right != nil {
			return lessBST(treeA.Right, treeB.Right)
		}
	}
	return false
}

func TestGenerateTreesExample2(t *testing.T) {
	n := 1
	ans := generateTrees(n)

	if len(ans) != 1 {
		t.Error("wrong len(ans), current = ", len(ans), "expect = ", 1)
	}
	Tree0 := &TreeNode{Val: 1}
	if !reflect.DeepEqual(ans[0], Tree0) {
		t.Error("wrong Tree0")
	}
}
