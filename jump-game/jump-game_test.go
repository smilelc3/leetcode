package jump_game

import "testing"

func TestCanJumpExample1(t *testing.T) {
	nums := []int{2, 3, 1, 1, 4}
	ans := canJump(nums)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestCanJumpExample2(t *testing.T) {
	nums := []int{3, 2, 1, 0, 4}
	ans := canJump(nums)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestCanJumpMyTest0(t *testing.T) {
	nums := []int{3}
	ans := canJump(nums)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestCanJumpMyTest1(t *testing.T) {
	nums := []int{0}
	ans := canJump(nums)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestCanJumpTest0(t *testing.T) {
	nums := []int{2, 0, 0}
	ans := canJump(nums)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestCanJumpTest1(t *testing.T) {
	nums := []int{2, 0, 0, 3, 0, 1, 4, 4}
	ans := canJump(nums)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}
