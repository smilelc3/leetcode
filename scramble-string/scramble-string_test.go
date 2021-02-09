package scramble_string

import (
	"testing"
)

func TestIsScrambleExample1(t *testing.T) {
	s1 := "great"
	s2 := "rgeat"
	ans := isScramble(s1, s2)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsScrambleExample2(t *testing.T) {
	s1 := "abcde"
	s2 := "caebd"
	ans := isScramble(s1, s2)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsScrambleExample3(t *testing.T) {
	s1 := "a"
	s2 := "a"
	ans := isScramble(s1, s2)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
