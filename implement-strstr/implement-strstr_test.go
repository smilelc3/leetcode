package implement_strstr

import "testing"

func TestStrStrExample1(t *testing.T) {
	haystack := "hello"
	needle := "ll"
	ans := strStr(haystack, needle)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestStrStrExample2(t *testing.T) {
	haystack := "aaaaa"
	needle := "bba"
	ans := strStr(haystack, needle)
	rightAns := -1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestStrStrExample3(t *testing.T) {
	haystack := ""
	needle := ""
	ans := strStr(haystack, needle)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
