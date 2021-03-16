package palindrome_number

import "strconv"

func isPalindrome(x int) bool {
	s := strconv.Itoa(x)
	for idx, char := range s {
		if idx >= len(s)/2 {
			break
		}
		if char != int32(s[len(s)-idx-1]) {
			return false
		}
	}
	return true
}
