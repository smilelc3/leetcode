package minimum_window_substring

import "fmt"

func minWindow(s string, t string) string {
	// version 1: 滑动窗口+hashMap
	//return minWindowV1(s, t)

	// version 1: 滑动窗口+数组代替Map
	return minWindowV2(s, t)
}

func minWindowV1(s string, t string) string {
	var minSubstring string
	sArray := []rune(s)
	tArray := []rune(t)
	// 初始化滑动窗口
	left, right, windowMap := initWindowV1(sArray, tArray)
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
func initWindowV1(s []rune, pattern []rune) (int, int, map[rune]int) {
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

func minWindowV2(s string, t string) string {
	var minSubstring string
	sArray := []rune(s)
	patternCount := [26 * 2]int{}
	for _, char := range t {
		patternCount[tranCharToIdx(char)]++
	}
	// 初始化滑动窗口
	left, right, windowCount := initWindowV2(sArray, patternCount)
	if left == -1 && right == -1 {
		return minSubstring
	}
	minSubstring = s[left:right]
	for {
		// 移动left
		curChar := sArray[left]
		curCharIdx := tranCharToIdx(curChar)
		windowCount[curCharIdx]--
		left++
		for left < right {
			if patternCount[tranCharToIdx(sArray[left])] != 0 {
				break
			}
			left++
		}
		// 移动right
		if windowCount[curCharIdx] < patternCount[curCharIdx] {
			for right < len(s) {
				if patternCount[tranCharToIdx(sArray[right])] != 0 {
					windowCount[tranCharToIdx(sArray[right])]++
				}
				if sArray[right] == curChar {
					right++
					break
				}
				right++
			}
		}
		if windowCount[curCharIdx] < patternCount[curCharIdx] && right == len(s) {
			// 达到移动终点
			break
		}
		if len(minSubstring) > right-left && right <= len(s) {
			minSubstring = s[left:right]
		}
	}
	return minSubstring
}

// 初始化滑动窗口，返回[left,right]和windowCount[26*2]
// left 指代初始位置，right指代结束位置的下一个
// windowCount[]指代窗口大小写字符的个数，[0,25]大写 [26,51]小写
// 若无法匹配，返回-1,-1
func initWindowV2(s []rune, patternCount [26 * 2]int) (int, int, [26 * 2]int) {
	windowCount := [26 * 2]int{}
	var needPatternTimer int
	for idx := 0; idx < len(patternCount); idx++ {
		if patternCount[idx] != 0 {
			needPatternTimer++
		}
	}
	left, right := -1, -1
	for idx, char := range s {
		if needPatternTimer == 0 {
			break
		}
		charIdx := tranCharToIdx(char)
		if patternCount[charIdx] != 0 {
			if left == -1 {
				left = idx
			}
			windowCount[charIdx]++
			if windowCount[charIdx] == patternCount[charIdx] {
				needPatternTimer--
			}
			right = idx + 1
		}
	}
	if needPatternTimer != 0 {
		return -1, -1, [26 * 2]int{}
	} else {
		return left, right, windowCount
	}
}

func tranCharToIdx(char rune) int {
	if 'A' <= char && char <= 'Z' {
		return int(char - 'A')
	} else if 'a' <= char && char <= 'z' {
		return int(char-'a') + 26
	} else {
		panic(fmt.Sprintf("当前字符%#v非大小写字母", char))
	}
}
