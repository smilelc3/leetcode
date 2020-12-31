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
	radiusArray := make([]int, len(manacherString)) // 记录每个位置的回文半径

	// manacher算法核心
	R := -1   // R是最右回文边界
	C := -1   // C是R对应的最左回文中心
	maxR := 0 // maxR记录最大的回文半径
	maxRIdx := 0 // 记录最大回文半径的下标
	for idx := 0; idx< len(manacherString); idx++ {
		//第一步直接取得可能的最短的回文半径，
		//当idx>R时，最短的回文半径是1，
		//反之，最短的回文半径可能是i对应的i'的回文半径或者i到R的距离
		if R > idx {
			radiusArray[idx] = minInt(R-idx, radiusArray[2*C-idx])
		} else {
			radiusArray[idx] = 1
		}
		for idx+radiusArray[idx] < len(manacherString) && idx-radiusArray[idx] > -1 {
			if manacherString[idx+radiusArray[idx]] ==
				manacherString[idx-radiusArray[idx]] {
				radiusArray[idx] ++
			} else {
				break
			}
		}
		if idx+radiusArray[idx] > R {
			R = idx + radiusArray[idx]
			C = idx
		}

		if maxR < radiusArray[idx] {
			maxR = radiusArray[idx]
			maxRIdx = idx
		}
	}
	//println(maxR - 1)
	//manacherStringLongestPalindrome := manacherString[maxRIdx-(maxR-1) : maxRIdx+(maxR-1)+1]
	//return strings.Replace(manacherStringLongestPalindrome, "#", "", -1)
	return s[(maxRIdx-(maxR-1)) /2 : (maxRIdx+(maxR-1)+1)/2]
}

func minInt(x, y int) int {
	if x < y {
		return x
	}
	return y
}
