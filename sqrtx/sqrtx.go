package sqrtx

func mySqrt(x int) int {
	start := 0
	end := x
	for start < end {
		mid := (start + end) / 2
		mid2 := mid * mid
		if mid2 == x {
			return mid
		} else if mid2 > x {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}

	// start == end
	if end*end > x {
		return end - 1
	} else {
		return end
	}
}
