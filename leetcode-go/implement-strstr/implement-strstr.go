package implement_strstr

func strStr(haystack string, needle string) int {
	// method 1: total match
	//return strStrDoubleLoop(haystack, needle)

	// method 2: KMP algorithm
	return strStrKmp(haystack, needle)
}

func strStrDoubleLoop(haystack, needle string) int {
	matchIdx := -1
	if len(needle) == 0 {
		matchIdx = 0
	}
	for haystackIdx := 0; haystackIdx < len(haystack); haystackIdx++ {
		isMatch := true
		for needleIdx, needleChar := range needle {
			if haystackIdx+needleIdx < len(haystack) {
				if rune(haystack[haystackIdx+needleIdx]) != needleChar {
					isMatch = false
					break
				}
			} else {
				isMatch = false
				break
			}
		}
		if isMatch == true {
			// return the first place found
			matchIdx = haystackIdx
			break
		}
	}
	return matchIdx
}

func strStrKmp(haystack, needle string) int {
	if len(needle) == 0 {
		return 0
	}
	// partialMatchTable 中的值是字符串的 前缀集 与 后缀集 的交集 中最长元素的长度
	// next数组为partialMatchTable数组向后偏移一位， 首位补-1
	next := make([]int, len(needle)+1)
	// 求next数组
	next[0] = -1
	i := 0
	j := -1
	for i < len(needle) {
		if j == -1 || needle[i] == needle[j] {
			i++
			j++
			next[i] = j
		} else {
			j = next[j]
		}
	}
	// 根据next数组求idxOf()
	i = 0
	j = 0
	for i < len(haystack) && j < len(needle) {
		if j == -1 || haystack[i] == needle[j] {
			i++
			j++
		} else {
			j = next[j]
		}
	}
	if j == len(needle) {
		return i - j
	} else {
		return -1
	}

}
