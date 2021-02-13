package same_tree

import (
	. "leetcode-go/built-in"
	"testing"
)

func TestIsSameTreeExample1(t *testing.T) {
	p := &TreeNode{Val: 1}
	p.Left = &TreeNode{Val: 2}
	p.Right = &TreeNode{Val: 3}
	q := &TreeNode{Val: 1}
	q.Left = &TreeNode{Val: 2}
	q.Right = &TreeNode{Val: 3}
	ans := isSameTree(p, q)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsSameTreeExample2(t *testing.T) {
	p := &TreeNode{Val: 1}
	p.Left = &TreeNode{Val: 2}
	q := &TreeNode{Val: 1}
	q.Right = &TreeNode{Val: 2}
	ans := isSameTree(p, q)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsSameTreeExample3(t *testing.T) {
	p := &TreeNode{Val: 1}
	p.Left = &TreeNode{Val: 2}
	p.Right = &TreeNode{Val: 1}
	q := &TreeNode{Val: 1}
	q.Left = &TreeNode{Val: 1}
	q.Right = &TreeNode{Val: 2}
	ans := isSameTree(p, q)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
