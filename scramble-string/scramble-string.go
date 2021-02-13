package scramble_string

import "sort"

func isScramble(s1 string, s2 string) bool {
	s1Bytes := []byte(s1)
	s2Bytes := []byte(s2)

	return isScrambleRecursion(s1Bytes, s2Bytes)
}

func isScrambleRecursion(s1 []byte, s2 []byte) bool {
	if len(s1) != len(s2) {
		return false
	}
	isSameStr := true

	s1Copy := make([]byte, len(s1))
	s2Copy := make([]byte, len(s2))

	copy(s1Copy, s1)
	copy(s2Copy, s2)

	sort.Slice(s1Copy, func(i, j int) bool {
		return s1Copy[i] < s1Copy[j]
	})
	sort.Slice(s2Copy, func(i, j int) bool {
		return s2Copy[i] < s2Copy[j]
	})
	for idx := 0; idx < len(s1); idx++ {
		if s1Copy[idx] != s2Copy[idx] {
			return false
		}
		if s1[idx] != s2[idx] {
			isSameStr = false
		}
	}
	if isSameStr {
		return true
	}

	for idx := 1; idx < len(s1); idx++ {
		s11 := s1[:idx]
		s12 := s1[idx:]
		s21 := s2[:idx]
		s22 := s2[idx:]
		if isScrambleRecursion(s11, s21) && isScrambleRecursion(s12, s22) {
			return true
		}
		s21 = s2[len(s2)-idx:]
		s22 = s2[:len(s2)-idx]
		if isScrambleRecursion(s11, s21) && isScrambleRecursion(s12, s22) {
			return true
		}
	}
	return false
}
