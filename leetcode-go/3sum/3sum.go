package three_sum

import "sort"

func threeSumDoubleLoopWithMap(nums []int) [][]int {
	var triplets [][]int
	// using hashMap
	sort.Ints(nums)
	intToIdxMap := map[int]int{}
	tripletsSet := map[[3]int]bool{}
	for idx, num := range nums {
		intToIdxMap[num] = idx
	}
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if threeIdx, ok := intToIdxMap[0-(nums[i]+nums[j])]; ok && threeIdx != i && threeIdx != j {
				triplet := [3]int{nums[i], nums[j], nums[threeIdx]}
				sort.Ints(triplet[:])
				if _, isRepeat := tripletsSet[triplet]; !isRepeat {
					tripletsSet[triplet] = true
					triplets = append(triplets, triplet[:])
				}
			}
		}
	}
	return triplets
}

func threeSumTwoPointersWithMap(nums []int) [][]int {
	var triplets [][]int
	sort.Ints(nums)
	for idx, num := range nums {
		if idx > 0 && num == nums[idx-1] {
			continue
		}
		left := idx + 1
		right := len(nums) - 1
		for left < right {
			sum := num + nums[left] + nums[right]
			if sum > 0 {
				right--
			} else if sum < 0 {
				left++
			} else { // sum == 0
				triplets = append(triplets, []int{num, nums[left], nums[right]})
				left++
				for nums[left] == nums[left-1] && left < right {
					left++
				}
			}
		}
	}
	return triplets
}

func threeSum(nums []int) [][]int {
	// method 1
	//return threeSumDoubleLoopWithMap(nums)

	// method 2
	return threeSumTwoPointersWithMap(nums)
}
