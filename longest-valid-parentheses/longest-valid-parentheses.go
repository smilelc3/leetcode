package longest_valid_parentheses

func longestValidParentheses(s string) int {
	//
	maxlength := 0
	var char2NumStack []int
	// ( --> 0
	// ) --> 1
	idx := 0
	for idx < len(s) {
		curChar := s[idx]
		if curChar == '(' {
			char2NumStack = append(char2NumStack, 0)
		} else {
			//curChar == ')'
			if len(char2NumStack) > 0 {
				// pop 出栈直到找到第一个为')' or '(' or 到最底
				mergeLength := 0
				popCharTrans := char2NumStack[len(char2NumStack)-1]
				char2NumStack = char2NumStack[:len(char2NumStack)-1]
				for popCharTrans != 0 && popCharTrans != 1 && len(char2NumStack) > 0 {
					mergeLength += popCharTrans // 是匹配的个数
					popCharTrans = char2NumStack[len(char2NumStack)-1]
					char2NumStack = char2NumStack[:len(char2NumStack)-1]
				}
				if popCharTrans == 0 {
					// popCharTrans -> '(' 0 is pair
					char2NumStack = append(char2NumStack, mergeLength+2)
				} else if popCharTrans == 1 {
					// popCharTrans -> ')' 1
					char2NumStack = append(char2NumStack, 1)
					char2NumStack = append(char2NumStack, mergeLength)
					char2NumStack = append(char2NumStack, 1)
				} else {
					char2NumStack = append(char2NumStack, popCharTrans+mergeLength)
					char2NumStack = append(char2NumStack, 1)
				}
			} else {
				char2NumStack = append(char2NumStack, 1)
			}
		}
		idx++
	}

	connLength := 0 // 连续最长
	for _, num := range char2NumStack {
		if num == 0 || num == 1 {
			maxlength = max(maxlength, connLength)
			connLength = 0
		} else {
			connLength += num
		}
	}
	maxlength = max(maxlength, connLength)
	return maxlength
}

func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
