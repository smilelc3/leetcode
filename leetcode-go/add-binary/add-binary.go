package add_binary

func addBinary(a string, b string) string {
	if len(a) > len(b) {
		a, b = b, a
	}
	aArray := []byte(a)
	bArray := []byte(b)
	for idx := len(b) - 1; idx >= 0; idx-- {
		if len(a)-1-(len(b)-1-idx) >= 0 {
			bArray[idx] += aArray[len(a)-1-(len(b)-1-idx)] - '0'
		}
		if bArray[idx] >= '2' && idx > 0 {
			bArray[idx] -= 2
			bArray[idx-1] += 1
		}
	}
	if bArray[0] > '1' {
		bArray[0] -= 2
		bArray = append([]byte{'1'}, bArray...)
	}
	return string(bArray)
}
