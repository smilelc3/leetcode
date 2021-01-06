package zigzag_conversion

/*
k(2n-2)
k(2n-2)+1										k(2n-2)+ (2n-2) - 1
k(2n-2)+2									k(2n-2)+ (2n-2) - 2
...						...
k(2n-2)+ n-3		k(2n-2)+ (2n-2) - (n-3)
k(2n-2)+ n-2	k(2n-2)+ (2n-2) - (n-2)
k(2n-2)+ n-1
*/

func convert(s string, numRows int) string {
	// 周期
	rowString := []byte(s)
	zigzag := make([]byte, len(s))
	cycleLength := 2*numRows - 2
	if cycleLength == 0 {
		// 特殊情况 numRows = 1
		return s
	}
	k := 0
	idx := 0
	for k*cycleLength < len(s) {
		zigzag[idx] = rowString[k*cycleLength]
		idx++
		k++
	}

	k = 0
	for t := 1; t <= numRows-2; t++ {
		k = 0
		for k*cycleLength+t < len(s) || (k+1)*cycleLength-t < len(s) {
			if k*cycleLength+t < len(s) {
				zigzag[idx] = rowString[k*cycleLength+t]
				idx++
			}
			if k*cycleLength+cycleLength-t < len(s) {
				zigzag[idx] = rowString[(k+1)*cycleLength-t]
				idx++
			}
			k++
		}
	}

	k = 0
	for k*cycleLength+numRows-1 < len(s) {
		zigzag[idx] = rowString[k*cycleLength+numRows-1]
		idx++
		k++
	}
	return string(zigzag)
}
