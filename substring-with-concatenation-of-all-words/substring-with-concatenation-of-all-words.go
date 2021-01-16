package substring_with_concatenation_of_all_words

func findSubstring(s string, words []string) []int {
	if len(s) == 0 || len(s) == 0 {
		return []int{} // nil
	}
	var ans []int
	// slide window 滑动窗口算法
	// 定义窗口左右指针
	// winLeft 指向开始位置，winRight指向结束位置的下一个位置
	var winLeft, winRight int

	// 记录 window 中已经有多少字符符合要求了
	var match int

	// 借助两个HashMap
	// needsMap存储所有需要的word，以及出现的次数
	needsMap := map[string]int{}
	for _, word := range words {
		needsMap[word]++
	}

	wordLength := len(words[0])

	// windowMap 存储当前window内的所有单词
	windowMap := map[string]int{}
	for offset := 0; offset < wordLength; offset++ {
		// init
		offStr := s[offset:]
		winLeft = 0
		winRight = 0
		windowMap = map[string]int{}
		match = 0
		for winRight+wordLength <= len(offStr) {
			nextWord := offStr[winRight : winRight+wordLength]
			winRight += wordLength
			if _, exist := needsMap[nextWord]; exist {
				windowMap[nextWord]++
				if needsMap[nextWord] == windowMap[nextWord] {
					match++
				} else if windowMap[nextWord] > needsMap[nextWord] {
					for windowMap[nextWord] > needsMap[nextWord] {
						// 超过match 动Left
						leftWord := offStr[winLeft : winLeft+wordLength]
						windowMap[leftWord]--
						if windowMap[leftWord]+1 == needsMap[leftWord] {
							match--
						}
						winLeft += wordLength
					}
				}
			} else {
				winLeft = winRight
				match = 0
				windowMap = map[string]int{}
			}
			if match == len(needsMap) {
				ans = append(ans, offset+winLeft)
				leftWord := offStr[winLeft : winLeft+wordLength]
				windowMap[leftWord]--
				match--
				winLeft += wordLength
			}
		}
	}
	return ans
}
