package letter_combinations_of_a_phone_number

func letterCombinations(digits string) []string {

	//init Map
	digitToLettersMap := map[int32][]int32{}
	digitToLettersMap['2'] = []int32{'a', 'b', 'c'}
	digitToLettersMap['3'] = []int32{'d', 'e', 'f'}
	digitToLettersMap['4'] = []int32{'g', 'h', 'i'}
	digitToLettersMap['5'] = []int32{'j', 'k', 'l'}
	digitToLettersMap['6'] = []int32{'m', 'n', 'o'}
	digitToLettersMap['7'] = []int32{'p', 'q', 'r', 's'}
	digitToLettersMap['8'] = []int32{'t', 'u', 'v'}
	digitToLettersMap['9'] = []int32{'w', 'x', 'y', 'z'}

	var lettersComb []string
	for _, digit := range digits {
		if letters, ok := digitToLettersMap[digit]; ok {
			if lettersComb == nil {
				for _, letter := range letters {
					lettersComb = append(lettersComb, string(letter))
				}
			} else {
				var newLettersComb []string
				for _, preComb := range lettersComb {
					for _, letter := range letters {
						newLettersComb = append(newLettersComb, preComb+string(letter))
					}
				}
				lettersComb = newLettersComb
			}
		}
	}
	return lettersComb
}
