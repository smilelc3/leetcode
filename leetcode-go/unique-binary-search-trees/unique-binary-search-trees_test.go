package unique_binary_search_trees

import (
	"testing"
)

func TestNumTreesExample1(t *testing.T) {
	n := 3
	ans := numTrees(n)
	rightAns := 5
	if rightAns != ans {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNumTreesExample2(t *testing.T) {
	n := 1
	ans := numTrees(n)
	rightAns := 1
	if rightAns != ans {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNumTreesTest0(t *testing.T) {
	n := 11
	ans := numTrees(n)
	rightAns := 58786
	if rightAns != ans {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
