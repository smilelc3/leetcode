package generate_parentheses

func generateParenthesisBacktracking(parenthesis string, leftRemain int, rightRemain int, parenthesisArray *[]string) {
	if leftRemain == 0 && rightRemain == 0 {
		*parenthesisArray = append(*parenthesisArray, parenthesis)
		return
	}
	if leftRemain > 0 {
		generateParenthesisBacktracking(parenthesis+"(", leftRemain-1, rightRemain, parenthesisArray)
	}
	if rightRemain > leftRemain {
		generateParenthesisBacktracking(parenthesis+")", leftRemain, rightRemain-1, parenthesisArray)
	}
	return
}

func generateParenthesis(n int) []string {
	var parenthesisArray []string
	generateParenthesisBacktracking("", n, n, &parenthesisArray)
	return parenthesisArray
}
