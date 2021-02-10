package reverse_linked_list_ii

import (
	. "leetcode-go/built-in"
)

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	// cost time: O(n)
	// space: O(1)
	idx := 1

	pNode := head
	var preNode, beginNode, endNode, nextNode *ListNode
	for idx <= n {
		if idx+1 == m {
			preNode = pNode
		}
		if idx == m {
			beginNode = pNode
		}
		if idx == n {
			endNode = pNode
			nextNode = pNode.Next
		}
		idx++
		pNode = pNode.Next
	}

	if beginNode == nil || endNode == nil {
		panic("n,m赋值错误")
	}
	headNode := beginNode
	tailNode := nextNode
	for headNode != nextNode {
		changeNode := headNode
		headNode = headNode.Next
		changeNode.Next = tailNode
		tailNode = changeNode
	}
	if preNode != nil {
		preNode.Next = endNode
		return head
	} else {
		return endNode
	}
}
