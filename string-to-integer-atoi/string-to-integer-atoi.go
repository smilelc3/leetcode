package string_to_integer_atoi

import (
	"regexp"
	"strconv"
	"strings"
)

func myAtoi(s string) int {
	ans := 0
	const Int32Max = int(^uint32(0) >> 1)
	const Int32Min = ^Int32Max
	compile := regexp.MustCompile(`^\s*[-+]?\d+`)
	match := compile.FindString(s)
	startFrom := 0
	for idx, char := range match {
		if char != ' ' {
			startFrom = idx
			break
		}
	}
	// remove all first whitespace
	//match = strings.Replace(match, " ", "", -1)
	match = match[startFrom:]

	ans, err := strconv.Atoi(match)
	if err != nil {
		if strings.Contains(err.Error(), "value out of range") {
			if strings.HasPrefix(match, "-") {
				return Int32Min
			} else {
				return Int32Max
			}
		}
		return 0
	}
	if ans > Int32Max {
		return Int32Max
	}
	if ans < Int32Min {
		return Int32Min
	}
	return ans
}
