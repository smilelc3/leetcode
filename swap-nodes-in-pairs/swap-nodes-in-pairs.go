package swap_nodes_in_pairs

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

func swapPairs(head *ListNode) *ListNode {
	var preNode, aNode, bNode *ListNode
	pNode := head
	for pNode != nil {
		aNode = pNode
		bNode = pNode.Next
		swapTwoNode(preNode, aNode, bNode)
		if preNode == nil && bNode != nil {
			head = bNode
		}
		if pNode.Next != nil {
			preNode = pNode
			pNode = pNode.Next
		} else {
			break
		}
	}
	return head
}
func swapTwoNode(preNode *ListNode, aNode *ListNode, bNode *ListNode) {
	if bNode != nil {
		// not last Note
		aNode.Next = bNode.Next
		bNode.Next = aNode
		if preNode != nil {
			// not first Node
			preNode.Next = bNode
		}
	}
}
