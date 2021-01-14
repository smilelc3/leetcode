package remove_element

import (
	"sort"
	"testing"
)

func TestRemoveElementExample1(t *testing.T) {
	nums := []int{3, 2, 2, 3}
	val := 3
	ansLen := removeElement(nums, val)
	rightAns := []int{2, 2}
	for idx := 0; idx < ansLen; idx++ {
		if nums[idx] != rightAns[idx] {
			t.Error("location = ", idx, "right ans = ", rightAns, ", current ans = ", nums)
		}
	}
}

func TestRemoveElementExample2(t *testing.T) {
	nums := []int{0, 1, 2, 2, 3, 0, 4, 2}
	val := 2
	ansLen := removeElement(nums, val)
	rightAns := []int{0, 1, 4, 0, 3}
	nums = nums[0:ansLen]
	sort.Ints(rightAns)
	sort.Ints(nums)
	for idx := 0; idx < ansLen; idx++ {
		if nums[idx] != rightAns[idx] {
			t.Error("location = ", idx, "right ans = ", rightAns, ", current ans = ", nums)
		}
	}
}
