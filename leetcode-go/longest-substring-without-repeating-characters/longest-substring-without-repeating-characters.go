package longest_substring_without_repeating_characters

func lengthOfLongestSubstring(s string) int {
	// using DP method
	curLength := 0 // 记录以当前字符的上一个字符为结尾的最长不重复子字符串
	maxLength := 0 // 记录最长不重复子串
	charToIdxMap := map[int32]int{}

	for idx, char := range s {
		if lastIdx, ok := charToIdxMap[char]; ok {
			dis := idx - lastIdx
			if dis <= curLength {
				curLength = dis
			} else {
				curLength++
			}
		} else {
			curLength++
		}
		if curLength > maxLength {
			maxLength = curLength
		}
		charToIdxMap[char] = idx
	}
	return maxLength
}
