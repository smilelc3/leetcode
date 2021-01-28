package valid_number

import "regexp"

func isNumber(s string) bool {
	// method 1: re.match
	//return isNumberReg(s)

	// method 2: FSM(finite-state machine)
	return isNumberFSM(s)
}

func isNumberFSM(s string) bool {
	const (
		fail = iota
		initial
		mark
		digitNoDot  // digit found, no dot yet found (LHS of exponent), eg. "1" of "1.2334"
		dotAndDigit // digit found and dot has already been found (LHS of exponent), eg. "1.2" of "1.2334"
		dotNoDigit  // dot found, no digit yet found (LHS of exponent), eg. "." of ".0123
		exp
		expMark
		expDigit
		space
		done
	)

	const (
		failInput  = iota
		digitInput // 0-9
		signInput  // +/-
		expInput   // e
		dotInput   // .
		blankInput // space
		doneInput  // EOF
	)

	transform := map[int]map[int]int{
		initial: {
			digitInput: digitNoDot,
			signInput:  mark,
			dotInput:   dotNoDigit,
			blankInput: initial,
		},
		mark: {
			digitInput: digitNoDot,
			dotInput:   dotNoDigit,
		},
		digitNoDot: {
			digitInput: digitNoDot,
			dotInput:   dotAndDigit,
			expInput:   exp,
			blankInput: space,
			doneInput:  done,
		},
		dotAndDigit: {
			digitInput: dotAndDigit,
			expInput:   exp,
			blankInput: space,
			doneInput:  done,
		},
		dotNoDigit: {
			digitInput: dotAndDigit,
		},
		exp: {
			signInput:  expMark,
			digitInput: expDigit,
		},
		expMark: {
			digitInput: expDigit,
		},
		expDigit: {
			digitInput: expDigit,
			blankInput: space,
			doneInput:  done,
		},
		space: {
			blankInput: space,
			doneInput:  done,
		},
	}

	currentState := initial
	for _, char := range s {
		switch char {
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			currentState = transform[currentState][digitInput]
		case '.':
			currentState = transform[currentState][dotInput]
		case '+', '-':
			currentState = transform[currentState][signInput]
		case 'e', 'E':
			currentState = transform[currentState][expInput]
		case ' ':
			currentState = transform[currentState][blankInput]
		default:
			currentState = transform[currentState][failInput]
		}
		if currentState == fail {
			return false
		}
	}

	currentState = transform[currentState][doneInput]
	if currentState == fail {
		return false
	}
	return true
}

func isNumberReg(s string) bool {
	var compile = regexp.MustCompile(`^[-+]?(\d+\.?|\d*\.\d+)([eE][-+]?\d+)?$`)
	return compile.MatchString(s)
}
