package n_queens_ii

import (
	"testing"
)

func TestTotalNQueensExample1(t *testing.T) {
	n := 4
	ans := totalNQueens(n)
	rightAns := 2
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestTotalNQueensExample2(t *testing.T) {
	n := 1
	ans := totalNQueens(n)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestTotalNQueensAll(t *testing.T) {
	ansTable := []int{1, 0, 0, 2, 10, 4, 40, 92, 352}
	for n := 1; n <= 9; n++ {
		ans := totalNQueens(n)
		rightAns := ansTable[n-1]
		if ans != rightAns {
			t.Error("n=", n, "right ans = ", rightAns, ", current ans = ", ans)
		}
	}

}
