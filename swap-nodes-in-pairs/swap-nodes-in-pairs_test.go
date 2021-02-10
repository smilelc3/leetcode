package swap_nodes_in_pairs

import (
	. "leetcode-go/built-in"
	"testing"
)

func TestSwapPairsExample1(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	ans := swapPairs(head)
	if ans.Val != 2 ||
		ans.Next.Val != 1 ||
		ans.Next.Next.Val != 4 ||
		ans.Next.Next.Next.Val != 3 ||
		ans.Next.Next.Next.Next != nil {
		t.Error("wrong Links")
	}
}

func TestSwapPairsExample2(t *testing.T) {
	var head *ListNode
	ans := swapPairs(head)
	if ans != nil {
		t.Error("wrong Links")
	}
}

func TestSwapPairsExample3(t *testing.T) {
	head := &ListNode{Val: 1}
	ans := swapPairs(head)
	if ans.Val != 1 ||
		ans.Next != nil {
		t.Error("wrong Links")
	}
}

func TestSwapPairsTest0(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	ans := swapPairs(head)
	if ans.Val != 2 ||
		ans.Next.Val != 1 ||
		ans.Next.Next.Val != 3 ||
		ans.Next.Next.Next != nil {
		t.Error("wrong Links")
	}
}
