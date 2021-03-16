package combination_sum

import "sort"

func combinationSum(candidates []int, target int) [][]int {
	var combinations [][]int
	sort.Ints(candidates)
	deepFirstSearchCombination(candidates, target, []int{}, 0, &combinations)
	return combinations
}

func deepFirstSearchCombination(candidates []int, target int, searchResult []int, searchIdx int, pCombinations *[][]int) {
	for nextIdx := searchIdx; nextIdx < len(candidates); nextIdx++ {
		num := candidates[nextIdx]
		if target > num {
			searchResult = append(searchResult, num)
			nextTarget := target - num
			if candidates[nextIdx] <= nextTarget {
				deepFirstSearchCombination(candidates, nextTarget, searchResult, nextIdx, pCombinations)
			}
			searchResult = searchResult[:len(searchResult)-1]

		} else if target == num {
			searchResult = append(searchResult, num)
			searchResultBack := make([]int, len(searchResult))
			copy(searchResultBack, searchResult)
			*pCombinations = append(*pCombinations, searchResultBack)
			break // Pruning

		} else {
			// num > target
			break // Pruning
		}
	}
}
