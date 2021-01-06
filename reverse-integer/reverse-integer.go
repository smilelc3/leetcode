package reverse_integer

import (
	"strconv"
)

/*
	GO语言中int类型的大小是不确定的，与具体的平台有关系
	一般来说，int在32位系统中是4字节，在64位系统中是8字节
*/
func reverse(x int) int {
	isNeg := false
	ans := 0
	const Int32Max = int(^uint32(0) >> 1)
	if x < 0 {
		isNeg = true
		x = -x
	}
	xStr := strconv.Itoa(x)
	rvsXStr := reverseString(xStr)

	ans, err := strconv.Atoi(rvsXStr)
	if err != nil || ans > Int32Max {
		return 0
	}
	if isNeg {
		ans = -ans
	}
	return ans
}

func reverseString(s string) string {
	chars := []rune(s)
	for i, j := 0, len(chars)-1; i < j; i, j = i+1, j-1 {
		chars[i], chars[j] = chars[j], chars[i]
	}
	return string(chars)
}
