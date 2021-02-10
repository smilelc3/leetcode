package rotate_list

import . "leetcode-go/built-in"

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	length := 1
	pNode := head
	for pNode.Next != nil {
		length++
		pNode = pNode.Next
	}
	tail := pNode

	k = k % length

	pNode = head
	idx := 0

	for idx+1 < length-k {
		pNode = pNode.Next
		idx++
	}
	realTail := pNode

	tail.Next = head
	head = realTail.Next
	realTail.Next = nil
	return head
}
