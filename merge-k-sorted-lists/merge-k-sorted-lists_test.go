package merge_k_sorted_lists

import "testing"
import . "leetcode-go/built-in-class"

func TestMergeKListsExample1(t *testing.T) {
	l1 := &ListNode{Val: 1}
	l1.Next = &ListNode{Val: 4}
	l1.Next.Next = &ListNode{Val: 5}

	l2 := &ListNode{Val: 1}
	l2.Next = &ListNode{Val: 3}
	l2.Next.Next = &ListNode{Val: 4}

	l3 := &ListNode{Val: 2}
	l3.Next = &ListNode{Val: 6}

	lists := []*ListNode{l1, l2, l3}

	ansLink := mergeKLists(lists)

	rightAns := []int{1, 1, 2, 3, 4, 4, 5, 6}

	for idx, val := range rightAns {
		if ansLink == nil {
			t.Error("short length link")
			break
		}
		if ansLink.Val != val {
			t.Error("wrong val link, location = ", idx, "right value = ", val, "your ans = ", ansLink.Val)
			break
		}
		ansLink = ansLink.Next
	}
	if ansLink != nil {
		t.Error("extent length link")
	}

}

func TestMergeKListsExample2(t *testing.T) {
	var l1 *ListNode
	lists := []*ListNode{l1}
	ansLink := mergeKLists(lists)
	if ansLink != nil {
		t.Error("extent length link")
	}
}

func TestMergeKListsExample3(t *testing.T) {
	var lists []*ListNode
	ansLink := mergeKLists(lists)
	if ansLink != nil {
		t.Error("extent length link")
	}
}

func TestMergeKListsTest0(t *testing.T) {
	l1 := &ListNode{Val: 1}
	lists := []*ListNode{l1}
	ansLink := mergeKLists(lists)
	if ansLink.Val != 1 ||
		ansLink.Next != nil {
		t.Error("extent length link")
	}
}

func TestMergeKListsTest1(t *testing.T) {
	var l1 *ListNode
	l2 := &ListNode{Val: 1}
	lists := []*ListNode{l1, l2}
	ansLink := mergeKLists(lists)
	if ansLink.Val != 1 ||
		ansLink.Next != nil {
		t.Error("extent length link")
	}
}
