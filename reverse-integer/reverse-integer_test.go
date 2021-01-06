package reverse_integer

import "testing"

func TestReverseExample1(t *testing.T) {
	x := 123
	ans := reverse(x)
	rightAns := 321
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReverseExample2(t *testing.T) {
	x := -123
	ans := reverse(x)
	rightAns := -321
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReverseExample3(t *testing.T) {
	x := 120
	ans := reverse(x)
	rightAns := 21
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReverseExample4(t *testing.T) {
	x := 0
	ans := reverse(x)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReverseIntOverflows(t *testing.T) {
	x := 1534236469
	ans := reverse(x)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans, " returns 0 when the reversed integer overflows")
	}
}
