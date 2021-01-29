package simplify_path

import "testing"

func TestSimplifyPathExample1(t *testing.T) {
	path := "/home/"
	ans := simplifyPath(path)
	rightAns := "/home"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSimplifyPathExample2(t *testing.T) {
	path := "/../"
	ans := simplifyPath(path)
	rightAns := "/"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSimplifyPathExample3(t *testing.T) {
	path := "/home//foo/"
	ans := simplifyPath(path)
	rightAns := "/home/foo"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestSimplifyPathExample4(t *testing.T) {
	path := "/a/./b/../../c/"
	ans := simplifyPath(path)
	rightAns := "/c"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
