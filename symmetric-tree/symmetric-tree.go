package symmetric_tree

import . "leetcode-go/built-in"

func isSymmetric(root *TreeNode) bool {
	return isMirrorTree(root, root)

}

func isMirrorTree(treeA, treeB *TreeNode) bool {
	if treeA != nil && treeB == nil {
		return false
	}
	if treeA == nil && treeB != nil {
		return false
	}
	if treeA != nil && treeB != nil {
		if treeA.Val != treeB.Val {
			return false
		} else {
			if !isMirrorTree(treeA.Left, treeB.Right) {
				return false
			}
			if !isMirrorTree(treeA.Right, treeB.Left) {
				return false
			}
		}
	}
	return true
}
