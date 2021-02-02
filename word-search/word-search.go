package word_search

func exist(board [][]byte, word string) bool {
	if len(board) == 0 || len(board[0]) == 0 {
		if len(word) == 0 {
			return true
		} else {
			return false
		}
	}

	hasVisitBoard := make([][]bool, len(board))
	for idx := 0; idx < len(hasVisitBoard); idx++ {
		hasVisitBoard[idx] = make([]bool, len(board[idx]))
	}
	wordBytes := []byte(word)
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[i]); j++ {
			isSolve := false
			hasVisitBoard[i][j] = true
			dfsBoard(i, j, board, wordBytes, 0, &hasVisitBoard, &isSolve)
			if isSolve {
				return true
			}
			hasVisitBoard[i][j] = false
		}
	}
	return false
}

func dfsBoard(i int, j int, board [][]byte, wordBytes []byte, idx int, pVisit *[][]bool, pIsSolve *bool) {
	//println(i, j, idx)
	if *pIsSolve {
		return
	}
	if board[i][j] == wordBytes[idx] {
		if idx == len(wordBytes)-1 {
			*pIsSolve = true
			return
		}
		if i-1 >= 0 && !(*pVisit)[i-1][j] {
			(*pVisit)[i-1][j] = true
			dfsBoard(i-1, j, board, wordBytes, idx+1, pVisit, pIsSolve)
			(*pVisit)[i-1][j] = false
		}
		if i+1 < len(board) && !(*pVisit)[i+1][j] {
			(*pVisit)[i+1][j] = true
			dfsBoard(i+1, j, board, wordBytes, idx+1, pVisit, pIsSolve)
			(*pVisit)[i+1][j] = false
		}
		if j-1 >= 0 && !(*pVisit)[i][j-1] {
			(*pVisit)[i][j-1] = true
			dfsBoard(i, j-1, board, wordBytes, idx+1, pVisit, pIsSolve)
			(*pVisit)[i][j-1] = false
		}
		if j+1 < len(board[i]) && !(*pVisit)[i][j+1] {
			(*pVisit)[i][j+1] = true
			dfsBoard(i, j+1, board, wordBytes, idx+1, pVisit, pIsSolve)
			(*pVisit)[i][j+1] = false
		}
	}
}
