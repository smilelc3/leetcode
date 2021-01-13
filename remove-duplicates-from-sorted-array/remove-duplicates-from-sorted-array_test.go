package remove_duplicates_from_sorted_array

import (
	"testing"
)

func TestRemoveDuplicatesExample1(t *testing.T) {
	nums := []int{1, 1, 2}
	ansLen := removeDuplicates(nums)
	rightAns := []int{1, 2}
	for idx := 0; idx < ansLen; idx++ {
		if nums[idx] != rightAns[idx] {
			t.Error("location = ", idx, "right ans = ", rightAns, ", current ans = ", nums)
		}
	}

}

func TestRemoveDuplicatesExample2(t *testing.T) {
	nums := []int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
	ansLen := removeDuplicates(nums)
	rightAns := []int{0, 1, 2, 3, 4}
	for idx := 0; idx < ansLen; idx++ {
		if nums[idx] != rightAns[idx] {
			t.Error("location = ", idx, "right ans = ", rightAns, ", current ans = ", nums)
		}
	}

}

func TestRemoveDuplicatesTest0(t *testing.T) {
	var nums []int
	ansLen := removeDuplicates(nums)
	if ansLen != 0 {
		t.Error("removeDuplicates([]) length is 0, your ans = ", ansLen)
	}

}
