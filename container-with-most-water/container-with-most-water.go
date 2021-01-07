package container_with_most_water

func maxAreaDoubleLoop(height []int) int {
	maxArea := 0
	for curIdx, curVal := range height {
		for preIdx, preVal := range height[:curIdx+1] {
			area := (curIdx - preIdx) * min(curVal, preVal)
			if area > maxArea {
				maxArea = area
			}
		}

	}
	return maxArea
}

func maxAreaTwoPointer(height []int) int {
	maxArea := 0
	i := 0
	j := len(height) - 1
	//
	for i < j {
		area := (j - i) * min(height[i], height[j])
		if area > maxArea {
			maxArea = area
		}
		if height[i] < height[j] {
			i++
		} else {
			j--
		}

	}
	return maxArea
}

func maxArea(height []int) int {
	//return maxAreaDoubleLoop(height)
	return maxAreaTwoPointer(height)
}

func min(x int, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}
