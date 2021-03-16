package group_anagrams

import (
	"reflect"
	"sort"
	"testing"
)

func TestGroupAnagramsExample1(t *testing.T) {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	ans := groupAnagrams(strs)
	rightAns := [][]string{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}
	// 双排序
	// 对rightAns排序
	for _, group := range rightAns {
		sort.Strings(group)
	}
	sort.Slice(rightAns, func(i, j int) bool {
		return groupLess(rightAns[i], rightAns[j])
	})
	// 对ans排序
	for _, group := range ans {
		sort.Strings(group)
	}
	sort.Slice(ans, func(i, j int) bool {
		return groupLess(ans[i], ans[j])
	})

	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

// compare func
func groupLess(strs1 []string, strs2 []string) bool {
	if len(strs1) < len(strs2) {
		return false
	} else if len(strs1) > len(strs2) {
		return true
	} else {
		// len(str1) == len(str2)
		for idx, str := range strs1 {
			if str < strs2[idx] {
				return false
			}
			if str > strs2[idx] {
				return true
			}
		}
	}
	return false
}

func TestGroupAnagramsExample2(t *testing.T) {
	strs := []string{""}
	ans := groupAnagrams(strs)
	rightAns := [][]string{{""}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestGroupAnagramsExample3(t *testing.T) {
	strs := []string{"a"}
	ans := groupAnagrams(strs)
	rightAns := [][]string{{"a"}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
