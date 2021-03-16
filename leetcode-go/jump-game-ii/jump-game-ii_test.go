package jump_game_ii

import (
	"testing"
)

func TestJumpExample1(t *testing.T) {
	nums := []int{2, 3, 1, 1, 4}
	ans := jump(nums)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestJumpExample2(t *testing.T) {
	nums := []int{2, 3, 0, 1, 4}
	ans := jump(nums)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestJumpTest0(t *testing.T) {
	nums := []int{1}
	ans := jump(nums)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestJumpTest1(t *testing.T) {
	nums := []int{1, 2, 1, 1, 1}
	ans := jump(nums)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestJumpTest2(t *testing.T) {
	nums := []int{2, 3, 1}
	ans := jump(nums)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}
