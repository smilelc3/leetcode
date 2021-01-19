package wildcard_matching

func isMatch(s string, p string) bool {
	// method 1: DP O(n*m)
	//return isMatchDP(s, p)

	// method 2: two pointer O(n)
	return isMatchTwoPointer(s, p)
}

func isMatchDP(s string, p string) bool {
	// 构建DP, 默认false
	dp := make([][]bool, len(s)+1)
	for i := range dp {
		dp[i] = make([]bool, len(p)+1)
	}

	// dp[i][j] 表示s[0...i-1] 与 p[0...j-1]是否匹配
	//dp[0][] 代表s是空串

	// 初始化
	dp[0][0] = true

	// 避免空串匹配***的情况
	for j := 0; j < len(p); j++ {
		if p[j] == '*' {
			dp[0][j+1] = dp[0][j]
		}
	}

	// 状态转移方程
	/*
		if p[j-1] == '?' || s[i-1] == p[j-1]
			dp[i][j] = dp[i-1][j-1]
		if p[j-1] == '*'
			dp[i][j] &= dp[i-1][j]  		*匹配多个, aa匹配* 等效于  a匹配*
			dp[i][j] &= dp[i-1][j-1]		*匹配一个, ba匹配b* 等效于 b匹配b
			dp[i][j] &= dp[i][j-1]			*匹配空,   b匹配b* 等效于 b匹配b
	*/

	for i := 0; i < len(s); i++ {
		for j := 0; j < len(p); j++ {
			if s[i] == p[j] {
				dp[i+1][j+1] = dp[i][j] // s[i] == p[j] 该状态等于前一个状态
			}
			if p[j] == '?' {
				dp[i+1][j+1] = dp[i][j] // p[j] == '?', 可匹配任何单个字符，该状态等于前一个状态
			}
			if p[j] == '*' {
				// '*' 可匹配任何字符序列（包括空串）
				dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1]
				dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j]
				dp[i+1][j+1] = dp[i+1][j+1] || dp[i+1][j]
			}
		}
	}

	return dp[len(s)][len(p)]
}

func isMatchTwoPointer(s string, p string) bool {
	i, j := 0, 0
	iStar, jStar := -1, -1
	for i < len(s) {
		//case 1, characters are matched
		if j < len(p) && (s[i] == p[j] || p[j] == '?') {
			i++
			j++
			//case 2, character is *
		} else if j < len(p) && p[j] == '*' {
			iStar = i //remember the * match position
			jStar = j
			j++ //just move j to next position, i stays on the current position as * matches with empty sequence
			//case 3, characters are not matched and iStar != -1 (means found * already)
		} else if iStar >= 0 {
			j = jStar + 1 //move j back to last position, redo the matching process
			iStar++
			i = iStar //redo the matching process from next i position
			//case 4, couldn't match
		} else {
			return false
		}
	}
	//handle p ending with * case
	for j < len(p) {
		if p[j] != '*' {
			return false
		} else {
			j++
		}
	}
	return j == len(p)
}
