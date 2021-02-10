package remove_duplicates_from_sorted_list_ii

import (
	. "leetcode-go/built-in"
	"reflect"
	"testing"
)

func TestDeleteDuplicatesExample1(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next.Next.Next = &ListNode{Val: 5}

	ans := deleteDuplicates(head)

	rightAns := &ListNode{Val: 1}
	rightAns.Next = &ListNode{Val: 2}
	rightAns.Next.Next = &ListNode{Val: 5}

	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestDeleteDuplicatesExample2(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 1}
	head.Next.Next = &ListNode{Val: 1}
	head.Next.Next.Next = &ListNode{Val: 2}
	head.Next.Next.Next.Next = &ListNode{Val: 3}

	ans := deleteDuplicates(head)

	rightAns := &ListNode{Val: 2}
	rightAns.Next = &ListNode{Val: 3}

	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestDeleteDuplicatesTest0(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 1}

	ans := deleteDuplicates(head)

	var rightAns *ListNode

	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestDeleteDuplicatesTest1(t *testing.T) {
	var head *ListNode
	ans := deleteDuplicates(head)
	var rightAns *ListNode
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestDeleteDuplicatesTest2(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 1}
	head.Next.Next = &ListNode{Val: 2}
	head.Next.Next.Next = &ListNode{Val: 2}

	ans := deleteDuplicates(head)

	var rightAns *ListNode

	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}
