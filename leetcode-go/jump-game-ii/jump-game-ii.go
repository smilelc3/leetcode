package jump_game_ii

import . "leetcode-go/built-in"
import "math"

func jump(nums []int) int {
	// O(n*m)
	//return jumpDP(nums)

	// O(n)
	return jumpExtent(nums)
}

// extent jump
func jumpExtent(nums []int) int {
	if len(nums) <= 1 {
		return 0
	}
	step := 0

	var nextFarthest, nextFarthestIdx int

	for idx := 0; idx < len(nums); {
		nextFarthest = idx + nums[idx]
		nextFarthestIdx = idx
		// has reach the last index
		if nextFarthest >= len(nums)-1 {
			return step + 1
		}
		// not reach the last index
		for next := 1; next <= nums[idx]; next++ {
			nextIdx := idx + next
			if nextIdx >= len(nums) {
				break
			}
			if nextFarthest < nextIdx+nums[nextIdx] {
				nextFarthest = nextIdx + nums[nextIdx]
				nextFarthestIdx = nextIdx
			}
		}

		// next idx start from nextFarthestIdx
		idx = nextFarthestIdx
		step++
	}
	return step
}

// DP algorithm

func jumpDP(nums []int) int {
	// DP algorithm O(m*n)
	// dp[i] means the min steps to reach i
	dp := make([]int, len(nums))
	for idx := 1; idx < len(nums); idx++ {
		dp[idx] = math.MaxInt32
	}

	for idx := 0; idx < len(nums); idx++ {
		for next := 1; next <= nums[idx]; next++ {
			nextIdx := idx + next
			if nextIdx >= len(nums) {
				break
			}
			dp[nextIdx] = Min(dp[nextIdx], dp[idx]+1)
		}
	}
	return dp[len(dp)-1]
}
