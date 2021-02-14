package recover_binary_search_tree

import . "leetcode-go/built-in"

func recoverTree(root *TreeNode) {
	var first, second, pre *TreeNode

	visitFunc := func(curNode *TreeNode) {
		if pre != nil && curNode.Val < pre.Val {
			if first == nil {
				first = pre
			}
			second = curNode
		}
		pre = curNode
	}
	InorderTraversalMorris(root, visitFunc)
	// swap
	first.Val, second.Val = second.Val, first.Val
}
