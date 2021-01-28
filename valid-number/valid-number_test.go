package valid_number

import "testing"

func TestIsNumberExample1(t *testing.T) {
	s := "0"
	ans := isNumber(s)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsNumberExample2(t *testing.T) {
	s := "e"
	ans := isNumber(s)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsNumberExample3(t *testing.T) {
	s := "."
	ans := isNumber(s)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsNumberExample4(t *testing.T) {
	s := ".1"
	ans := isNumber(s)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsNumberTest0(t *testing.T) {
	s := "e9"
	ans := isNumber(s)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsNumberMyTest0(t *testing.T) {
	s := ""
	ans := isNumber(s)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsNumberTest1(t *testing.T) {
	s := "005047e+6"
	ans := isNumber(s)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsNumberMyTest1(t *testing.T) {
	s := "1."
	ans := isNumber(s)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
