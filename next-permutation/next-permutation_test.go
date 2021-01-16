package next_permutation

import (
	"reflect"
	"testing"
)

func TestNextPermutationExample1(t *testing.T) {
	ans := []int{1, 2, 3}
	nextPermutation(ans)
	rightAns := []int{1, 3, 2}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNextPermutationExample2(t *testing.T) {
	ans := []int{3, 2, 1}
	nextPermutation(ans)
	rightAns := []int{1, 2, 3}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNextPermutationExample3(t *testing.T) {
	ans := []int{1, 1, 5}
	nextPermutation(ans)
	rightAns := []int{1, 5, 1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestNextPermutationExample4(t *testing.T) {
	ans := []int{1}
	nextPermutation(ans)
	rightAns := []int{1}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
