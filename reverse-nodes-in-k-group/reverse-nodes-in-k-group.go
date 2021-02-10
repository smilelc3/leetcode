package reverse_nodes_in_k_group

import . "leetcode-go/built-in"

func reverseKGroup(head *ListNode, k int) *ListNode {
	// space cost O(1)
	var reverseHead *ListNode
	var preNode, startNode, endNode, nextNode *ListNode
	idx := 0
	pNode := head
	for pNode != nil {
		if idx%k == 0 {
			startNode = pNode
		}
		if idx%k == k-1 {
			endNode = pNode
			nextNode = pNode.Next
			// find a k group
			reverseSinglyLink(startNode, endNode)
			startNode, endNode = endNode, startNode
			if reverseHead == nil {
				reverseHead = startNode
			}
			if preNode != nil {
				preNode.Next = startNode
			}
			if endNode != nil {
				endNode.Next = nextNode
			}
			preNode = endNode
			pNode = nextNode
		} else {
			pNode = pNode.Next
		}
		idx++
	}
	return reverseHead
}

// 反转单向链表
func reverseSinglyLink(startNode, endNode *ListNode) {
	// reverse a link return head Node
	pNode := startNode
	var nextNode, preNode *ListNode
	for preNode != endNode {
		nextNode = pNode.Next
		// reverse node
		pNode.Next = preNode
		preNode = pNode
		pNode = nextNode
	}
}
