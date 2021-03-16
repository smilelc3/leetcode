package validate_binary_search_tree

import (
	. "leetcode-go/built-in"
)

func isValidBST(root *TreeNode) bool {
	return isValidBSTMinMax(root, MinInt, MaxInt)
}

func isValidBSTMinMax(root *TreeNode, min, max int) bool {
	if root == nil {
		return true
	}
	if root.Val <= min || root.Val >= max {
		return false
	}
	return isValidBSTMinMax(root.Left, min, root.Val) && isValidBSTMinMax(root.Right, root.Val, max)
}
