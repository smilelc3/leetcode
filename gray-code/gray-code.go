package gray_code

func grayCode(n int) []int {
	return grayCodeMethod2(n)
}

func grayCodeMethod1(n int) []int {
	// 手动构造法
	ans := make([]int, 1, 1<<n)
	// 以二进制为0值的格雷码为第零项，
	// 第一项改变最右边的位元，
	// 第二项改变右起第一个为1的位元的左边位元，
	// 如此反复，即可排列出n个位元的格雷码。
	for idx := 1; idx < 1<<n; idx++ {
		if idx&1 == 1 { // 第一项
			ans = append(ans, ans[idx-1]^1)
		} else { // 第二项
			bit := 0 // 右起第一个为1的位元位置
			for ans[idx-1]>>bit&1 == 0 {
				bit++
			}
			ans = append(ans, ans[idx-1]^(1<<(bit+1)))
		}
	}
	return ans
}

func grayCodeMethod2(n int) []int {
	// G(n) = n ^ (n/2)
	ans := make([]int, 0, 1<<n)
	for idx := 0; idx < 1<<n; idx++ {
		ans = append(ans, idx^(idx>>1))
	}
	return ans
}
