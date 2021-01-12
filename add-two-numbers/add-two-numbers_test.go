package add_two_numbers

import (
	"testing"
)

func TestAddTwoNumbersExample1(t *testing.T) {
	//	Input:
	//	Output: [7,0,8]
	//	Explanation: 342 + 465 = 807.
	l1 := []int{2, 4, 3}
	l2 := []int{5, 6, 4}
	Link1 := new(ListNode)
	Link2 := new(ListNode)

	preNode := Link1
	for idx, val := range l1 {
		preNode.Val = val
		if idx != len(l1)-1 {
			preNode.Next = new(ListNode)
			preNode = preNode.Next
		}
	}

	preNode = Link2
	for idx, val := range l2 {
		preNode.Val = val
		if idx != len(l2)-1 {
			preNode.Next = new(ListNode)
			preNode = preNode.Next
		}
	}

	ansLink := addTwoNumbers(Link1, Link2)
	if ansLink.Val != 7 ||
		ansLink.Next.Val != 0 ||
		ansLink.Next.Next.Val != 8 ||
		ansLink.Next.Next.Next != nil {
		t.Error("return Link = ", ansLink.Val, ansLink.Next.Val, ansLink.Next.Next.Val, ansLink.Next.Next.Next)
	}
}

func TestAddTwoNumbersExample2(t *testing.T) {
	l1 := []int{0}
	l2 := []int{0}
	Link1 := new(ListNode)
	Link2 := new(ListNode)

	preNode := Link1
	for idx, val := range l1 {
		preNode.Val = val
		if idx != len(l1)-1 {
			preNode.Next = new(ListNode)
			preNode = preNode.Next
		}
	}

	preNode = Link2
	for idx, val := range l2 {
		preNode.Val = val
		if idx != len(l2)-1 {
			preNode.Next = new(ListNode)
			preNode = preNode.Next
		}
	}

	ansLink := addTwoNumbers(Link1, Link2)
	if ansLink.Val != 0 ||
		ansLink.Next != nil {
		t.Error("return Link = ", ansLink.Val, ansLink.Next.Val, ansLink.Next.Next.Val, ansLink.Next.Next.Next)
	}
}

func TestAddTwoNumbersExample3(t *testing.T) {
	l1 := []int{9, 9, 9, 9, 9, 9, 9}
	l2 := []int{9, 9, 9, 9}
	Link1 := new(ListNode)
	Link2 := new(ListNode)

	preNode := Link1
	for idx, val := range l1 {
		preNode.Val = val
		if idx != len(l1)-1 {
			preNode.Next = new(ListNode)
			preNode = preNode.Next
		}
	}

	preNode = Link2
	for idx, val := range l2 {
		preNode.Val = val
		if idx != len(l2)-1 {
			preNode.Next = new(ListNode)
			preNode = preNode.Next
		}
	}
	//[8,9,9,9,0,0,0,1]
	ansLink := addTwoNumbers(Link1, Link2)
	if ansLink.Val != 8 ||
		ansLink.Next.Val != 9 ||
		ansLink.Next.Next.Val != 9 ||
		ansLink.Next.Next.Next.Val != 9 ||
		ansLink.Next.Next.Next.Next.Val != 0 ||
		ansLink.Next.Next.Next.Next.Next.Val != 0 ||
		ansLink.Next.Next.Next.Next.Next.Next.Val != 0 ||
		ansLink.Next.Next.Next.Next.Next.Next.Next.Val != 1 ||
		ansLink.Next.Next.Next.Next.Next.Next.Next.Next != nil {
		t.Error("return Link = ", ansLink.Val, ansLink.Next.Val, ansLink.Next.Next.Val, ansLink.Next.Next.Next)
	}
}
