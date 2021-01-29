package text_justification

func fullJustify(words []string, maxWidth int) []string {
	curLength := 0
	lastEndIdx := 0
	var ans []string
	for idx, word := range words {
		// 当前行还能增加
		if curLength+len(word) <= maxWidth {
			curLength += len(word)
			if curLength < maxWidth {
				curLength += 1 // add at least one space
			}
		} else {
			line := formLineFromWords(words[lastEndIdx:idx], maxWidth, false)
			ans = append(ans, line)
			lastEndIdx = idx
			curLength = len(word)
			if curLength < maxWidth {
				curLength += 1 // add at least one space
			}
		}
	}
	ans = append(ans, formLineFromWords(words[lastEndIdx:], maxWidth, true))
	return ans
}

func formLineFromWords(words []string, maxWidth int, isLastLine bool) string {
	line := ""
	if isLastLine {
		for _, word := range words {
			line += word
			if len(line) < maxWidth {
				line += " "
			}
		}
		for len(line) < maxWidth {
			line += " "
		}

	} else {
		WordsNum := len(words)
		spaceLength := maxWidth
		for idx := 0; idx < WordsNum; idx++ {
			spaceLength -= len(words[idx])
		}
		if WordsNum == 1 {
			line += words[0]
			for idx := 0; idx < spaceLength; idx++ {
				line += " "
			}
		} else {
			spaceArray := getSpaceArray(spaceLength, WordsNum-1)
			for idx := 0; idx < WordsNum-1; idx++ {
				line += words[idx]
				line += spaceArray[idx]
			}
			line += words[WordsNum-1]
		}
	}
	return line
}

func getSpaceArray(length int, num int) []string {
	var spaceArray []string
	if num == 1 {
		spaceArray = append(spaceArray, "")
		for idx := 0; idx < length; idx++ {
			spaceArray[0] += " "
		}
		return spaceArray
	}
	if length%num == 0 {
		tempStr := ""
		for idx := 0; idx < length/num; idx++ {
			tempStr += " "
		}
		return append([]string{tempStr}, getSpaceArray(length-length/num, num-1)...)
	} else {
		tempStr := ""
		for idx := 0; idx < length/num+1; idx++ {
			tempStr += " "
		}
		return append([]string{tempStr}, getSpaceArray(length-(length/num+1), num-1)...)
	}
}
