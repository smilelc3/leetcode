package add_binary

import (
	"testing"
)

func TestAddBinaryExample1(t *testing.T) {
	a := "11"
	b := "1"
	ans := addBinary(a, b)
	rightAns := "100"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestAddBinaryExample2(t *testing.T) {
	a := "1010"
	b := "1011"
	ans := addBinary(a, b)
	rightAns := "10101"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestAddBinaryTest0(t *testing.T) {
	a := "0"
	b := "0"
	ans := addBinary(a, b)
	rightAns := "0"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestAddBinaryTest1(t *testing.T) {
	a := "1111"
	b := "1111"
	ans := addBinary(a, b)
	rightAns := "11110"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
