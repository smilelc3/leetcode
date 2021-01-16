package longest_valid_parentheses

import "testing"

func TestLongestValidParenthesesExample1(t *testing.T) {
	s := "(()"
	ans := longestValidParentheses(s)
	rightAns := 2

	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestValidParenthesesExample2(t *testing.T) {
	s := ")()())"
	ans := longestValidParentheses(s)
	rightAns := 4
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestValidParenthesesExample3(t *testing.T) {
	s := ""
	ans := longestValidParentheses(s)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestValidParenthesesTest0(t *testing.T) {
	s := "()(()"
	ans := longestValidParentheses(s)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
func TestLongestValidParenthesesTest1(t *testing.T) {
	s := "())"
	ans := longestValidParentheses(s)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestValidParenthesesTest2(t *testing.T) {
	s := "((()))())"
	ans := longestValidParentheses(s)
	rightAns := 8
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestValidParenthesesMyTest0(t *testing.T) {
	s := "()()()()"
	ans := longestValidParentheses(s)
	rightAns := 8
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
