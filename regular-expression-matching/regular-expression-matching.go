package regular_expression_matching

func isMatch(s string, p string) bool {
	//dp[i+1][j+1]代表s[0...i]和p[0...j]的是否匹配
	//0 <= s.length <= 20
	//0 <= p.length <= 30

	// 构建DP
	dp := make([][]bool, len(s)+1)
	for i := range dp {
		dp[i] = make([]bool, len(p)+1)
	}

	// 初始化
	dp[0][0] = true
	/*
		为了消除a*这种与空串的匹配，
		比如s是空，a*或者a*b*都是满足条件的，
		执行这个循环就可以得到满足条件的情况，并设为true
	*/
	for j := 0; j < len(p); j++ {
		if p[j] == '*' && dp[0][j-1] {
			dp[0][j+1] = true
		}
	}
	for i := 0; i < len(s); i++ {
		for j := 0; j < len(p); j++ {
			if p[j] == '.' {
				dp[i+1][j+1] = dp[i][j] // 和前一个状态一致
			}
			if p[j] == s[i] {
				dp[i+1][j+1] = dp[i][j] // 和前一个状态一致
			}
			if p[j] == '*' {
				if p[j-1] == s[i] || p[j-1] == '.' {

					//以下三种状态取一个，为真
					//dp[i+1][j+1] = dp[i][j+1] // a* 匹配多个a
					//dp[i+1][j+1] = dp[i+1][j] // a* 匹配一个a
					//dp[i+1][j+1] = dp[i+1][j-1] // a* 匹配空
					dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1]
				} else {
					dp[i+1][j+1] = dp[i+1][j-1] //p前一个不匹配，*就匹配0次
				}
			}
		}
	}

	return dp[len(s)][len(p)]
}
