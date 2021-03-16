package substring_with_concatenation_of_all_words

import (
	"reflect"
	"testing"
)

func TestFindSubstringExample1(t *testing.T) {
	s := "barfoothefoobarman"
	words := []string{"foo", "bar"}
	ans := findSubstring(s, words)
	rightAns := []int{0, 9}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFindSubstringExample2(t *testing.T) {
	s := "wordgoodgoodgoodbestword"
	words := []string{"word", "good", "best", "word"}
	ans := findSubstring(s, words)
	var rightAns []int
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFindSubstringExample3(t *testing.T) {
	s := "barfoofoobarthefoobarman"
	words := []string{"bar", "foo", "the"}
	ans := findSubstring(s, words)
	rightAns := []int{6, 9, 12}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFindSubstringTest0(t *testing.T) {
	s := "wordgoodgoodgoodbestword"
	words := []string{"word", "good", "best", "good"}
	ans := findSubstring(s, words)
	rightAns := []int{8}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFindSubstringTest1(t *testing.T) {
	s := "lingmindraboofooowingdingbarrwingmonkeypoundcake"
	words := []string{"fooo", "barr", "wing", "ding", "wing"}
	ans := findSubstring(s, words)
	rightAns := []int{13}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestFindSubstringTest2(t *testing.T) {
	s := "bcabbcaabbccacacbabccacaababcbb"
	words := []string{"c", "b", "a", "c", "a", "a", "a", "b", "c"}
	ans := findSubstring(s, words)
	rightAns := []int{6, 16, 17, 18, 19, 20}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
