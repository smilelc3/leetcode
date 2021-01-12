package merge_two_sorted_lists

import "testing"

func TestMergeTwoListsExample1(t *testing.T) {
	l1 := &ListNode{Val: 1}
	l1.Next = &ListNode{Val: 2}
	l1.Next.Next = &ListNode{Val: 4}

	l2 := &ListNode{Val: 1}
	l2.Next = &ListNode{Val: 3}
	l2.Next.Next = &ListNode{Val: 4}

	ans := mergeTwoLists(l1, l2)

	if ans.Val != 1 ||
		ans.Next.Val != 1 ||
		ans.Next.Next.Val != 2 ||
		ans.Next.Next.Next.Val != 3 ||
		ans.Next.Next.Next.Next.Val != 4 ||
		ans.Next.Next.Next.Next.Next.Val != 4 ||
		ans.Next.Next.Next.Next.Next.Next != nil {
		t.Error("wrong Links")
	}
}

func TestMergeTwoListsExample2(t *testing.T) {
	var l1, l2 *ListNode
	ans := mergeTwoLists(l1, l2)
	if ans != nil {
		t.Error("wrong Links")
	}
}

func TestMergeTwoListsExample3(t *testing.T) {
	var l1 *ListNode
	l2 := &ListNode{Val: 0}
	ans := mergeTwoLists(l1, l2)
	if ans.Val != 0 ||
		ans.Next != nil {
		t.Error("wrong Links")
	}
}
