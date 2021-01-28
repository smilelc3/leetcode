package valid_number

import "regexp"

func isNumber(s string) bool {
	// method 1: re.match
	//return isNumberReg(s)

	// method 2: FSM(finite-state machine)
	return isNumberFSM(s)
}

func isNumberFSM(s string) bool {

}

func isNumberReg(s string) bool {
	var compile = regexp.MustCompile(`^[-+]?(\d+\.?|\d*\.\d+)([eE][-+]?\d+)?$`)
	return compile.MatchString(s)
}
