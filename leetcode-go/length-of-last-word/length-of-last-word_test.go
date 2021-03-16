package length_of_last_word

import "testing"

func TestLengthOfLastWordExample1(t *testing.T) {
	s := "Hello World"
	ans := lengthOfLastWord(s)
	rightAns := 5
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLengthOfLastWordExample2(t *testing.T) {
	s := ""
	ans := lengthOfLastWord(s)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLengthOfLastWordTest0(t *testing.T) {
	s := "a "
	ans := lengthOfLastWord(s)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLengthOfLastWordTest1(t *testing.T) {
	s := " "
	ans := lengthOfLastWord(s)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
