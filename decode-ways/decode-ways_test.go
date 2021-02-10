package decode_ways

import "testing"

func TestNumDecodingsExample1(t *testing.T) {
	s := "12"
	ans := numDecodings(s)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNumDecodingsExample2(t *testing.T) {
	s := "226"
	ans := numDecodings(s)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNumDecodingsExample3(t *testing.T) {
	s := "0"
	ans := numDecodings(s)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNumDecodingsExample4(t *testing.T) {
	s := "06"
	ans := numDecodings(s)
	rightAns := 0
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNumDecodingsTest0(t *testing.T) {
	s := "2101"
	ans := numDecodings(s)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNumDecodingsTest1(t *testing.T) {
	s := "2611055971756562"
	ans := numDecodings(s)
	rightAns := 4
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
