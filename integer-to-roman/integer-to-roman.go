package integer_to_roman

import "strings"

/*
	Symbol      Value
	I           1
	IV          4
	V           5
	IX          9
	X           10
	XL          40
	L           50
	XC          90
	C           100
	CD          400
	D           500
	CM          900
	M           1000
*/

func intToRoman(num int) string {
	RomanSymbolDesc := [...]string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	RomanNumDesc := [...]int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	var RomanStringBuild strings.Builder // 单线程，非线程安全，速度快

	idx := 0
	for num != 0 {
		if num >= RomanNumDesc[idx] {
			for timer := 0; timer < num/RomanNumDesc[idx]; timer++ {
				RomanStringBuild.WriteString(RomanSymbolDesc[idx])
			}
			num = num % RomanNumDesc[idx]
		} else {
			idx++
		}
	}
	return RomanStringBuild.String()
}
