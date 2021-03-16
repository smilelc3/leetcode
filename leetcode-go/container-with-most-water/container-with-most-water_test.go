package container_with_most_water

import (
	"testing"
)

func TestMaxAreaExample1(t *testing.T) {
	height := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	ans := maxArea(height)
	rightAns := 49
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxAreaExample2(t *testing.T) {
	height := []int{1, 1}
	ans := maxArea(height)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxAreaExample3(t *testing.T) {
	height := []int{4, 3, 2, 1, 4}
	ans := maxArea(height)
	rightAns := 16
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMaxAreaExample4(t *testing.T) {
	height := []int{1, 2, 1}
	ans := maxArea(height)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
