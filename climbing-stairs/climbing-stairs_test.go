package climbing_stairs

import (
	"testing"
)

func TestClimbStairsExample1(t *testing.T) {
	n := 2
	ans := climbStairs(n)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestClimbStairsExample2(t *testing.T) {
	n := 3
	ans := climbStairs(n)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestClimbStairsExample3(t *testing.T) {
	n := 44
	ans := climbStairs(n)
	rightAns := 1134903170
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
