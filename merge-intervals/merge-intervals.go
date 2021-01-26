package merge_intervals

import (
	"sort"
)

func merge(intervals [][]int) [][]int {
	if intervals == nil {
		return [][]int{}
	}
	var ans [][]int

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	curInterval := intervals[0]

	for idx := 1; idx < len(intervals); idx++ {
		if curInterval[1] >= intervals[idx][0] {
			curInterval[1] = max(intervals[idx][1], curInterval[1])
		} else {
			ans = append(ans, []int{curInterval[0], curInterval[1]})
			curInterval = intervals[idx]
		}
	}
	ans = append(ans, curInterval)
	return ans
}

func max(x int, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
