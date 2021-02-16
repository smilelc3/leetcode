package maximum_depth_of_binary_tree

import . "leetcode-go/built-in"

func maxDepth(root *TreeNode) int {
	return dfsDepth(root, 0)
}

func dfsDepth(root *TreeNode, depth int) int {
	if root == nil {
		return depth
	}
	return Max(dfsDepth(root.Left, depth+1), dfsDepth(root.Right, depth+1))
}
