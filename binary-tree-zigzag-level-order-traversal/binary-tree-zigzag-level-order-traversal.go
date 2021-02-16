package binary_tree_zigzag_level_order_traversal

import (
	. "leetcode-go/built-in"
)

func zigzagLevelOrder(root *TreeNode) [][]int {
	var ans [][]int
	if root == nil {
		return ans
	}
	// root非空
	bfsQueue := []*TreeNode{root}
	level := 1 // 层级
	for len(bfsQueue) != 0 {
		curQueueLength := len(bfsQueue)
		curLevel := make([]int, curQueueLength, curQueueLength)
		for idx := 0; idx < curQueueLength; idx++ {
			var pNode *TreeNode
			pNode = bfsQueue[idx]
			if pNode.Left != nil {
				bfsQueue = append(bfsQueue, pNode.Left)
			}
			if pNode.Right != nil {
				bfsQueue = append(bfsQueue, pNode.Right)
			}
			if level&1 == 1 {
				curLevel[idx] = pNode.Val
			} else {
				curLevel[curQueueLength-idx-1] = pNode.Val
			}
		}
		ans = append(ans, curLevel)
		bfsQueue = bfsQueue[curQueueLength:]
		level++
	}
	return ans
}
