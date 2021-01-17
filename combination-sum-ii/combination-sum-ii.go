package combination_sum_ii

import (
	"sort"
	"strconv"
	"strings"
)

func combinationSum2(candidates []int, target int) [][]int {
	var combinations [][]int
	combinationsStringSet := map[string]bool{}
	sort.Ints(candidates)
	deepFirstSearchCombination2(candidates, target, []int{}, 0, &combinations, &combinationsStringSet)
	return combinations
}

func deepFirstSearchCombination2(candidates []int, target int, searchResult []int, searchIdx int, pCombinations *[][]int, pCombinationsStringSet *map[string]bool) {
	for idx := searchIdx; idx < len(candidates); idx++ {
		num := candidates[idx]
		if target > num {
			searchResult = append(searchResult, num)
			nextTarget := target - num
			nextIdx := idx + 1
			if candidates[idx] <= nextTarget {
				deepFirstSearchCombination2(candidates, nextTarget, searchResult, nextIdx, pCombinations, pCombinationsStringSet)
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
