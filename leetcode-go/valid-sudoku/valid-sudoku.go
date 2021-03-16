package valid_sudoku

func isValidSudoku(board [][]byte) bool {
	// using bit operation
	bitRows := [9]uint16{}
	bitCols := [9]uint16{}
	bitBoxes := [9]uint16{}

	for rowIdx := 0; rowIdx < 9; rowIdx++ {
		for colIdx := 0; colIdx < 9; colIdx++ {
			byteData := board[rowIdx][colIdx]
			if byteData == '.' {
				continue
			}
			data := byteData - '0'

			// check Row
			if bitRows[rowIdx]>>data&1 == 1 {
				return false
			} else {
				bitRows[rowIdx] = bitRows[rowIdx] | (1 << data)
			}

			// check col
			if bitCols[colIdx]>>data&1 == 1 {
				return false
			} else {
				bitCols[colIdx] = bitCols[colIdx] | (1 << data)
			}

			// check box
			boxIdx := rowIdx/3*(9/3) + colIdx/3
			if bitBoxes[boxIdx]>>data&1 == 1 {
				return false
			} else {
				bitBoxes[boxIdx] = bitBoxes[boxIdx] | (1 << data)
			}
		}
	}
	return true
}
