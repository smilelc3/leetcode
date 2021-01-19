package wildcard_matching

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
	p := "*"
	ans := isMatch(s, p)
	if ans != true {
		t.Error("'*' matches any sequence.")
	}
}

func TestIsMatchExample3(t *testing.T) {
	s := "cb"
	p := "?a"
	ans := isMatch(s, p)
	if ans != false {
		t.Error("'?' matches 'c', but the second letter is 'a', which does not match 'b'.")
	}
}
func TestIsMatchExample4(t *testing.T) {
	s := "adceb"
	p := "*a*b"
	ans := isMatch(s, p)
	if ans != true {
		t.Error("The first '*' matches the empty sequence, while the second '*' matches the substring \"dce\".")
	}
}

func TestIsMatchExample5(t *testing.T) {
	s := "acdcb"
	p := "a*c?b"
	ans := isMatch(s, p)
	if ans != false {
		t.Error("right ans = ", false, ", current ans = ", ans)
	}
}

func TestIsMatchTest0(t *testing.T) {
	s := ""
	p := "******"
	ans := isMatch(s, p)
	if ans != true {
		t.Error("right ans = ", true, ", current ans = ", ans)
	}
}

func TestIsMatchMyTest0(t *testing.T) {
	s := ""
	p := "**a***"
	ans := isMatch(s, p)
	if ans != false {
		t.Error("right ans = ", false, ", current ans = ", ans)
	}
}
