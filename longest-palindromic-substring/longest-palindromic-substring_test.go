package longest_palindromic_substring

import "testing"

func TestLongestPalindrome(t *testing.T) {
  // Manacher algorithm
	s := "babad"
	ans := longestPalindrome(s)
	if ans != "bab" && ans != "aba" {
		t.Error("right ans = \"bab\" or \"aba\", ", "your ans = ", ans)
	}
}
