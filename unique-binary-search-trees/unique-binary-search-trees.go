package unique_binary_search_trees

import "math/big"

func numTrees(n int) int {
	// version 1: DP
	//return numTreesDP(n)

	// version 2: formula
	return numTreesFormula(n)
}

func numTreesDP(n int) int {
	dp := make([]int, n+1)
	dp[0] = 1
	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			dp[i] += dp[j] * dp[i-1-j]
		}
	}
	return dp[n]
}

func numTreesFormula(n int) int {
	// 卡特兰数公式
	// $F(n) = C_{2n}^{n}-C_{2n}^{n+1} = \frac{C_{2n}^{n}}{n+1}$
	return int(comb(2*n, n) / int64(n+1))
}

func comb(n, k int) int64 {
	ans := fac(n)
	ans.Div(ans, fac(k)).Div(ans, fac(n-k))
	return ans.Int64()
}

func fac(n int) *big.Int {
	ans := big.NewInt(1)
	if n == 0 || n == 1 {
		return ans
	} else {
		for idx := 2; idx <= n; idx++ {
			ans.Mul(ans, big.NewInt(int64(idx)))
		}
		return ans
	}
}
