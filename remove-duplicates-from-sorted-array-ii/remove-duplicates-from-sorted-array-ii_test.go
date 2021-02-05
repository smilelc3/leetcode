package remove_duplicates_from_sorted_array_ii

import (
	"reflect"
	"testing"
)

func TestRemoveDuplicatesExample1(t *testing.T) {
	nums := []int{1, 1, 1, 2, 2, 3}
	ansLen := removeDuplicates(nums)
	rightAnsLen := 5
	rightAnsNums := []int{1, 1, 2, 2, 3}
	if ansLen != rightAnsLen {
		t.Error("right length = ", rightAnsLen, ", current length = ", ansLen)
	}
	if !reflect.DeepEqual(nums[:rightAnsLen], rightAnsNums) {
		t.Error("right nums[]= ", rightAnsNums, ", current nums= ", nums)
	}
}

func TestRemoveDuplicatesExample2(t *testing.T) {
	nums := []int{0, 0, 1, 1, 1, 1, 2, 3, 3}
	ansLen := removeDuplicates(nums)
	rightAnsLen := 7
	rightAnsNums := []int{0, 0, 1, 1, 2, 3, 3}
	if ansLen != rightAnsLen {
		t.Error("right length = ", rightAnsLen, ", current length = ", ansLen)
	}
	if !reflect.DeepEqual(nums[:rightAnsLen], rightAnsNums) {
		t.Error("right nums[]= ", rightAnsNums, ", current nums= ", nums)
	}
}
