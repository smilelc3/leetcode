package permutation_sequence

func getPermutation(n int, k int) string {
	if n <= 0 {
		return ""
	}
	Fn := make([]int, n)
	calculateFactorial(&Fn)

	strSeq := make([]byte, n)
	for idx := 0; idx < n; idx++ {
		strSeq[idx] = byte('0' + idx + 1)
	}

	return string(getNumKPermutation(n, k, strSeq, &Fn))
}

//  Fn(i) = i!
func calculateFactorial(pFn *[]int) {
	if len(*pFn) <= 0 {
		return
	}
	(*pFn)[0] = 1
	for idx := 1; idx < len(*pFn); idx++ {
		(*pFn)[idx] = (*pFn)[idx-1] * idx
	}
}

func getNumKPermutation(n, k int, strSeq []byte, pFn *[]int) []byte {
	if n == 1 {
		return strSeq
	}
	curCharIdx := k / (*pFn)[n-1]
	if k-(*pFn)[n-1]*(curCharIdx) == 0 {
		curCharIdx--
	}
	newK := k - curCharIdx*(*pFn)[n-1]
	curChar := strSeq[curCharIdx]
	strSeq = append(strSeq[0:curCharIdx], strSeq[curCharIdx+1:]...)
	return append([]byte{curChar}, getNumKPermutation(n-1, newK, strSeq, pFn)...)
}
