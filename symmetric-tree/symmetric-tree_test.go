package symmetric_tree

import (
	. "leetcode-go/built-in"
	"testing"
)

func TestIsSymmetricExample1(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Right = &TreeNode{Val: 2}
	root.Left = &TreeNode{Val: 2}
	root.Right.Right = &TreeNode{Val: 3}
	root.Right.Left = &TreeNode{Val: 4}
	root.Left.Right = &TreeNode{Val: 4}
	root.Left.Left = &TreeNode{Val: 3}
	ans := isSymmetric(root)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsSymmetricExample2(t *testing.T) {
	root := &TreeNode{Val: 1}
	root.Right = &TreeNode{Val: 2}
	root.Left = &TreeNode{Val: 2}
	root.Right.Left = &TreeNode{Val: 3}
	root.Left.Left = &TreeNode{Val: 3}
	ans := isSymmetric(root)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
