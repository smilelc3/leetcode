package binary_tree_inorder_traversal

import . "leetcode-go/built-in"

func inorderTraversal(root *TreeNode) []int {
	// version 1: 递归实现 Space O(n)
	// return inorderTraversalBacktrack(root)

	// version 2: Morris遍历 Space O(1)
	var ans []int
	visitFunc := func(node *TreeNode) {
		ans = append(ans, node.Val)
	}
	InorderTraversalMorris(root, visitFunc)
	return ans
}

func inorderTraversalBacktrack(root *TreeNode) []int {
	var ans []int
	if root == nil {
		return ans
	}
	ans = append(ans, inorderTraversal(root.Left)...)
	ans = append(ans, root.Val)
	ans = append(ans, inorderTraversal(root.Right)...)
	return ans
}
