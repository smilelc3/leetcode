package restore_ip_addresses

import (
	"strconv"
)

func restoreIpAddresses(s string) []string {
	sBytes := []byte(s)

	var addresses []string
	deepFirstSearchIp(sBytes, 0, make([]int, 0, 3), &addresses)

	return addresses
}

func deepFirstSearchIp(str []byte, next int, dotIdxes []int, pStorage *[]string) {
	if len(dotIdxes) == 3 {
		address := string(str[:dotIdxes[0]+1]) + "."
		address += string(str[dotIdxes[0]+1:dotIdxes[1]+1]) + "."
		address += string(str[dotIdxes[1]+1:dotIdxes[2]+1]) + "."
		address += string(str[dotIdxes[2]+1:])
		*pStorage = append(*pStorage, address)
		return
	}
	for idx := next; idx < len(str)-1; idx++ {
		if len(dotIdxes) <= 1 {
			if isLegal8Bit(str[next : idx+1]) {
				dotIdxes = append(dotIdxes, idx)
				deepFirstSearchIp(str, idx+1, dotIdxes, pStorage)
				dotIdxes = dotIdxes[:len(dotIdxes)-1]
			} else {
				return
			}
		} else if isLegal8Bit(str[next:idx+1]) && isLegal8Bit(str[idx+1:]) {
			dotIdxes = append(dotIdxes, idx)
			deepFirstSearchIp(str, idx+1, dotIdxes, pStorage)
			dotIdxes = dotIdxes[:len(dotIdxes)-1]
		}
	}
}

func isLegal8Bit(str []byte) bool {
	if len(str) == 0 {
		return false
	}
	if str[0] == '0' {
		if len(str) == 1 {
			return true
		}
	} else if len(str) <= 3 {
		val, _ := strconv.Atoi(string(str))
		if val <= 255 {
			return true
		}
	}
	return false
}
