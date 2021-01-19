package powx_n

func myPow(x float64, n int) float64 {
	// fast power O(log(n))
	if n < 0 {
		return 1 / myPow(x, -n)
	} else if n == 0 {
		return 1
	} else if n == 1 {
		return x
	} else if n&1 == 1 {
		return myPow(x*x, n/2) * x
	} else {
		return myPow(x*x, n/2)
	}
}
