package binary_tree_level_order_traversal

import (
	. "leetcode-go/built-in"
)

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	var ans [][]int
	queueNodes := []*TreeNode{root}
	for len(queueNodes) != 0 {
		curQueueLength := len(queueNodes)
		var sameLevel []int
		for idx := 0; idx < curQueueLength; idx++ {
			curNode := queueNodes[idx]
			sameLevel = append(sameLevel, curNode.Val)
			if curNode.Left != nil {
				queueNodes = append(queueNodes, curNode.Left)
			}
			if curNode.Right != nil {
				queueNodes = append(queueNodes, curNode.Right)
			}
		}
		ans = append(ans, sameLevel)
		queueNodes = queueNodes[curQueueLength:]
	}
	return ans
}
