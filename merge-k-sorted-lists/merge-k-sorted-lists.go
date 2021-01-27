package merge_k_sorted_lists

import "math"

import . "leetcode-go/built-in-class"

func mergeKLists(lists []*ListNode) *ListNode {
	// method 1 递归 250ms  O(lists.length * max(lists[i].length))
	//return mergeKListsWithBacktrack(lists)

	// method 2 分治 8ms  O(log(lists.length) * max(lists[i].length))
	return mergeKListsWithDivideConquer(lists)
}

func mergeKListsWithDivideConquer(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	left := 0
	mid := len(lists) / 2
	right := len(lists) - 1
	if left == right {
		// len(lists) == 1
		return lists[0]
	}

	leftHalfHead := mergeKListsWithDivideConquer(lists[:mid])
	rightHalfHead := mergeKListsWithDivideConquer(lists[mid:])

	return mergeTwoLists(leftHalfHead, rightHalfHead)
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

func mergeKListsWithBacktrack(lists []*ListNode) *ListNode {
	var mergeHead *ListNode
	if !isListsAllNil(lists) {
		minNode := &ListNode{Val: math.MaxInt32}
		minIdx := -1
		for idx, node := range lists {
			if node != nil && node.Val < minNode.Val {
				minNode = node
				minIdx = idx
			}
		}
		mergeHead = minNode
		nextLists := append(lists[:minIdx], minNode.Next)
		if minIdx+1 < len(lists) {
			nextLists = append(nextLists, lists[minIdx+1:]...)
		}
		mergeHead.Next = mergeKListsWithBacktrack(nextLists)
	}
	return mergeHead
}

func isListsAllNil(lists []*ListNode) bool {
	isNil := true
	for _, node := range lists {
		if node != nil {
			isNil = false
			break
		}
	}
	return isNil
}
