package interleaving_string

func isInterleave(s1 string, s2 string, s3 string) bool {
	// original DP space O(mn)
	//return isInterleaveDP(s1,s2,s3)

	// dp rolling array space O(min(m,n))
	if len(s1) > len(s2) {
		s1, s2 = s2, s1
	}
	return isInterleaveDPWithRollArray(s1, s2, s3)
}

func isInterleaveDP(s1 string, s2 string, s3 string) bool {
	// 长度不等直接返回false
	if len(s1)+len(s2) != len(s3) {
		return false
	}
	// 排除空字串特殊情况
	if s1 == "" {
		return s2 == s3
	} else if s2 == "" {
		return s1 == s3
	}

	// 以下确保s1,s2均不为空串
	// dp[i][j] 表示s1[:i]与s2[:j]组合是否匹配s3[0:i+j]
	dp := make([][]bool, len(s1)+1)
	for idx := 0; idx <= len(s1); idx++ {
		dp[idx] = make([]bool, len(s2)+1)
	}
	s1Bytes, s2Bytes, s3Bytes := []byte(s1), []byte(s2), []byte(s3)

	// 初始化
	dp[0][0] = true
	for idx := 1; idx <= len(s1); idx++ {
		if s1Bytes[idx-1] == s3Bytes[idx-1] {
			dp[idx][0] = dp[idx-1][0]
		}
	}

	for idx := 1; idx <= len(s2); idx++ {
		if s2Bytes[idx-1] == s3Bytes[idx-1] {
			dp[0][idx] = dp[0][idx-1]
		}
	}
	for i := 1; i <= len(s1); i++ {
		for j := 1; j <= len(s2); j++ {
			if s2Bytes[j-1] == s3[i+j-1] {
				dp[i][j] = dp[i][j] || dp[i][j-1]
			}
			if s1Bytes[i-1] == s3[i+j-1] {
				dp[i][j] = dp[i][j] || dp[i-1][j]
			}
		}
	}
	return dp[len(s1)][len(s2)]
}

func isInterleaveDPWithRollArray(less string, more string, mix string) bool {
	// 长度不等直接返回false
	if len(less)+len(more) != len(mix) {
		return false
	}
	// 排除空字串特殊情况
	if less == "" {
		return more == mix
	} else if more == "" {
		return less == mix
	}

	// 以下确保less,more均不为空串
	// dp[i][j] 表示less[:i]与more[:j]组合是否匹配mix[0:i+j]
	dp := make([]bool, len(less)+1)
	lessBytes, moreBytes, mixBytes := []byte(less), []byte(more), []byte(mix)

	// 初始化
	dp[0] = true
	for idx := 1; idx <= len(less); idx++ {
		if lessBytes[idx-1] == mixBytes[idx-1] {
			dp[idx] = dp[idx-1]
		}
	}

	for i := 1; i <= len(more); i++ {
		for j := 0; j <= len(less); j++ {
			dp[j] = dp[j] && moreBytes[i-1] == mixBytes[i+j-1]
			if j > 0 && lessBytes[j-1] == mixBytes[i+j-1] {
				dp[j] = dp[j] || dp[j-1]
			}
		}
	}
	return dp[len(less)]
}
