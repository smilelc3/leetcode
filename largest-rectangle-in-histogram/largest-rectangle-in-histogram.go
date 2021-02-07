package largest_rectangle_in_histogram

func largestRectangleArea(heights []int) int {
	// method 1: O(n^2)
	//return largestRectangleAreaDoubleLoop(heights)

	// method 2: O(n) height+width stack
	//return largestRectangleAreaStackHW(heights)

	// method 3: O(n) height.idx stack
	return largestRectangleAreaStackIdx(heights)
}

func largestRectangleAreaDoubleLoop(heights []int) int {
	maxArea := 0
	for left := 0; left < len(heights); left++ {
		minHeight := heights[left]
		for right := left; right < len(heights); right++ {
			if heights[right] == 0 {
				break
			}
			if (len(heights)-left)*minHeight <= maxArea {
				break
			}
			if minHeight > heights[right] {
				minHeight = heights[right]
			}
			if maxArea < (right-left+1)*minHeight {
				maxArea = (right - left + 1) * minHeight
			}
		}
	}
	return maxArea
}

type bar struct {
	height int
	width  int
}

func largestRectangleAreaStackHW(heights []int) int {
	barStack := make([]bar, 0, len(heights)+1)
	maxArea := 0
	// 人为追加末尾0高度的bar,便于保证stack清空
	heights = append(heights, 0)
	for _, height := range heights {
		if len(barStack) > 0 && barStack[len(barStack)-1].height > height {
			// 如果当前栈非空，且新元素高度比栈顶元素小，退回到最近比当前高度小的栈元素或则栈为空，并统计最小高度
			totWidth := 0
			for len(barStack) > 0 && barStack[len(barStack)-1].height >= height {
				popBar := barStack[len(barStack)-1]
				// pop 当前的元素
				barStack = barStack[:len(barStack)-1]
				// 更新curMinHeight
				totWidth += popBar.width
				// 更新maxArea
				maxArea = max(maxArea, popBar.height*totWidth)

			}
			// push 之前的元素汇总+新元素
			barStack = append(barStack, bar{
				height: height,
				width:  totWidth + 1,
			})
		} else {
			// push 当前的height
			barStack = append(barStack, bar{
				height: height,
				width:  1,
			})
		}

	}
	return maxArea
}

func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}

func largestRectangleAreaStackIdx(heights []int) int {
	var barIdxStack []int
	maxArea := 0
	// 人为追加末尾0高度的bar,便于保证stack清空
	heights = append(heights, 0)
	for idx := 0; idx < len(heights); {
		if len(barIdxStack) > 0 && heights[barIdxStack[len(barIdxStack)-1]] >= heights[idx] {
			// 如果当前栈非空，且新元素高度比栈顶元素小，退回到最近比当前高度小的栈元素或则栈为空
			// pop 当前的元素
			popIdx := barIdxStack[len(barIdxStack)-1]
			barIdxStack = barIdxStack[:len(barIdxStack)-1]
			// 更新maxArea
			if len(barIdxStack) == 0 { // pop弹出的bar,是之前最矮的
				maxArea = max(maxArea, idx*heights[popIdx])
			} else { // idx-barIdxStack[len(barIdxStack)-1]-1 计算的是pop出来的宽度
				maxArea = max(maxArea, (idx-barIdxStack[len(barIdxStack)-1]-1)*heights[popIdx])
			}
		} else {
			// push 当前的bar的idx，继续下一个
			barIdxStack = append(barIdxStack, idx)
			idx++
		}

	}
	return maxArea
}
