package reverse_linked_list_ii

import (
	"reflect"
	"testing"
)
import . "leetcode-go/built-in"

func TestReverseBetweenExample(t *testing.T) {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	m := 2
	n := 4
	ans := reverseBetween(head, m, n)

	rightAns := &ListNode{Val: 1}
	rightAns.Next = &ListNode{Val: 4}
	rightAns.Next.Next = &ListNode{Val: 3}
	rightAns.Next.Next.Next = &ListNode{Val: 2}
	rightAns.Next.Next.Next.Next = &ListNode{Val: 5}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestReverseBetweenMyTest0(t *testing.T) {
	head := GenLinksByNums([]int{1, 1, 2, 3, 4, 5, 6})
	m := 2
	n := 6
	ans := reverseBetween(head, m, n)

	rightAns := GenLinksByNums([]int{1, 5, 4, 3, 2, 1, 6})
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestReverseBetweenMyTest1(t *testing.T) {
	head := GenLinksByNums([]int{1, 2, 3, 4, 5, 6})
	m := 1
	n := 5
	ans := reverseBetween(head, m, n)

	rightAns := GenLinksByNums([]int{5, 4, 3, 2, 1, 6})
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}

func TestReverseBetweenMyTest2(t *testing.T) {
	head := GenLinksByNums([]int{1, 2, 3, 4, 5, 6})
	m := 1
	n := 6
	ans := reverseBetween(head, m, n)

	rightAns := GenLinksByNums([]int{6, 5, 4, 3, 2, 1})
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("wrong Links")
	}
}
