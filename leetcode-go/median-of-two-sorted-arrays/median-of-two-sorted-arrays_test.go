package median_of_two_sorted_arrays

import "testing"

func TestFindMedianSortedArrays(t *testing.T) {
	num1 := []int{1, 2}
	num2 := []int{3, 4}

	ans := findMedianSortedArrays(num1, num2)
	if ans != 2.5 {
		t.Error("merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.", "ans = ", ans)
	}
}
