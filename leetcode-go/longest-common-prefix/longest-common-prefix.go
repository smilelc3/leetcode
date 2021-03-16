package longest_common_prefix

func longestCommonPrefix(strs []string) string {
	commonPrefixEndIdx := 0
	var curChar uint8
	for len(strs) > 0 {
		for strIdx, str := range strs {
			if commonPrefixEndIdx >= len(str) {
				return str[:commonPrefixEndIdx]
			}
			if strIdx == 0 {
				curChar = str[commonPrefixEndIdx]

			} else if str[commonPrefixEndIdx] != curChar {
				return str[:commonPrefixEndIdx]
			}
			if strIdx == len(strs)-1 {
				commonPrefixEndIdx++
			}
		}
	}
	return ""
}
