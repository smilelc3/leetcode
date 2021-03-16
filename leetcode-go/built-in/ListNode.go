package built_in

type ListNode struct {
	Val  int
	Next *ListNode
}

func GenLinksByNums(nums []int) *ListNode {
	var head, preNode *ListNode
	for idx := 0; idx < len(nums); idx++ {
		curNode := &ListNode{
			Val: nums[idx],
		}
		if idx == 0 || preNode == nil {
			head = curNode
			preNode = curNode
		} else {
			preNode.Next = curNode
			preNode = preNode.Next
		}
	}
	return head
}
