package same_tree

import . "leetcode-go/built-in"

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	} else if p != nil && q != nil && p.Val == q.Val {
		if isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right) {
			return true
		} else {
			return false
		}
	} else {
		return false
	}
}
