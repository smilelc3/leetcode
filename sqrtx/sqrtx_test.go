package sqrtx

import (
	"testing"
)

func TestMySqrtExample1(t *testing.T) {
	x := 4
	ans := mySqrt(x)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMySqrtExample2(t *testing.T) {
	x := 8
	ans := mySqrt(x)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMySqrtTest0(t *testing.T) {
	x := 1
	ans := mySqrt(x)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMySqrtTest1(t *testing.T) {
	x := 2
	ans := mySqrt(x)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
