package merge_two_sorted_lists

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	// Both l1 and l2 are sorted in non-decreasing order.
	var mergeHead *ListNode
	if l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			mergeHead = l1
			mergeHead.Next = mergeTwoLists(l1.Next, l2)
		} else {
			mergeHead = l2
			mergeHead.Next = mergeTwoLists(l1, l2.Next)
		}
	} else if l1 != nil {
		mergeHead = l1
		mergeHead.Next = mergeTwoLists(l1.Next, l2)
	} else if l2 != nil {
		mergeHead = l2
		mergeHead.Next = mergeTwoLists(l1, l2.Next)
	}
	return mergeHead
}
