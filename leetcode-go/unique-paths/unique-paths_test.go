package unique_paths

import "testing"

func TestUniquePathsExample1(t *testing.T) {
	m := 3
	n := 2
	ans := uniquePaths(m, n)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestUniquePathsExample2(t *testing.T) {
	m := 7
	n := 3
	ans := uniquePaths(m, n)
	rightAns := 28
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestUniquePathsExample3(t *testing.T) {
	m := 3
	n := 3
	ans := uniquePaths(m, n)
	rightAns := 6
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
