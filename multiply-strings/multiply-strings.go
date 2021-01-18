package multiply_strings

import "strings"

func multiply(num1 string, num2 string) string {
	if num1 == "" || num2 == "" {
		return ""
	}
	multiAns := make([]int, len(num1)+len(num2))
	num1 = reverseString(num1)
	num2 = reverseString(num2)

	for idx1 := 0; idx1 < len(num1); idx1++ {
		for idx2 := 0; idx2 < len(num2); idx2++ {
			multiAns[idx1+idx2] += (int(num1[idx1]) - '0') * (int(num2[idx2]) - '0')
		}
	}
	for idx := 0; idx < len(multiAns)-1; idx++ {
		if multiAns[idx] >= 10 {
			multiAns[idx+1] += multiAns[idx] / 10
			multiAns[idx] %= 10
		}
	}
	builder := strings.Builder{}

	highIdx := len(num1) + len(num2) - 1
	for multiAns[highIdx] == 0 && highIdx > 0 {
		highIdx--
	}
	for highIdx >= 0 {
		builder.WriteByte(byte('0' + multiAns[highIdx]))
		highIdx--
	}

	return builder.String()
}

func reverseString(s string) string {
	runes := []rune(s)
	for from, to := 0, len(runes)-1; from < to; from, to = from+1, to-1 {
		runes[from], runes[to] = runes[to], runes[from]
	}
	return string(runes)
}
