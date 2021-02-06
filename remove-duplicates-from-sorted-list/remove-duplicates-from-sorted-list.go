package remove_duplicates_from_sorted_list

import . "leetcode-go/built-in-class"

func deleteDuplicates(head *ListNode) *ListNode {
	pNode := head
	for pNode != nil {
		for pNode.Next != nil && pNode.Val == pNode.Next.Val {
			pNode.Next = pNode.Next.Next
		}
		pNode = pNode.Next
	}
	return head
}
