package regular_expression_matching

import "testing"

func TestIsMatchExample1(t *testing.T) {
	s := "aa"
	p := "a"
	ans := isMatch(s, p)
	if ans != false {
		t.Error("\"a\" does not match the entire string \"aa\".")
	}
}

func TestIsMatchExample2(t *testing.T) {
	s := "aa"
	p := "a*"
	ans := isMatch(s, p)
	if ans != true {
		t.Error("'*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes \"aa\".")
	}
}

func TestIsMatchExample3(t *testing.T) {
	s := "ab"
	p := ".*"
	ans := isMatch(s, p)
	if ans != true {
		t.Error("\".*\" means \"zero or more (*) of any character (.)\".")
	}
}

func TestIsMatchExample4(t *testing.T) {
	s := "aab"
	p := "c*a*b"
	ans := isMatch(s, p)
	if ans != true {
		t.Error("c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches \"aab\".")
	}
}

func TestIsMatchExample5(t *testing.T) {
	s := "mississippi"
	p := "mis*is*p*."
	ans := isMatch(s, p)
	if ans != false {
		t.Error()
	}
}
