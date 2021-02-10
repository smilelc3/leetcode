package built_in

func Abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}
func Max(x int, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}

func Min(x int, y int) int {
	if x > y {
		return y
	} else {
		return x
	}
}
