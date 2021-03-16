package generate_parentheses

import (
	"reflect"
	"testing"
)

func TestGenerateParenthesisExample1(t *testing.T) {
	n := 3
	ans := generateParenthesis(n)
	rightAns := []string{"((()))", "(()())", "(())()", "()(())", "()()()"}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestGenerateParenthesisExample2(t *testing.T) {
	n := 1
	ans := generateParenthesis(n)
	rightAns := []string{"()"}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
