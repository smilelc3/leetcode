package maximum_subarray

func maxSubArray(nums []int) int {
	if nums == nil {
		return 0
	}
	maxSubArraySum := nums[0]
	sum := 0
	for _, num := range nums {
		sum += num
		if sum > maxSubArraySum {
			maxSubArraySum = sum
		}
		if sum < 0 {
			sum = 0
		}
	}
	return maxSubArraySum
}
