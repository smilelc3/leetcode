package decode_ways

func numDecodings(s string) int {
	// 斐波那契变形
	//return numDecodingsV1(s)

	// 斐波那契变形 + 状态压缩
	return numDecodingsV2(s)
}

func numDecodingsV1(s string) int {
	sRunes := []rune(s)
	// dp[i] 表示s[0]~s[i]的可能性
	dp := make([]int, len(s))

	// 初始化
	// dp[0]
	if sRunes[0] != '0' {
		dp[0] = 1
	}
	// dp[1]
	if len(s) >= 2 {
		if sRunes[1] != '0' {
			dp[1] = dp[0]
		}
		if isTwoCharCanTranLetter(sRunes[0], sRunes[1]) {
			dp[1] += +1
		}
	}

	for idx := 2; idx < len(s); idx++ {
		if sRunes[idx] != '0' {
			dp[idx] = dp[idx-1]
		}
		if isTwoCharCanTranLetter(sRunes[idx-1], sRunes[idx]) {
			dp[idx] += dp[idx-2]
		}
	}
	return dp[len(s)-1]
}

func numDecodingsV2(s string) int {
	sRunes := []rune(s)
	// dp[i] 表示s[0]~s[i]的可能性
	var dp, preDp, prePreDp int

	// 初始化
	// dp[0]
	if sRunes[0] != '0' {
		prePreDp = 1
		if len(s) == 1 {
			return prePreDp
		}
	}
	// dp[1]
	if len(s) >= 2 {
		if sRunes[1] != '0' {
			preDp = prePreDp
		}
		if isTwoCharCanTranLetter(sRunes[0], sRunes[1]) {
			preDp += +1
		}
		if len(s) == 2 {
			return preDp
		}
	}

	for idx := 2; idx < len(s); idx++ {
		if sRunes[idx] == '0' {
			dp = 0
		} else {
			dp = preDp
		}
		if isTwoCharCanTranLetter(sRunes[idx-1], sRunes[idx]) {
			dp += prePreDp
		}
		prePreDp, preDp = preDp, dp
	}
	return dp
}

func isTwoCharCanTranLetter(first, second rune) bool {
	if first == '1' && '0' <= second && second <= '9' {
		return true
	} else if first == '2' && '0' <= second && second <= '6' {
		return true
	}
	return false
}
