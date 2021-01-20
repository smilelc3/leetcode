package group_anagrams

func groupAnagrams(strs []string) [][]string {
	letterCountMap := map[[26]uint8]int{}
	var groups [][]string
	for _, str := range strs {

		letterCount := [26]uint8{}
		for idx := 0; idx < len(str); idx++ {
			letterCount[str[idx]-'a']++
		}
		if idx, exist := letterCountMap[letterCount]; exist {
			// exist
			if groups != nil {
				groups[idx] = append(groups[idx], str)
			}
		} else {
			groups = append(groups, []string{str})
			letterCountMap[letterCount] = len(groups) - 1
		}
	}
	return groups
}
