package partition_list

import . "leetcode-go/built-in-class"

func partition(head *ListNode, x int) *ListNode {
	var greaterHead, greaterTail *ListNode
	var LessHead, LessTail *ListNode
	pNode := head
	for pNode != nil {
		if pNode.Val < x {
			if LessHead == nil || LessTail == nil {
				LessHead = pNode
				LessTail = pNode
			} else {
				LessTail.Next = pNode
				LessTail = LessTail.Next
			}

		} else {
			if greaterHead == nil || greaterTail == nil {
				greaterHead = pNode
				greaterTail = pNode
			} else {
				greaterTail.Next = pNode
				greaterTail = greaterTail.Next
			}
		}
		pNode = pNode.Next
	}

	// connect two link
	if LessTail != nil {
		LessTail.Next = greaterHead
		return LessHead
	} else {
		return greaterHead
	}

}
