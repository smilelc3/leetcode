package plus_one

func plusOne(digits []int) []int {

	if digits == nil {
		return digits
	}
	digits[len(digits)-1] += 1

	for idx := len(digits) - 1; idx >= 1; idx-- {
		if digits[idx] == 10 {
			digits[idx] = 0
			digits[idx-1] += 1
		}
	}
	if digits[0] == 10 {
		digits[0] = 0
		digits = append([]int{1}, digits...)
	}
	return digits
}
