package rotate_list

import (
	. "leetcode-go/built-in"
	"reflect"
	"testing"
)

func TestRotateRightExample1(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	k := 2
	ans := rotateRight(head, k)
	rightAns := &ListNode{Val: 4}
	rightAns.Next = &ListNode{Val: 5}
	rightAns.Next.Next = &ListNode{Val: 1}
	rightAns.Next.Next.Next = &ListNode{Val: 2}
	rightAns.Next.Next.Next.Next = &ListNode{Val: 3}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestRotateRightExample2(t *testing.T) {
	head := &ListNode{Val: 0}
	head.Next = &ListNode{Val: 1}
	head.Next.Next = &ListNode{Val: 2}
	k := 4
	ans := rotateRight(head, k)
	rightAns := &ListNode{Val: 2}
	rightAns.Next = &ListNode{Val: 0}
	rightAns.Next.Next = &ListNode{Val: 1}

	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}
