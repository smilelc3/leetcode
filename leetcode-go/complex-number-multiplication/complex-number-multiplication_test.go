package complex_number_multiplication

import (
	"testing"
)

func TestComplexNumberMultiplyExample1(t *testing.T) {
	a := "1+1i"
	b := "1+1i"
	ans := complexNumberMultiply(a, b)
	rightAns := "0+2i"

	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestComplexNumberMultiplyExample2(t *testing.T) {
	a := "1+-1i"
	b := "1+-1i"
	ans := complexNumberMultiply(a, b)
	rightAns := "0+-2i"

	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestComplexNumberMultiplyTest0(t *testing.T) {
	a := "78+-76i"
	b := "-86+72i"
	ans := complexNumberMultiply(a, b)
	rightAns := "-1236+12152i"

	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
