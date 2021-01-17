package count_and_say

import "testing"

func TestCountAndSayExample1(t *testing.T) {
	n := 1
	ans := countAndSay(n)
	rightAns := "1"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestCountAndSayExample2(t *testing.T) {
	n := 4
	ans := countAndSay(n)
	rightAns := "1211"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
