package partition_list

import (
	"reflect"
	"testing"
)
import . "leetcode-go/built-in"

func TestPartitionExample1(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 4}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 2}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	head.Next.Next.Next.Next.Next = &ListNode{Val: 2}
	x := 3
	ans := partition(head, x)
	rightAns := &ListNode{Val: 1}
	rightAns.Next = &ListNode{Val: 2}
	rightAns.Next.Next = &ListNode{Val: 2}
	rightAns.Next.Next.Next = &ListNode{Val: 4}
	rightAns.Next.Next.Next.Next = &ListNode{Val: 3}
	rightAns.Next.Next.Next.Next.Next = &ListNode{Val: 5}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestPartitionExample2(t *testing.T) {
	head := &ListNode{Val: 2}
	head.Next = &ListNode{Val: 1}
	x := 2
	ans := partition(head, x)
	rightAns := &ListNode{Val: 1}
	rightAns.Next = &ListNode{Val: 2}

	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}
