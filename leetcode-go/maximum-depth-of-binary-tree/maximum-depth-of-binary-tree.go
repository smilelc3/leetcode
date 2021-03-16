package maximum_depth_of_binary_tree

import (
	. "leetcode-go/built-in"
)

func maxDepth(root *TreeNode) int {
	ansChan := make(chan int, 2)
	stopChan := make(chan struct{})
	defer close(stopChan)
	go func() {
		select {
		case <-stopChan:
			return
		case ansChan <- dfsDepth(root, 0):
		}
	}()
	go func() {
		select {
		case <-stopChan:
			return
		case ansChan <- bfsDepth(root):
		}
	}()
	ans := <-ansChan

	return ans
}

func dfsDepth(root *TreeNode, depth int) int {
	if root == nil {
		return depth
	}
	return Max(dfsDepth(root.Left, depth+1), dfsDepth(root.Right, depth+1))
}

func bfsDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	maxDepth := 0
	nodeQueue := []*TreeNode{root}
	for len(nodeQueue) != 0 {
		curQueueLength := len(nodeQueue)
		for idx := 0; idx < curQueueLength; idx++ {
			curNode := nodeQueue[idx]
			if curNode.Left != nil {
				nodeQueue = append(nodeQueue, curNode.Left)
			}
			if curNode.Right != nil {
				nodeQueue = append(nodeQueue, curNode.Right)
			}
		}
		nodeQueue = nodeQueue[curQueueLength:]
		maxDepth++
	}
	return maxDepth
}
