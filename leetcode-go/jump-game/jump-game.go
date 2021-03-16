package jump_game

func canJump(nums []int) bool {
	if len(nums) <= 1 {
		return true
	} else if nums[0] == 0 {
		return false
	}
	idx := len(nums) - 2
	for idx >= 0 {
		if nums[idx] == 0 {
			nextIdx := idx - 1
			for nextIdx >= 0 && nextIdx+nums[nextIdx] <= idx {
				nextIdx--
			}
			if nextIdx < 0 {
				return false
			} else {
				idx = nextIdx - 1
			}
		} else {
			idx--
		}
	}
	return true
}
