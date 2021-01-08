package longest_common_prefix

import "testing"

func TestLongestCommonPrefixExample1(t *testing.T) {
	strs := []string{"flower", "flow", "flight"}
	ans := longestCommonPrefix(strs)
	rightAns := "fl"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestCommonPrefixExample2(t *testing.T) {
	strs := []string{"dog", "racecar", "car"}
	ans := longestCommonPrefix(strs)
	rightAns := ""
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestCommonPrefixNil(t *testing.T) {
	var strs []string
	ans := longestCommonPrefix(strs)
	rightAns := ""
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestCommonPrefixNone(t *testing.T) {
	strs := []string{""}
	ans := longestCommonPrefix(strs)
	rightAns := ""
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLongestCommonPrefixSingleChar(t *testing.T) {
	strs := []string{"a"}
	ans := longestCommonPrefix(strs)
	rightAns := "a"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
