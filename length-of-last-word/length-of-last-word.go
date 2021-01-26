package length_of_last_word

func lengthOfLastWord(s string) int {
	str := []byte(s)
	if len(str) == 0 {
		return 0
	}
	length := 0

	lastNotSpaceIdx := len(str) - 1
	for lastNotSpaceIdx >= 0 && str[lastNotSpaceIdx] == ' ' {
		lastNotSpaceIdx--
	}
	str = str[:lastNotSpaceIdx+1]

	for idx := len(str) - 1; idx >= 0; idx-- {
		if str[idx] != ' ' {
			length++
		} else {
			break
		}
	}
	return length
}
