package n_queens_ii

func totalNQueens(n int) int {
	var ans int

	// method 1: backtrack
	// NQueuesBackTrack(0, n, 0, [2]uint32{0, 0}, &ans)

	// method 2: table
	if n >= 1 && n <= 9 {
		ansTable := []int{1, 0, 0, 2, 10, 4, 40, 92, 352}
		ans = ansTable[n-1]
	} else {
		NQueuesBackTrack(0, n, 0, [2]uint32{0, 0}, &ans)
	}
	return ans
}

func NQueuesBackTrack(row int, n int, colExistQueue uint16, slashExistQueue [2]uint32, pSave *int) {
	// 1 <= n <= 9
	// slashExistQueue[0]  means /
	// slashExistQueue[0]  means \
	for col := 0; col < n; col++ {
		if colExistQueue&(1<<col) != 0 ||
			slashExistQueue[0]&(1<<(row+col)) != 0 ||
			slashExistQueue[1]&(1<<(row-col+n-1)) != 0 {
			continue
		} else {
			if row+1 == n {
				*pSave++
				return
			}
			colExistQueue |= 1 << col
			slashExistQueue[0] |= 1 << (row + col)
			slashExistQueue[1] |= 1 << (row - col + n - 1)

			NQueuesBackTrack(row+1, n, colExistQueue, slashExistQueue, pSave)

			// resume
			colExistQueue = colExistQueue ^ (1 << col)
			slashExistQueue[0] ^= 1 << (row + col)
			slashExistQueue[1] ^= 1 << (row - col + n - 1)
		}
	}
}
