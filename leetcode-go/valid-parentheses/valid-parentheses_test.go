package valid_parentheses

import (
	"testing"
)

func TestIsValidExample1(t *testing.T) {
	s := "()"
	ans := isValid(s)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsValidExample2(t *testing.T) {
	s := "()[]{}"
	ans := isValid(s)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsValidExample3(t *testing.T) {
	s := "(]"
	ans := isValid(s)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsValidExample4(t *testing.T) {
	s := "([)]"
	ans := isValid(s)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
