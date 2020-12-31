package longest_substring_without_repeating_characters

import "testing"

func TestLengthOfLongestSubstring(t *testing.T)  {
	s := "abcabcbb"
	if lengthOfLongestSubstring(s) != 3 {
		t.Error("The answer is \"abc\", with the length of 3.", "ans is ", lengthOfLongestSubstring(s))
	}

	s = "bbbbb"
	if lengthOfLongestSubstring(s) != 1 {
		t.Error("The answer is \"b\", with the length of 1.", "ans is ", lengthOfLongestSubstring(s))
	}

	s = "pwwkew"
	if lengthOfLongestSubstring(s) != 3 {
		t.Error("The answer is \"wke\", with the length of 3.", "ans is ", lengthOfLongestSubstring(s))
	}

	s = ""
	if lengthOfLongestSubstring(s) != 0 {
		t.Error("ans is ", lengthOfLongestSubstring(s))
	}
}