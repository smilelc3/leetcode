package roman_to_integer

/*
	Symbol       Value
	I             1
	IV			  4
	V             5
	IX			  9
	X             10
	XL			  40
	L             50
	XC			  90
	C             100
	CD			  400
	D             500
	CM			  900
	M             1000
*/

func romanToInt(s string) int {
	idx := 0
	romanNum := 0
	for idx < len(s) {
		switch s[idx] {
		case 'M':
			romanNum += 1000
			idx++
		case 'D':
			romanNum += 500
			idx++
		case 'L':
			romanNum += 50
			idx++
		case 'V':
			romanNum += 5
			idx++
		case 'C':
			if idx+1 < len(s) && s[idx+1] == 'M' {
				romanNum += 900
				idx += 2
			} else if idx+1 < len(s) && s[idx+1] == 'D' {
				romanNum += 400
				idx += 2
			} else {
				romanNum += 100
				idx++
			}
		case 'X':
			if idx+1 < len(s) && s[idx+1] == 'C' {
				romanNum += 90
				idx += 2
			} else if idx+1 < len(s) && s[idx+1] == 'L' {
				romanNum += 40
				idx += 2
			} else {
				romanNum += 10
				idx++
			}
		case 'I':
			if idx+1 < len(s) && s[idx+1] == 'X' {
				romanNum += 9
				idx += 2
			} else if idx+1 < len(s) && s[idx+1] == 'V' {
				romanNum += 4
				idx += 2
			} else {
				romanNum += 1
				idx++
			}
		}
	}
	return romanNum
}
