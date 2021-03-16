package plus_one

import (
	"reflect"
	"testing"
)

func TestPlusOneExample1(t *testing.T) {
	digits := []int{1, 2, 3}
	ans := plusOne(digits)
	rightAns := []int{1, 2, 4}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestPlusOneExample2(t *testing.T) {
	digits := []int{4, 3, 2, 1}
	ans := plusOne(digits)
	rightAns := []int{4, 3, 2, 2}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestPlusOneExample3(t *testing.T) {
	digits := []int{0}
	ans := plusOne(digits)
	rightAns := []int{1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
