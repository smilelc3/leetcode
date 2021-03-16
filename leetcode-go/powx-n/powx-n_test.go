package powx_n

import (
	"math"
	"testing"
)

func TestMyPowExample1(t *testing.T) {
	x := 2.00000
	n := 10
	ans := myPow(x, n)
	rightAns := math.Pow(x, float64(n))
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMyPowExample2(t *testing.T) {
	x := 2.10000
	n := 3
	ans := myPow(x, n)
	rightAns := math.Pow(x, float64(n))
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMyPowExample3(t *testing.T) {
	x := 2.00000
	n := -2
	ans := myPow(x, n)
	rightAns := math.Pow(x, float64(n))
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMyPowTest0(t *testing.T) {
	x := 0.44528
	n := 0
	ans := myPow(x, n)
	rightAns := math.Pow(x, float64(n))
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
