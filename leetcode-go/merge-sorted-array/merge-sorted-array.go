package merge_sorted_array

func merge(nums1 []int, m int, nums2 []int, n int) {
	if m+n != len(nums1) {
		panic("m + n != len(nums1)")
	}
	nums1Idx := m - 1
	nums2Idx := n - 1
	for insertIdx := len(nums1) - 1; insertIdx >= 0; insertIdx-- {
		if nums2Idx < 0 {
			nums1[insertIdx] = nums1[nums1Idx]
			nums1Idx--
		} else if nums1Idx < 0 {
			nums1[insertIdx] = nums2[nums2Idx]
			nums2Idx--
		} else if nums1[nums1Idx] >= nums2[nums2Idx] {
			nums1[insertIdx] = nums1[nums1Idx]
			nums1Idx--
		} else {
			nums1[insertIdx] = nums2[nums2Idx]
			nums2Idx--
		}
	}
}
