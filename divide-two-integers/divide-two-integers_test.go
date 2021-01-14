package divide_two_integers

import (
	"math"
	"testing"
)

func TestDivideExample1(t *testing.T) {
	dividend := 10
	divisor := 3
	ans := divide(dividend, divisor)
	rightAns := dividend / divisor
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestDivideExample2(t *testing.T) {
	dividend := 7
	divisor := -3
	ans := divide(dividend, divisor)
	rightAns := dividend / divisor
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestDivideExample3(t *testing.T) {
	dividend := 0
	divisor := 1
	ans := divide(dividend, divisor)
	rightAns := dividend / divisor
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestDivideExample4(t *testing.T) {
	dividend := 1
	divisor := 1
	ans := divide(dividend, divisor)
	rightAns := dividend / divisor
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestDivideOverflow(t *testing.T) {
	dividend := -2147483648
	divisor := -1
	ans := divide(dividend, divisor)
	rightAns := math.MaxInt32
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestDivideFetchOverflow(t *testing.T) {
	dividend := -2147483648
	divisor := 1
	ans := divide(dividend, divisor)
	rightAns := math.MinInt32
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
