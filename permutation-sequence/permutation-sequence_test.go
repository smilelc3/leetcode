package permutation_sequence

import (
	"testing"
)

func TestGetPermutationExample1(t *testing.T) {
	n := 3
	k := 3
	ans := getPermutation(n, k)
	rightAns := "213"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestGetPermutationExample2(t *testing.T) {
	n := 4
	k := 9
	ans := getPermutation(n, k)
	rightAns := "2314"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestGetPermutationExample3(t *testing.T) {
	n := 3
	k := 1
	ans := getPermutation(n, k)
	rightAns := "123"
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
