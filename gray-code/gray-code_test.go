package gray_code

import (
	"reflect"
	"testing"
)

func TestGrayCodeExample1(t *testing.T) {
	n := 2
	ans := grayCode(n)
	rightAns := []int{0, 1, 3, 2}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestGrayCodeExample2(t *testing.T) {
	n := 1
	ans := grayCode(n)
	rightAns := []int{0, 1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func BenchmarkGrayCodeN16(b *testing.B) {
	n := 16
	b.ResetTimer()
	for idx := 0; idx < b.N; idx++ {
		_ = grayCode(n)
	}

}
