package largest_rectangle_in_histogram

import (
	"math/rand"
	"testing"
)

func TestLargestRectangleAreaExample1(t *testing.T) {
	heights := []int{2, 1, 5, 6, 2, 3}
	ans := largestRectangleArea(heights)
	rightAns := 10
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLargestRectangleAreaExample2(t *testing.T) {
	heights := []int{2, 4}
	ans := largestRectangleArea(heights)
	rightAns := 4
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLargestRectangleAreaMyTest0(t *testing.T) {
	heights := []int{1, 3, 2, 1, 3}
	ans := largestRectangleArea(heights)
	rightAns := 5
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLargestRectangleAreaTest0(t *testing.T) {
	heights := []int{0, 9}
	ans := largestRectangleArea(heights)
	rightAns := 9
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLargestRectangleAreaTest1(t *testing.T) {
	heights := []int{1}
	ans := largestRectangleArea(heights)
	rightAns := 1
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestLargestRectangleAreaTest2(t *testing.T) {
	heights := []int{2, 1, 2}
	ans := largestRectangleArea(heights)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func BenchmarkLargestRectangleAreaRandom(b *testing.B) {
	rand.Seed(1)
	var heights []int
	for idx := 0; idx < 100000; idx++ {
		heights = append(heights, rand.Intn(10000))
	}

	b.ResetTimer()
	for idx := 0; idx < b.N; idx++ {
		largestRectangleArea(heights)
	}
}

func BenchmarkLargestRectangleAreaDesc(b *testing.B) {
	var heights []int
	for idx := 0; idx < 100000; idx++ {
		heights = append(heights, 10000-idx/10)
	}

	b.ResetTimer()
	for idx := 0; idx < b.N; idx++ {
		largestRectangleArea(heights)
	}
}

func BenchmarkLargestRectangleAreaAsc(b *testing.B) {
	var heights []int
	for idx := 0; idx < 100000; idx++ {
		heights = append(heights, idx/10)
	}

	b.ResetTimer()
	for idx := 0; idx < b.N; idx++ {
		largestRectangleArea(heights)
	}
}
