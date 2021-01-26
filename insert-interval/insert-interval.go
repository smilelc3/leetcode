package insert_interval

func insert(intervals [][]int, newInterval []int) [][]int {
	if len(intervals) == 0 || len(intervals[0]) == 0 {
		return [][]int{newInterval}
	}
	if len(newInterval) != 2 {
		return intervals
	}
	idx := 0
	var mergeIntervals [][]int

	for idx < len(intervals) {
		if intervals[idx][0] > newInterval[1] {
			// needn't merge
			mergeIntervals = append(mergeIntervals, newInterval)
			mergeIntervals = append(mergeIntervals, intervals[idx:]...)
			break
		} else if isTwoIntervalMix(intervals[idx], newInterval) {
			// start merge
			mergeInterval := mergeTwoInterval(intervals[idx], newInterval)
			idx++
			for idx < len(intervals) && isTwoIntervalMix(intervals[idx], mergeInterval) {
				mergeInterval = mergeTwoInterval(intervals[idx], mergeInterval)
				idx++
			}
			mergeIntervals = append(mergeIntervals, mergeInterval)
			mergeIntervals = append(mergeIntervals, intervals[idx:]...)
			break
		} else {
			mergeIntervals = append(mergeIntervals, intervals[idx])
		}
		idx++
	}
	if intervals[len(intervals)-1][1] < newInterval[0] {
		// needn't merge
		mergeIntervals = append(mergeIntervals, newInterval)
	}
	return mergeIntervals
}

func isTwoIntervalMix(itv1, itv2 []int) bool {
	if itv2[0] <= itv1[1] && itv1[1] <= itv2[1] {
		return true
	} else if itv2[0] <= itv1[0] && itv1[0] <= itv2[1] {
		return true
	} else if itv1[0] < itv2[0] && itv2[1] < itv1[1] {
		return true
	}
	return false
}

func mergeTwoInterval(itv1, itv2 []int) []int {
	return []int{min(itv1[0], itv2[0]), max(itv1[1], itv2[1])}
}

func max(x int, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}

func min(x int, y int) int {
	if x > y {
		return y
	} else {
		return x
	}
}
