package zigzag_conversion

import (
	"testing"
)

func TestConvertExample1(t *testing.T) {
	s := "PAYPALISHIRING"
	numRows := 3
	rightAns := "PAHNAPLSIIGYIR"
	ans := convert(s, numRows)
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestConvertExample2(t *testing.T) {
	s := "PAYPALISHIRING"
	numRows := 4
	rightAns := "PINALSIGYAHRPI"
	ans := convert(s, numRows)
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestConvertExample3(t *testing.T) {
	s := "A"
	numRows := 1
	rightAns := "A"
	ans := convert(s, numRows)
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
