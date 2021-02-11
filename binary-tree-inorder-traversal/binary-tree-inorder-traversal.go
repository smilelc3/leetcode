package binary_tree_inorder_traversal

import . "leetcode-go/built-in"

func inorderTraversal(root *TreeNode) []int {
	var ans []int
	if root == nil {
		return ans
	}
	ans = append(ans, inorderTraversal(root.Left)...)
	ans = append(ans, root.Val)
	ans = append(ans, inorderTraversal(root.Right)...)

	return ans
}
