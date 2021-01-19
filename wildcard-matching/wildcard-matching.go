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
			dp[0][j+1] = dp[0][j] // 与前一个状态一致
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
			} else if p[j] == '?' {
				dp[i+1][j+1] = dp[i][j] // p[j] == '?', 可匹配任何单个字符，该状态等于前一个状态
			} else if p[j] == '*' {
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
	// 这题缺陷在于只要出现*号，该*号到下一次出现 ?或* s串和p串之间的字符都无意义
	i, j := 0, 0
	iStar, jStar := -1, -1
	for i < len(s) {
		if j < len(p) && (s[i] == p[j] || p[j] == '?') { // 情况一 可直接匹配
			i++
			j++
		} else if j < len(p) && p[j] == '*' { // 情况二 当前p处理的是*
			iStar = i // 记录*出现时的指针位置
			jStar = j
			j++ // 继续处理p的下一个，s保持当前位置，认为*匹配空串
		} else if iStar >= 0 { // 情况三，当前什么都不匹配，但是之前存在的*, 字符都无意义,直接s往后继续移动，直到遇到下一次*或者？
			j = jStar + 1
			i = iStar + 1
			iStar++
		} else { // 情况四，啥都不匹配
			return false
		}
	}
	//p指针不到最后时需要保证当前指向之后都为*
	for j < len(p) {
		if p[j] != '*' {
			return false
		} else {
			j++
		}
	}
	return true
}
