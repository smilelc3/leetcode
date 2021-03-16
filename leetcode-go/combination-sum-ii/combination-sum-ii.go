package combination_sum_ii

import (
	"sort"
	"strconv"
	"strings"
)

func combinationSum2(candidates []int, target int) [][]int {
	// version 1: using Map to remove duplicates
	//return combinationSum2WithMapDeduplication(candidates, target)

	// version 2: edit "for" condition to remove duplicates
	return combinationSum2Best(candidates, target)
}

func combinationSum2Best(candidates []int, target int) [][]int {
	var combinations [][]int
	sort.Ints(candidates)
	deepFirstSearchCombination2Best(candidates, target, []int{}, 0, &combinations)
	return combinations
}

func deepFirstSearchCombination2Best(candidates []int, target int, searchResult []int, searchIdx int, pCombinations *[][]int) {
	for idx := searchIdx; idx < len(candidates); idx++ {
		// magic pruning！
		if idx > searchIdx && candidates[idx] == candidates[idx-1] {
			continue
		}
		num := candidates[idx]
		if target > num {
			searchResult = append(searchResult, num)
			nextTarget := target - num
			nextIdx := idx + 1
			if candidates[idx] <= nextTarget {
				deepFirstSearchCombination2Best(candidates, nextTarget, searchResult, nextIdx, pCombinations)
			}
			searchResult = searchResult[:len(searchResult)-1]

		} else if target == num {
			searchResult = append(searchResult, num)
			// deep copy
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

func combinationSum2WithMapDeduplication(candidates []int, target int) [][]int {
	var combinations [][]int
	combinationsStringSet := map[string]bool{}
	sort.Ints(candidates)
	deepFirstSearchCombination2MapDeduplication(candidates, target, []int{}, 0, &combinations, &combinationsStringSet)
	return combinations
}

func deepFirstSearchCombination2MapDeduplication(candidates []int, target int, searchResult []int, searchIdx int, pCombinations *[][]int, pCombinationsStringSet *map[string]bool) {
	for idx := searchIdx; idx < len(candidates); idx++ {
		num := candidates[idx]
		if target > num {
			searchResult = append(searchResult, num)
			nextTarget := target - num
			nextIdx := idx + 1
			if candidates[idx] <= nextTarget {
				deepFirstSearchCombination2MapDeduplication(candidates, nextTarget, searchResult, nextIdx, pCombinations, pCombinationsStringSet)
			}
			searchResult = searchResult[:len(searchResult)-1]

		} else if target == num {
			searchResult = append(searchResult, num)
			searchResultString := transCombination2String(searchResult)
			if _, ok := (*pCombinationsStringSet)[searchResultString]; !ok {
				(*pCombinationsStringSet)[searchResultString] = true
				// deep copy
				searchResultBack := make([]int, len(searchResult))
				copy(searchResultBack, searchResult)
				*pCombinations = append(*pCombinations, searchResultBack)
			}

			break // Pruning

		} else {
			// num > target
			break // Pruning
		}
	}
}

func transCombination2String(combination []int) string {
	var builder strings.Builder

	for idx, num := range combination {
		if idx != len(combination)-1 {
			builder.WriteString(strconv.Itoa(num))
			builder.WriteByte(' ')
		} else {
			builder.WriteString(strconv.Itoa(num))
		}
	}
	return builder.String()
}
