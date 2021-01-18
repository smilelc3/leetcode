package trapping_rain_water

import "testing"

func TestTrapExample1(t *testing.T) {
	height := []int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
	ans := trap(height)
	rightAns := 6
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestTrapExample2(t *testing.T) {
	height := []int{4, 2, 0, 3, 2, 5}
	ans := trap(height)
	rightAns := 9
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
