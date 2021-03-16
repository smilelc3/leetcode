package integer_to_roman

import "testing"

func TestIntToRomanExample1(t *testing.T) {
	num := 3
	ans := intToRoman(num)
	rightAns := "III"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIntToRomanExample2(t *testing.T) {
	num := 4
	ans := intToRoman(num)
	rightAns := "IV"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIntToRomanExample3(t *testing.T) {
	num := 9
	ans := intToRoman(num)
	rightAns := "IX"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIntToRomanExample4(t *testing.T) {
	num := 58
	ans := intToRoman(num)
	rightAns := "LVIII"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIntToRomanExample5(t *testing.T) {
	num := 1994
	ans := intToRoman(num)
	rightAns := "MCMXCIV"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
