package letter_combinations_of_a_phone_number

import (
	"reflect"
	"testing"
)

func TestLetterCombinationsExample1(t *testing.T) {
	digits := "23"
	ans := letterCombinations(digits)
	rightAns := []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestLetterCombinationsExample2(t *testing.T) {
	digits := ""
	ans := letterCombinations(digits)
	var rightAns []string
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}

func TestLetterCombinationsExample3(t *testing.T) {
	digits := "2"
	ans := letterCombinations(digits)
	rightAns := []string{"a", "b", "c"}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, "current ans = ", ans)
	}
}
