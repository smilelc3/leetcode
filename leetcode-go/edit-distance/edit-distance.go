package edit_distance

import . "leetcode-go/built-in"

func minDistance(word1 string, word2 string) int {
	// dp[i][j] 表示word1[0,i-1] 与 word2[0,j-1] 的最小编辑距离
	// TODO: 可继续优化空间复杂度
	word1Bytes := []byte(word1)
	word2Bytes := []byte(word2)

	dp := make([][]int, len(word1)+1)

	for idx := 0; idx <= len(word1); idx++ {
		dp[idx] = make([]int, len(word2)+1)
	}

	for idx := 1; idx <= len(word2); idx++ {
		dp[0][idx] = idx
	}
	for idx := 1; idx <= len(word1); idx++ {
		dp[idx][0] = idx
	}

	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			minDelete := Min(dp[i][j-1]+1, dp[i-1][j]+1)
			minReplace := dp[i-1][j-1]
			if word1Bytes[i-1] != word2Bytes[j-1] {
				minReplace++
			}
			dp[i][j] = Min(minReplace, minDelete)
		}
	}

	return dp[len(word1)][len(word2)]
}
