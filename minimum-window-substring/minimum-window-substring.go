package minimum_window_substring

func minWindow(s string, t string) string {
	var minSubstring string
	sArray := []rune(s)
	tArray := []rune(t)
	// 初始化滑动窗口
	left, right, windowMap := initWindow(sArray, tArray)
	if left == -1 && right == -1 {
		return minSubstring
	}
	minSubstring = s[left:right]

	// 初始化模式串patternMap和当前windowMap
	patternMap := map[rune]int{}
	for _, char := range tArray {
		patternMap[char]++
	}

	for {
		// 移动left
		curChar := sArray[left]
		windowMap[curChar]--
		left++
		for left < right {
			if _, ok := patternMap[sArray[left]]; ok {
				break
			}
			left++
		}
		// 移动right
		if windowMap[curChar] < patternMap[curChar] {
			for right < len(s) {
				if _, ok := windowMap[sArray[right]]; ok {
					windowMap[sArray[right]]++
				}
				if sArray[right] == curChar {
					right++
					break
				}
				right++
			}
		}
		if windowMap[curChar] < patternMap[curChar] && right == len(s) {
			// 达到移动终点
			break
		}
		if len(minSubstring) > right-left && right <= len(s) {
			minSubstring = s[left:right]
		}
	}
	return minSubstring
}

// 初始化滑动窗口，返回[left,right]和windowMap
// left 指代初始位置，right指代结束位置的下一个
// 若无法匹配，返回-1,-1
func initWindow(s []rune, pattern []rune) (int, int, map[rune]int) {
	windowMap := map[rune]int{}
	patternMap := map[rune]int{}
	for _, char := range pattern {
		patternMap[char]++
	}
	left, right := -1, -1
	for idx, char := range s {
		if len(patternMap) == 0 {
			break
		}
		if _, ok := patternMap[char]; ok {
			if left == -1 {
				left = idx
			}
			patternMap[char]--
			windowMap[char]++
			if patternMap[char] == 0 {
				delete(patternMap, char)
			}
			right = idx + 1
		} else if _, ok := windowMap[char]; ok {
			windowMap[char]++
		}
	}
	if len(patternMap) != 0 {
		return -1, -1, map[rune]int{}
	} else {
		return left, right, windowMap
	}
}
