package linked_list_cycle

import (
	. "leetcode-go/built-in"
	"testing"
)

func TestHasCycleExample1(t *testing.T) {
	head := GenLinksByNums([]int{3, 2, 0, -4})
	head.Next.Next.Next.Next = head.Next
	ans := hasCycle(head)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestHasCycleExample2(t *testing.T) {
	head := GenLinksByNums([]int{1, 2})
	head.Next.Next = head
	ans := hasCycle(head)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestHasCycleExample3(t *testing.T) {
	head := GenLinksByNums([]int{1})
	ans := hasCycle(head)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}
