package roman_to_integer

import (
	"testing"
)

func TestRomanToIntExample1(t *testing.T) {
	s := "III"
	ans := romanToInt(s)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRomanToIntExample2(t *testing.T) {
	s := "IV"
	ans := romanToInt(s)
	rightAns := 4
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRomanToIntExample3(t *testing.T) {
	s := "IX"
	ans := romanToInt(s)
	rightAns := 9
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRomanToIntExample4(t *testing.T) {
	s := "LVIII"
	ans := romanToInt(s)
	rightAns := 58
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRomanToIntExample5(t *testing.T) {
	s := "MCMXCIV"
	ans := romanToInt(s)
	rightAns := 1994
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
