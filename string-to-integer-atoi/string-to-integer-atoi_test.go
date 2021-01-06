package string_to_integer_atoi

import "testing"

func TestReversExample1(t *testing.T) {
	str := "42"
	ans := myAtoi(str)
	rightAns := 42
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReversExample2(t *testing.T) {
	str := "   -42"
	ans := myAtoi(str)
	rightAns := -42
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReversExample3(t *testing.T) {
	str := "4193 with words"
	ans := myAtoi(str)
	rightAns := 4193
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReversExample4(t *testing.T) {
	str := "words and 987"
	ans := myAtoi(str)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReversExample5(t *testing.T) {
	str := "-91283472332"
	ans := myAtoi(str)
	rightAns := -2147483648
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestReversLargeNumber(t *testing.T) {
	str := "20000000000000000000"
	ans := myAtoi(str)
	rightAns := 2147483647
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
