package complex_number_multiplication

import (
	"strconv"
	"strings"
)

func complexNumberMultiply(a string, b string) string {
	// 第一步，分离数字
	aReal, aImag := splitNumber2RealAndImag(a)
	bReal, bImag := splitNumber2RealAndImag(b)

	ansRealStr := strconv.Itoa(aReal*bReal - aImag*bImag)
	ansImagStr := strconv.Itoa(aReal*bImag + aImag*bReal)

	return ansRealStr + "+" + ansImagStr + "i"
}

func splitNumber2RealAndImag(t string) (int, int) {
	// a+bi
	// a+-bi
	// -a+bi
	// -a+-bi

	tBytes := []byte(t)
	isTRealNeg := tBytes[0] == '-'
	tImagSignIdx := 0

	if isTRealNeg {
		tImagSignIdx = strings.Index(t[1:], "+") + 1
	} else {
		tImagSignIdx = strings.Index(t, "+")
	}

	tReal, _ := strconv.Atoi(t[:tImagSignIdx])

	tImag, _ := strconv.Atoi(t[tImagSignIdx+1 : len(t)-1])

	return tReal, tImag
}
