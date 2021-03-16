package unique_binary_search_trees_ii

import (
	. "leetcode-go/built-in"
)

func generateTrees(n int) []*TreeNode {
	var ans []*TreeNode

	genBSTBacktrack(1, n, &ans)
	return ans
}

func genBSTBacktrack(start, end int, pStorage *[]*TreeNode) {
	if start == end {
		*pStorage = append(*pStorage, &TreeNode{Val: start})
		return
	}

	for val := start; val <= end; val++ {
		var left, right []*TreeNode
		if val-start > 0 {
			// 有左子树
			genBSTBacktrack(start, val-1, &left)
		}
		if end-val > 0 {
			// 有右子树
			genBSTBacktrack(val+1, end, &right)
		}
		// 既存在左子树
		if len(left) != 0 && len(right) != 0 {
			for i := 0; i < len(left); i++ {
				for j := 0; j < len(right); j++ {
					root := &TreeNode{Val: val}
					root.Left = left[i]
					root.Right = right[j]
					*pStorage = append(*pStorage, root)
				}
			}
		}
		// 仅存在左子树
		if len(left) != 0 && len(right) == 0 {
			for idx := 0; idx < len(left); idx++ {
				root := &TreeNode{Val: val}
				root.Left = left[idx]
				*pStorage = append(*pStorage, root)
			}
		}
		// 仅存在右子树
		if len(left) == 0 && len(right) != 0 {
			for idx := 0; idx < len(right); idx++ {
				root := &TreeNode{Val: val}
				root.Right = right[idx]
				*pStorage = append(*pStorage, root)
			}
		}
	}
}
