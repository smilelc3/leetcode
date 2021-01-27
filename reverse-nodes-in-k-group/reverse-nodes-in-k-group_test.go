package reverse_nodes_in_k_group

import (
	. "leetcode-go/built-in-class"
	"testing"
)

func TestReverseKGroupExample1(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	k := 2
	ans := reverseKGroup(head, k)
	if ans.Val != 2 ||
		ans.Next.Val != 1 ||
		ans.Next.Next.Val != 4 ||
		ans.Next.Next.Next.Val != 3 ||
		ans.Next.Next.Next.Next.Val != 5 ||
		ans.Next.Next.Next.Next.Next != nil {
		t.Error("wrong Links")
	}
}

func TestReverseKGroupExample2(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	k := 3
	ans := reverseKGroup(head, k)
	if ans.Val != 3 ||
		ans.Next.Val != 2 ||
		ans.Next.Next.Val != 1 ||
		ans.Next.Next.Next.Val != 4 ||
		ans.Next.Next.Next.Next.Val != 5 ||
		ans.Next.Next.Next.Next.Next != nil {
		t.Error("wrong Links")
	}
}

func TestReverseKGroupExample3(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	k := 1
	ans := reverseKGroup(head, k)
	if ans.Val != 1 ||
		ans.Next.Val != 2 ||
		ans.Next.Next.Val != 3 ||
		ans.Next.Next.Next.Val != 4 ||
		ans.Next.Next.Next.Next.Val != 5 ||
		ans.Next.Next.Next.Next.Next != nil {
		t.Error("wrong Links")
	}
}

func TestReverseKGroupExample4(t *testing.T) {
	head := &ListNode{Val: 1}
	k := 1
	ans := reverseKGroup(head, k)
	if ans.Val != 1 ||
		ans.Next != nil {
		t.Error("wrong Links")
	}
}

func TestReverseSingleLink(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	tail := head.Next.Next.Next.Next
	reverseSinglyLink(head, tail)
	head, tail = tail, head
	if head.Val != 5 ||
		head.Next.Val != 4 ||
		head.Next.Next.Val != 3 ||
		head.Next.Next.Next.Val != 2 ||
		head.Next.Next.Next.Next.Val != 1 ||
		head.Next.Next.Next.Next.Next != nil {
		t.Error("wrong Links")
	}
}
