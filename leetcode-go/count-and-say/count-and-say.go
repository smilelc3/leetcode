package count_and_say

import (
	"strconv"
	"strings"
)

func countAndSayRecursive(n int) string {
	if n == 1 {
		return "1"
	} else {
		str := countAndSayRecursive(n - 1)
		strBuilder := strings.Builder{}
		preChar := str[0]
		length := 1
		for idx := 1; idx < len(str); idx++ {
			if preChar != str[idx] {
				strBuilder.WriteByte(byte(length + '0'))
				strBuilder.WriteByte(preChar)
				preChar = str[idx]
				length = 1
			} else {
				length++
			}
		}
		strBuilder.WriteByte(byte(length + '0'))
		strBuilder.WriteByte(preChar)
		return strBuilder.String()
	}
}

func countAndSay(n int) string {
	// Recursive version + strings.Builder boost
	return countAndSayRecursive(n)

	// Inductive version
	//return countAndSayInductive(n)
}

func countAndSayInductive(n int) string {
	str := "1"
	for current := 2; current <= n; current++ {
		newStr := ""
		preChar := str[0]
		length := 1
		for idx := 1; idx < len(str); idx++ {
			if preChar != str[idx] {
				newStr += strconv.Itoa(length) + string(preChar)
				preChar = str[idx]
				length = 1
			} else {
				length++
			}
		}
		newStr += strconv.Itoa(length) + string(preChar)
		str = newStr
	}
	return str
}
