package next_permutation

func nextPermutation(nums []int) {
	// algorithm come from C++ std  func: next_permutation
	// link: https://en.cppreference.com/w/cpp/algorithm/next_permutation

	first := 0
	last := len(nums)
	if first == last {
		return
	}
	i := last
	i--
	if first == i {
		return
	}
	// last指向最后一个元素的后一个位置
	// 要获取最后一个元素需要回退一步，即--last指向最后一个元素
	// 程序运行到此处，i指向最后一个元素

	for {
		/*
		   * 1. 首先，从倒数第二个数字开始右向左找到第一个递减的数字的位置i，以953882为例，
		   第一个非递增的数字为3，并记该数字的前一个数字的位置为i1(数字8)；

		   * 2. 从最后一个数字开始往左找到第一个大于位置i（数字3）的数字8，
		   记其位置为i2（这里的倒数第2位）；

		   * 3. 交换i与i2位置的数字，得到958832；

		   * 4. 将i1到结尾的数字逆序，得到958238，此即为953882的下一个排列958238.
		*/

		var i1, i2 int
		i1 = i
		i--
		if nums[i] < nums[i1] {
			i2 = last
			i2--
			for nums[i] >= nums[i2] {
				i2--
			}
			nums[i], nums[i2] = nums[i2], nums[i]
			reverse(nums, i1, last)
			return
		}
		if i == first {
			reverse(nums, first, last)
			return
		}

	}
}

func reverse(nums []int, start int, end int) {
	// start 指向开始位置，end指向结束位置的下一个位置
	for ; start < end-1; start, end = start+1, end-1 {
		nums[start], nums[end-1] = nums[end-1], nums[start]
	}
}
