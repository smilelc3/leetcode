package median_of_two_sorted_arrays

// https://www.cnblogs.com/grandyang/p/4465932.html

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m := len(nums1)
	n := len(nums2)

	if m < n {
		return findMedianSortedArrays(nums2, nums1)
	}
	// m >= n always
	if n == 0 {
		return (float64(nums1[(m-1)/2]) + float64(nums1[m/2])) / 2
	}

	const IntMax = int(^uint(0) >> 1)
	const IntMin = ^IntMax

	left := 0
	right := n * 2
	for left <= right {
		mid2 := (left + right) / 2
		mid1 := m + n - mid2
		var L1, L2, R1, R2 int

		if mid1 != 0 {
			L1 = nums1[(mid1-1)/2]
		} else {
			L1 = IntMin
		}

		if mid2 != 0 {
			L2 = nums2[(mid2-1)/2]
		} else {
			L2 = IntMin
		}

		if mid1 != m*2 {
			R1 = nums1[mid1/2]
		} else {
			R1 = IntMax
		}

		if mid2 != n*2 {
			R2 = nums2[mid2/2]
		} else {
			R2 = IntMax
		}

		if L1 > R2 {
			left = mid2 + 1
		} else if L2 > R1 {
			right = mid2 - 1
		} else {
			return (float64(max(L1, L2)) + float64(min(R1, R2))) / 2
		}
	}
	return -1
}

func min(a int, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
