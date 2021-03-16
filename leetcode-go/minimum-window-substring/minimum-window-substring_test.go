package minimum_window_substring

import (
	"io/ioutil"
	"testing"
)

func TestMinWindowExample1(test *testing.T) {
	s := "ADOBECODEBANC"
	t := "ABC"
	ans := minWindow(s, t)
	rightAns := "BANC"
	if ans != rightAns {
		test.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinWindowExample2(test *testing.T) {
	s := "a"
	t := "a"
	ans := minWindow(s, t)
	rightAns := "a"
	if ans != rightAns {
		test.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinWindowTest0(test *testing.T) {
	s := "a"
	t := "aa"
	ans := minWindow(s, t)
	rightAns := ""
	if ans != rightAns {
		test.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinWindowTest1(test *testing.T) {
	s := "ab"
	t := "a"
	ans := minWindow(s, t)
	rightAns := "a"
	if ans != rightAns {
		test.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinWindowTest2(test *testing.T) {
	s := "bba"
	t := "ab"
	ans := minWindow(s, t)
	rightAns := "ba"
	if ans != rightAns {
		test.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinWindowTest3(test *testing.T) {
	sBytes, _ := ioutil.ReadFile("test3s.txt")
	s := string(sBytes)
	tBytes, _ := ioutil.ReadFile("test3t.txt")
	t := string(tBytes)

	ans := minWindow(s, t)
	rightAnsBytes, _ := ioutil.ReadFile("test3ans.txt")
	rightAns := string(rightAnsBytes)
	if ans != rightAns {
		test.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinWindowTest4(test *testing.T) {
	s := "aa"
	t := "aa"
	ans := minWindow(s, t)
	rightAns := "aa"
	if ans != rightAns {
		test.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func BenchmarkMinWindowV1Test3(b *testing.B) {
	sBytes, _ := ioutil.ReadFile("test3s.txt")
	s := string(sBytes)
	tBytes, _ := ioutil.ReadFile("test3t.txt")
	t := string(tBytes)
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		minWindowV1(s, t)
	}
}

func BenchmarkMinWindowV2Test3(b *testing.B) {
	sBytes, _ := ioutil.ReadFile("test3s.txt")
	s := string(sBytes)
	tBytes, _ := ioutil.ReadFile("test3t.txt")
	t := string(tBytes)
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		minWindowV2(s, t)
	}
}
