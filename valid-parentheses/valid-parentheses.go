package valid_parentheses

func isValid(s string) bool {
	ans := true
	var bracketsStack []int32
	for _, char := range s {
		if char == '(' || char == '{' || char == '[' {
			bracketsStack = append(bracketsStack, char)
		} else {
			if len(bracketsStack) != 0 {
				popChar := bracketsStack[len(bracketsStack)-1]
				bracketsStack = bracketsStack[:len(bracketsStack)-1]
				if popChar == '(' && char == ')' {
					continue
				} else if popChar == '[' && char == ']' {
					continue
				} else if popChar == '{' && char == '}' {
					continue
				} else {
					ans = false
					break
				}
			} else {
				ans = false
				break
			}
		}
	}
	if len(bracketsStack) != 0 {
		ans = false
	}
	return ans
}
