package divide_two_integers

import "math"

func divideFool(dividend int, divisor int) int {
	quotient := dividend / divisor
	if quotient > math.MaxInt32 || quotient < math.MinInt32 {
		return math.MaxInt32
	}
	return quotient
}

func divideBitOperation(dividend int, divisor int) int {
	quotient := 0
	isNeg := false
	if dividend < 0 {
		dividend = -dividend
		isNeg = !isNeg
	}
	if divisor < 0 {
		divisor = -divisor
		isNeg = !isNeg
	}
	bitLenDiff := 0
	for (divisor << bitLenDiff) < dividend {
		bitLenDiff++
	}
	for i := bitLenDiff; i >= 0; i-- {
		if (divisor << i) > dividend {
			continue
		}
		quotient += 1 << i
		dividend -= divisor << i
	}
	if isNeg {
		quotient = -quotient
	}

	if quotient > math.MaxInt32 || quotient < math.MinInt32 {
		return math.MaxInt32
	}
	return quotient
}

func divide(dividend int, divisor int) int {
	//return divideFool(dividend, divisor)
	return divideBitOperation(dividend, divisor)
}
