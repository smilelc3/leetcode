package remove_nth_node_from_end_of_list

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

func removeNthFromEndNormal(head *ListNode, n int) *ListNode {
	var pNodesArray []*ListNode
	pNode := head
	for pNode != nil {
		pNodesArray = append(pNodesArray, pNode)
		pNode = pNode.Next
	}
	if pNodesArray != nil {
		deleteNode := pNodesArray[len(pNodesArray)-1-(n-1)]
		if len(pNodesArray)-1-(n-1)-1 >= 0 {
			preNode := pNodesArray[len(pNodesArray)-1-(n-1)-1]
			preNode.Next = deleteNode.Next
		} else { // deleteNode == head
			head = deleteNode.Next
		}
	}
	return head
}

func removeNthFromEndScrollN(head *ListNode, n int) *ListNode {
	pNodesArray := make([]*ListNode, n+1)
	pNode := head
	idx := 0
	length := 0
	for pNode != nil {
		pNodesArray[idx%(n+1)] = pNode
		pNode = pNode.Next
		idx++
		idx %= n + 1
		length++
	}

	if length != 0 {
		deleteNode := pNodesArray[intRem(idx-n, n+1)]
		if length-1-(n-1)-1 >= 0 {
			preNode := pNodesArray[intRem(idx-n-1, n+1)]
			preNode.Next = deleteNode.Next
		} else { // deleteNode == head
			head = deleteNode.Next
		}
	}
	return head
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	// method 1  space: O(Link.length)
	//return removeNthFromEndNormal(head, n)

	// method 2 space: O(n)
	return removeNthFromEndScrollN(head, n)
}

func intRem(m int, n int) int {
	if m%n >= 0 {
		return m % n
	} else {
		return m%n + n
	}
}
