package remove_duplicates_from_sorted_list_ii

import . "leetcode-go/built-in-class"

func deleteDuplicates(head *ListNode) *ListNode {
	pNode := head
	var preNode *ListNode
	for pNode != nil {
		// 存在重复Node
		if pNode.Next != nil && pNode.Val == pNode.Next.Val {
			// 使该Node指向下一个和该Node值不等的Node，有可能为空
			for pNode.Next != nil && pNode.Val == pNode.Next.Val {
				pNode.Next = pNode.Next.Next
			}
			if preNode != nil {
				// 完全删除该和pNode值相等的Node
				preNode.Next = pNode.Next
				pNode = pNode.Next
			} else {
				// 遇到首位置就是重复节点
				head = pNode.Next
				pNode = pNode.Next
			}
		} else {
			// preNode可能未赋值，且该节点未重复
			preNode = pNode
			pNode = pNode.Next
		}
	}
	return head
}
