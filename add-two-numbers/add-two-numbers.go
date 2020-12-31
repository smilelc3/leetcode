package add_two_numbers

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

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	ansLink := new(ListNode)
	pAnsNode := ansLink
	pNode1 := l1
	pNode2 := l2
	for pNode1 != nil || pNode2 != nil {
		if pNode1 != nil {
			pAnsNode.Val += pNode1.Val
			pNode1 = pNode1.Next
		}
		if pNode2 != nil {
			pAnsNode.Val += pNode2.Val
			pNode2 = pNode2.Next
		}
		if pAnsNode.Val >= 10 || pNode1 != nil || pNode2 != nil {
			pAnsNode.Next = new(ListNode)
			if pAnsNode.Val >= 10 {
				pAnsNode.Next.Val = pAnsNode.Val / 10
				pAnsNode.Val = pAnsNode.Val % 10
			}
			pAnsNode = pAnsNode.Next
		}
	}
	return ansLink
}
