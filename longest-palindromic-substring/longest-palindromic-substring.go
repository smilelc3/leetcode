package longest_palindromic_substring

func longestPalindrome(s string) string {
	if s == "" { // 空字符直接返回
		return ""
	}

	// 转换为manacher字符串
	manacherString := "#"
	for _, char := range s {
		manacherString += string(char) + "#"
	}
	P := make([]int, len(manacherString)) // 记录每个位置的回文半径

	// manacher算法核心
	R := -1    // R是最右回文边界
	C := -1    // C是R对应的最左回文中心
	maxR := 0  // maxR记录最大的回文半径
	maxRi := 0 // 记录最大回文半径的下标
	for i := 0; i < len(manacherString); i++ {
		//第一步直接取得可能的最短的回文半径，
		//当i>=R时，最短的回文半径是1，
		//反之，最短的回文半径可能是i对应的i'的回文半径或者i到R的距离
		if i >= R {
			P[i] = 1
		} else {
			P[i] = min(R-i, P[2*C-i])

		}
		for i+P[i] < len(manacherString) && i-P[i] >= 0 {
			if manacherString[i+P[i]] == manacherString[i-P[i]] {
				P[i]++ //更新当前位置的回文半径
			} else {
				break
			}
		}
		if i+P[i] > R {
			R = i + P[i]
			C = i
		}

		if maxR < P[i] {
			maxR = P[i]
			maxRi = i
		}
	}
	// 最长回文半径为 maxR - 1
	//manacherStringLongestPalindrome := manacherString[maxRi-(maxR-1) : maxRi+(maxR-1)+1]
	//return strings.Replace(manacherStringLongestPalindrome, "#", "", -1)
	return s[(maxRi-(maxR-1))/2 : (maxRi+(maxR-1)+1)/2]
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
