package multiply_strings

import (
	"testing"
)

func TestMultiplyExample1(t *testing.T) {
	num1 := "2"
	num2 := "3"
	ans := multiply(num1, num2)
	rightAns := "6"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMultiplyExample2(t *testing.T) {
	num1 := "123"
	num2 := "456"
	ans := multiply(num1, num2)
	rightAns := "56088"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMultiplyTest0(t *testing.T) {
	num1 := "9133"
	num2 := "0"
	ans := multiply(num1, num2)
	rightAns := "0"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMultiplyTest1(t *testing.T) {
	num1 := "5"
	num2 := "12"
	ans := multiply(num1, num2)
	rightAns := "60"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
