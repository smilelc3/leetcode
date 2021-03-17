package built_in

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 给定nums构建Tree
func GenTreeByNums(nums []int, nilNum int) *TreeNode {
	if len(nums) == 0 || nums[0] == nilNum {
		return nil
	}
	root := &TreeNode{Val: nums[0]}
	nums = nums[1:]
	preLevelNode := []*TreeNode{root} // 维护上一层所有非空父节点
	for len(nums) != 0 {
		numPreLevelNodes := len(preLevelNode)
		numsIdx := 0
		for idx := 0; idx < numPreLevelNodes; idx++ {
			if numsIdx < len(nums) {
				if nums[numsIdx] != nilNum {
					preLevelNode[idx].Left = &TreeNode{Val: nums[numsIdx]}
					preLevelNode = append(preLevelNode, preLevelNode[idx].Left)
				}
				numsIdx++
			}
			if numsIdx < len(nums) {
				if nums[numsIdx] != nilNum {
					preLevelNode[idx].Right = &TreeNode{Val: nums[numsIdx]}
					preLevelNode = append(preLevelNode, preLevelNode[idx].Right)
				}
				numsIdx++
			}
		}
		preLevelNode = preLevelNode[numPreLevelNodes:]
		nums = nums[numsIdx:]
	}
	return root
}

// 先序遍历(Morris遍历)
func PreorderTraversalMorris(root *TreeNode, visitFunc func(node *TreeNode)) {
	// 1. 如果cur无左子树，cur向右移动（cur=cur.right）
	// 2. 如果cur有左子树，找到cur左子树上最右的节点，记为mostRight
	//    a. 如果mostRight的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
	//    b. 如果mostRight的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
	// 3. 重复1、2,直到cur为空

	cur := root
	var mostRight *TreeNode
	for cur != nil {
		// cur表示当前节点，mostRight表示cur的左子树的最右节点
		mostRight = cur.Left
		if mostRight != nil {
			// cur有左子树，找到cur左子树的最右节点
			for mostRight.Right != nil && mostRight.Right != cur {
				mostRight = mostRight.Right
			}
			if mostRight.Right == nil {
				// mostRight的right指向空，让其指向cur，cur向左移动
				mostRight.Right = cur
				visitFunc(cur) // 先序中序访问不同点
				cur = cur.Left
			} else {
				// mostRight的right指向cur，让其指向空，cur向右移动
				mostRight.Right = nil
				cur = cur.Right
			}
		} else {
			// 如果cur无左子树，cur向右移动
			visitFunc(cur)
			cur = cur.Right
		}
	}
}

// 中序遍历(Morris遍历)
func InorderTraversalMorris(root *TreeNode, visitFunc func(node *TreeNode)) {
	// 1. 如果cur无左子树，cur向右移动（cur=cur.right）
	// 2. 如果cur有左子树，找到cur左子树上最右的节点，记为mostRight
	//    a. 如果mostRight的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
	//    b. 如果mostRight的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
	// 3. 重复1、2,直到cur为空

	cur := root
	var mostRight *TreeNode
	for cur != nil {
		// cur表示当前节点，mostRight表示cur的左子树的最右节点
		mostRight = cur.Left
		if mostRight != nil {
			// cur有左子树，找到cur左子树的最右节点
			for mostRight.Right != nil && mostRight.Right != cur {
				mostRight = mostRight.Right
			}
			if mostRight.Right == nil {
				// mostRight的right指向空，让其指向cur，cur向左移动
				mostRight.Right = cur
				cur = cur.Left
			} else {
				// mostRight的right指向cur，让其指向空，cur向右移动
				mostRight.Right = nil
				visitFunc(cur) // 先序中序访问不同点
				cur = cur.Right
			}
		} else {
			// 如果cur无左子树，cur向右移动
			visitFunc(cur)
			cur = cur.Right
		}
	}
}

// 后序遍历(Morris遍历)
func PostorderTraversalMorris(root *TreeNode, visitFunc func(node *TreeNode)) {
	// 1. 如果cur无左子树，cur向右移动（cur=cur.right）
	// 2. 如果cur有左子树，找到cur左子树上最右的节点，记为mostRight
	//    a. 如果mostRight的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
	//    b. 如果mostRight的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
	// 3. 重复1、2,直到cur为空

	cur := root
	var mostRight *TreeNode
	for cur != nil {
		// cur表示当前节点，mostRight表示cur的左子树的最右节点
		mostRight = cur.Left
		if mostRight != nil {
			// cur有左子树，找到cur左子树的最右节点
			for mostRight.Right != nil && mostRight.Right != cur {
				mostRight = mostRight.Right
			}
			if mostRight.Right == nil {
				// mostRight的right指向空，让其指向cur，cur向左移动
				mostRight.Right = cur
				cur = cur.Left
			} else {
				// mostRight的right指向cur，让其指向空，cur向右移动
				mostRight.Right = nil
				visitEdge(cur.Left, visitFunc) //  # 在第二次到达时，逆序访问cur节点的左子树的右边界
				cur = cur.Right
			}
		} else {
			// 如果cur无左子树，cur向右移动
			cur = cur.Right
		}
	}
	visitEdge(root, visitFunc)
}

// 访问边界
func visitEdge(node *TreeNode, visitFunc func(node *TreeNode)) {
	tail := reverseEdge(node)
	cur := tail
	for cur != nil {
		visitFunc(cur)
		cur = cur.Right
	}
	reverseEdge(node)
}

// 反转右边界
func reverseEdge(node *TreeNode) *TreeNode {
	var pre, next *TreeNode
	for node != nil {
		next = node.Right
		node.Right = pre
		pre = node
		node = next
	}
	return pre
}
