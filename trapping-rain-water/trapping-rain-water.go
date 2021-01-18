package trapping_rain_water

func trap(height []int) int {
	waterArea := 0

	// 不下降坐标
	var forwardAscArray []int
	var backwardAscArray []int

	isIdxHasWater := make([]bool, len(height))
	// 正向记录
	forwardHeight := -1
	for idx := 0; idx < len(height); idx++ {
		if height[idx] >= forwardHeight {
			forwardHeight = height[idx]
			forwardAscArray = append(forwardAscArray, idx)
		}
	}

	// 反向记录
	backwardHeight := -1
	for idx := len(height) - 1; idx >= 0; idx-- {
		if height[idx] >= backwardHeight {
			backwardHeight = height[idx]
			backwardAscArray = append(backwardAscArray, idx)
		}
	}

	if forwardAscArray != nil {
		left := forwardAscArray[0]
		for i := 1; i < len(forwardAscArray); i++ {
			right := forwardAscArray[i]
			// left <= right
			for waterIdx := left + 1; waterIdx <= right-1; waterIdx++ {
				// calculate water
				waterArea += height[left] - height[waterIdx]
				isIdxHasWater[waterIdx] = true
			}
			left = right
		}
	}

	if backwardAscArray != nil {
		right := backwardAscArray[0]
		for i := 1; i < len(backwardAscArray); i++ {
			left := backwardAscArray[i]
			// left >= right
			for waterIdx := right - 1; waterIdx >= left+1; waterIdx-- {
				// calculate water
				if !isIdxHasWater[waterIdx] {
					waterArea += height[right] - height[waterIdx]
					isIdxHasWater[waterIdx] = true
				}
			}
			right = left
		}
	}
	return waterArea
}
