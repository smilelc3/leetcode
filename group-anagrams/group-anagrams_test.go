package group_anagrams

import (
	"reflect"
	"testing"
)

func TestGroupAnagramsExample1(t *testing.T) {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	ans := groupAnagrams(strs)
	rightAns := [][]string{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestGroupAnagramsExample2(t *testing.T) {
	strs := []string{""}
	ans := groupAnagrams(strs)
	rightAns := [][]string{{""}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestGroupAnagramsExample3(t *testing.T) {
	strs := []string{"a"}
	ans := groupAnagrams(strs)
	rightAns := [][]string{{"a"}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
