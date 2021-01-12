package remove_nth_node_from_end_of_list

import (
	"testing"
)

func TestRemoveNthFromEndExample1(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	n := 2
	ans := removeNthFromEnd(head, n)

	if ans.Val != 1 ||
		ans.Next.Val != 2 ||
		ans.Next.Next.Val != 3 ||
		ans.Next.Next.Next.Val != 5 ||
		ans.Next.Next.Next.Next != nil {
		t.Error("wrong Links")
	}
}

func TestRemoveNthFromEndExample2(t *testing.T) {
	head := &ListNode{Val: 1}
	n := 1
	ans := removeNthFromEnd(head, n)

	if ans != nil {
		t.Error("wrong Links")
	}
}

func TestRemoveNthFromEndExample3(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	n := 1
	ans := removeNthFromEnd(head, n)

	if ans.Val != 1 ||
		ans.Next != nil {
		t.Error("wrong Links")
	}
}
