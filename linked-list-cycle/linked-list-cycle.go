package linked_list_cycle

import . "leetcode-go/built-in"

func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil || head.Next.Next == nil {
		return false
	}
	slow := head.Next
	fast := head.Next.Next

	for fast != slow && fast.Next != nil && slow.Next != nil {
		slow = slow.Next
		fast = fast.Next
		if fast.Next != nil {
			fast = fast.Next
		} else {
			return false
		}
	}
	return fast == slow
}
