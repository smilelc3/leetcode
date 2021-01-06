package palindrome_number

import "testing"

func TestIsPalindromeExample1(t *testing.T) {
	x := 121
	if !isPalindrome(x) {
		t.Error(x, "is a Palindrome Number")
	}
}

func TestIsPalindromeExample2(t *testing.T) {
	x := -121
	if isPalindrome(x) {
		t.Error(x, " is not a Palindrome Number")
	}
}

func TestIsPalindromeExample3(t *testing.T) {
	x := 10
	if isPalindrome(x) {
		t.Error(x, "is not a Palindrome Number")
	}
}

func TestIsPalindromeExample4(t *testing.T) {
	x := -101
	if isPalindrome(x) {
		t.Error(x, "is not a Palindrome Number")
	}
}

func TestIsPalindrome1001(t *testing.T) {
	x := 1001
	if !isPalindrome(x) {
		t.Error(x, "is a Palindrome Number")
	}
}
