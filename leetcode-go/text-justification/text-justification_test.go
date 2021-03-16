package text_justification

import (
	"reflect"
	"testing"
)

func TestFullJustifyExample1(t *testing.T) {
	words := []string{"This", "is", "an", "example", "of", "text", "justification."}
	maxWidth := 16
	ans := fullJustify(words, maxWidth)
	rightAns := []string{
		"This    is    an",
		"example  of text",
		"justification.  "}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFullJustifyExample2(t *testing.T) {
	words := []string{"What", "must", "be", "acknowledgment", "shall", "be"}
	maxWidth := 16
	ans := fullJustify(words, maxWidth)
	rightAns := []string{
		"What   must   be",
		"acknowledgment  ",
		"shall be        "}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFullJustifyExample3(t *testing.T) {
	words := []string{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"}
	maxWidth := 20
	ans := fullJustify(words, maxWidth)
	rightAns := []string{
		"Science  is  what we",
		"understand      well",
		"enough to explain to",
		"a  computer.  Art is",
		"everything  else  we",
		"do                  "}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
