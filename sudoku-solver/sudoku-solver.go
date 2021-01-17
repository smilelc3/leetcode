package sudoku_solver

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
	"time"
)

func solveSudoku(board [][]byte) {
	sudoku := NewSudoku()
	data := transBytesDataToArray(board)
	sudoku.LoadDataFromArray(data)
	startTime := time.Now().UnixNano()
	isSolved := DanceLinkSolver(sudoku) // 解数独
	endTime := time.Now().UnixNano()

	if isSolved {
		//sudoku.Show()
		fmt.Println("舞蹈链法所用时间：", float64(endTime-startTime)/1e6, "ms")
		transArrayToBytesData(sudoku.GetDataByArray(), board)
	}
}

func transBytesDataToArray(board [][]byte) [81]uint8 {
	data := [81]uint8{}
	for rowIdx := 0; rowIdx < 9; rowIdx++ {
		for colIdx := 0; colIdx < 9; colIdx++ {
			byteNum := board[rowIdx][colIdx]
			if byteNum == '.' {
				continue
			}
			num := byteNum - '0'
			data[rowIdx*9+colIdx] = num
		}
	}
	return data
}

func transArrayToBytesData(data [81]uint8, board [][]byte) {
	for rowIdx := 0; rowIdx < 9; rowIdx++ {
		for colIdx := 0; colIdx < 9; colIdx++ {
			num := data[rowIdx*9+colIdx]
			if num != 0 {
				board[rowIdx][colIdx] = num + '0'
			} else {
				board[rowIdx][colIdx] = '.'
			}
		}
	}
}

/* github.com/smilelc3/sudoku-solver/Sudoku/sudoku_class.go */

// Sudoku Class
type Sudoku struct {
	Cells       [81]*Cell
	Boxes       [9]Box
	isLoadData  bool
	blankInShow byte
	Rows        [9]Row
	Cols        [9]Col
}

// 每一个9小格为一个Box
type Box struct {
	Cells  [9]*Cell
	BoxIdx uint8
}

//每一个数字为一个Cell
type Cell struct {
	//绑定行列
	Row *Row
	Col *Col

	//绑定Box
	Box *Box

	// 受Cell修改影响的其他的cells集合
	AffectedCellsSet map[*Cell]struct{}

	Val uint8
	Idx uint8
}

// 定义横行
type Row struct {
	line
	RowIdx uint8
}

// 定义纵行
type Col struct {
	line
	ColIdx uint8
}

// 定义行
type line struct {
	Cells [9]*Cell
}

/* github.com/smilelc3/sudoku-solver/Sudoku/sudoku_func.go */

// 构造函数
func NewSudoku() *Sudoku {
	sudoku := new(Sudoku)

	sudoku.isLoadData = false
	sudoku.blankInShow = ' '

	var row, col uint8
	for row = 0; row < 9; row++ {
		for col = 0; col < 9; col++ {
			targetCell := new(Cell)
			// 为sudoku构建Rows Cols
			sudoku.Rows[row].Cells[col] = targetCell
			sudoku.Cols[col].Cells[row] = targetCell
			sudoku.Rows[row].RowIdx = row
			sudoku.Cols[col].ColIdx = col

			//为sudoku构建Boxes
			boxIdx := sudoku.getBoxIdxByCoords(row, col)
			cellIdx := sudoku.GetCellIdByCoords(row, col)
			sudoku.Boxes[boxIdx].Cells[cellIdx] = targetCell
			sudoku.Boxes[boxIdx].BoxIdx = boxIdx

			// 构建Cell(值，索引，父链)
			dataIdx := row*9 + col
			targetCell.Idx = dataIdx
			targetCell.Row = &sudoku.Rows[row]
			targetCell.Col = &sudoku.Cols[col]
			targetCell.Box = &sudoku.Boxes[boxIdx]

			sudoku.Cells[dataIdx] = targetCell

		}
	}

	// 构造cell对象的
	for row = 0; row < 9; row++ {
		for col = 0; col < 9; col++ {
			thisCell := sudoku.Rows[row].Cells[col]
			thisCell.AffectedCellsSet = thisCell.GetCellAffectedCellsSet()
		}
	}
	return sudoku
}

//从List加载数据
func (Sudoku *Sudoku) LoadDataFromArray(data [81]uint8) {
	for idx, cell := range Sudoku.Cells {
		cell.Val = data[idx]
	}
	Sudoku.isLoadData = true
}

//从控制框中输入数据
func (Sudoku *Sudoku) LoadDataFromInput() {
	fmt.Println("请输入81个 [1-9] 的数字， 待填写数字用 0 代替, 数字间用空格间隔")
	var data [9 * 9]uint8
	for idx := 0; idx < (9 * 9); idx++ {
		_, err := fmt.Scanf("%d", &data[idx])
		if err != nil {
			panic(err)
		}
		if data[idx] > 9 {
			panic("数字不合法")
		}
	}
	Sudoku.LoadDataFromArray(data)
}

//从文本文件中输入数据
func (Sudoku *Sudoku) LoadDataFromFile(filePath string, splitMark string) {
	data, err := ioutil.ReadFile(filePath)
	if err != nil {
		fmt.Println("文件读取错误")
		panic(err)

	}
	idx := 0
	stringLines := strings.Split(string(data), "\n")
	for _, Line := range stringLines {
		stringValues := strings.Split(Line, splitMark)
		for _, stringValue := range stringValues {
			stringValue = strings.Trim(stringValue, " \t\r")
			if stringValue == "" {
				continue
			}
			val, err := strconv.Atoi(stringValue)
			if err != nil {
				fmt.Println("文件内容错误")
				panic(err)
			}
			if val > 9 || val < 0 {
				panic("文件数据错误")
			}
			Sudoku.Cells[idx].Val = uint8(val)
			idx++
		}
	}
	if idx != 81 {
		panic("数据内容错误")
	} else {
		Sudoku.isLoadData = true
	}

}

// 通过坐标获取值
func (Sudoku *Sudoku) GetValByCoords(row uint8, col uint8) uint8 {
	return Sudoku.GetCellByCoords(row, col).Val
}

//通过坐标获取Box
func (Sudoku *Sudoku) GetBoxByCoords(row uint8, col uint8) *Box {
	return &Sudoku.Boxes[Sudoku.getBoxIdxByCoords(row, col)]
}

// 通过坐标返回Box idx
func (Sudoku *Sudoku) getBoxIdxByCoords(row uint8, col uint8) uint8 {
	boxIdx := row/3*(9/3) + col/3
	return boxIdx
}

//通过坐标返回Cell位于Box的内部 cell id
func (Sudoku *Sudoku) GetCellIdByCoords(row uint8, col uint8) uint8 {
	cellIdx := row%3*3 + col%3
	return cellIdx
}

//通过坐标获取Cell对象
func (Sudoku *Sudoku) GetCellByCoords(row uint8, col uint8) *Cell {
	return Sudoku.GetBoxByCoords(row, col).Cells[Sudoku.GetCellIdByCoords(row, col)]
}

// 格式化数独输出
func (Sudoku *Sudoku) GetFormString() string {
	if Sudoku.isLoadData == false {
		panic("请先加载数据")
	}
	var row, col uint8
	formString := ""
	formString += "+-----------------------------+" + "\n"
	for row = 0; row < 9; row++ {
		formString += "| "
		for col = 0; col < 9; col++ {
			if Sudoku.GetValByCoords(row, col) == 0 {
				formString += string(Sudoku.blankInShow)
			} else {
				formString += fmt.Sprintf("%d", Sudoku.GetValByCoords(row, col))
			}

			if col == 2 || col == 5 {
				formString += " | "
			} else if col == 8 {
				formString += " |"
			} else {
				formString += "  "
			}

		}
		formString += "\n"
		if row == 2 || row == 5 {
			formString += "|---------+---------+---------|" + "\n"
		}
	}
	formString += "+-----------------------------+" + "\n"
	return formString
}

// 以一维数组返回所有数据
func (Sudoku *Sudoku) GetDataByArray() [81]uint8 {
	data := [81]uint8{}
	for idx, cell := range Sudoku.Cells {
		data[idx] = cell.Val
	}
	return data
}

// 设置blank
func (Sudoku *Sudoku) SetBlank(blank byte) {
	Sudoku.blankInShow = blank
}

// 打印数独
func (Sudoku *Sudoku) Show() {
	fmt.Print(Sudoku.GetFormString())
}

// 获取某一个cell所受影响的周边cells的集合（借助map[*Cell]struct{}实现）
func (cell *Cell) GetCellAffectedCellsSet() map[*Cell]struct{} {
	if cell.AffectedCellsSet != nil {
		return cell.AffectedCellsSet
	}
	var EXIST = struct{}{}
	cellsSet := make(map[*Cell]struct{})
	for _, nearCell := range cell.Box.Cells {
		if nearCell != cell {
			cellsSet[nearCell] = EXIST
		}
	}
	for _, nearCell := range cell.Row.Cells {
		if nearCell != cell {
			cellsSet[nearCell] = EXIST
		}
	}

	for _, nearCell := range cell.Col.Cells {
		if nearCell != cell {
			cellsSet[nearCell] = EXIST
		}
	}
	return cellsSet
}

/* github.com/smilelc3/sudoku-solver/Sudoku/dance_link_algorithm.go  */

// 精确覆盖问题的定义：给定一个由0-1组成的矩阵，是否能找到一个行的集合，使得集合中每一列都恰好包含一个1

type DanceLink struct {
	Headers []*node // arg参数便于header使用计数优化
	Nodes   []*node // 存所有Node

	RowFirstNode []*node //记录每行第一个节点，辅助空间，便于从行查找，构建左右链

	AnsStack []int //答案栈

	AllAns        [][]int // 存所有答案
	needSolvedNum int     //需要解的个数
}

//Node节点类u
type node struct {
	arg    int //  未定义参数
	Left   *node
	Right  *node
	Up     *node
	Down   *node
	RowNum int
	ColNum int
}

// 记录node方向备份，便于恢复
type nodeDirectBackup struct {
	RawNode      *node // 指向原始数据
	RawNodeLeft  *node
	RawNodeRight *node
	RawNodeUp    *node
	RawNodeDown  *node
}

// 标记列首元素C，返回被标记的元素集合
func (danceLink *DanceLink) markOneHeaderNode(header *node) (map[*node]bool, []int, []map[*node]bool) {
	markedNodesSet := make(map[*node]bool) // 当前列首元素所标记的结果

	var rowNumSet []int                       // 涉及到的行号集合
	var rowNumLinkHeadersSet []map[*node]bool // 行号对应的所关联的其他列首元素

	markedNodesSet[header] = true
	cNode := header.Down
	for cNode != header {
		markedNodesSet[cNode] = true
		rowNumSet = append(rowNumSet, cNode.RowNum)
		rNode := cNode.Right
		rowNumLinkHeadersSet = append(rowNumLinkHeadersSet, make(map[*node]bool))
		for rNode != cNode {
			markedNodesSet[rNode] = true
			rowNumLinkHeadersSet[len(rowNumSet)-1][danceLink.Headers[rNode.ColNum]] = true
			rNode = rNode.Right
		}
		cNode = cNode.Down
	}
	return markedNodesSet, rowNumSet, rowNumLinkHeadersSet
}

// 直接删除元素
func (danceLink *DanceLink) removeNodes(allNodesSet map[*node]bool) {
	// 不修改node本身的标记，仅修改相邻节点的信息
	//1. 删除节点两个相对方向都是非删除节点，直接删除并重建链
	//2. 当删除节点的一方向为删除节点，另外相对方向为非删除节点时，非删除节点连接到顺次的第一个非删除节点
	//3. 当删除节点四边都是非删除节点时，不处理该节点（因为header节点不会被选中，因此必然存一个非删除节点）
	for node := range allNodesSet {
		danceLink.Headers[node.ColNum].arg-- //header计数更新

		_, isLeftExist := allNodesSet[node.Left]
		_, isRightExist := allNodesSet[node.Right]
		_, isUpExist := allNodesSet[node.Up]
		_, isDownExist := allNodesSet[node.Down]

		if isUpExist && !isDownExist { //pNode向上找到第一个不是删除节点的节点
			pNode := node.Up
			for _, exist := allNodesSet[pNode]; exist; _, exist = allNodesSet[pNode] {
				pNode = pNode.Up
			}
			node.Down.Up = pNode
			pNode.Down = node.Down
		}
		if !isUpExist && isDownExist { //pNode向下找到第一个不是删除节点的节点
			pNode := node.Down
			for _, exist := allNodesSet[pNode]; exist; _, exist = allNodesSet[pNode] {
				pNode = pNode.Down
			}
			node.Up.Down = pNode
			pNode.Up = node.Up
		}
		if isLeftExist && !isRightExist { //pNode向左找到第一个不是删除节点的节点
			pNode := node.Left
			for _, exist := allNodesSet[pNode]; exist; _, exist = allNodesSet[pNode] {
				pNode = pNode.Left
			}
			node.Right.Left = pNode
			pNode.Right = node.Right
		}
		if !isLeftExist && isRightExist { //pNode向右找到第一个不是删除节点的节点
			pNode := node.Right
			for _, exist := allNodesSet[pNode]; exist; _, exist = allNodesSet[pNode] {
				pNode = pNode.Right
			}
			node.Left.Right = pNode
			pNode.Left = node.Left
		}

		if !isUpExist && !isDownExist {
			node.Up.Down = node.Down
			node.Down.Up = node.Up
		}
		if !isLeftExist && !isRightExist {
			node.Left.Right = node.Right
			node.Right.Left = node.Left
		}
	}
}

// 直接恢复元素
func (danceLink *DanceLink) resumeNodes(allNodesSet map[*node]bool) {
	for node := range allNodesSet {
		//依照本身标记恢复
		node.Up.Down = node
		node.Down.Up = node
		node.Left.Right = node
		node.Right.Left = node

		//恢复header计数
		danceLink.Headers[node.ColNum].arg++
	}

}

// 删除元素,并返回备份
func (danceLink *DanceLink) removeNodesReturnBackup(allNodesSet map[*node]bool) []nodeDirectBackup {
	var nodesDirectBackup []nodeDirectBackup

	// 先备份数据
	for node := range allNodesSet {
		backup := nodeDirectBackup{}
		backup.RawNode = node
		backup.RawNodeUp = node.Up
		backup.RawNodeDown = node.Down
		backup.RawNodeLeft = node.Left
		backup.RawNodeRight = node.Right
		nodesDirectBackup = append(nodesDirectBackup, backup)

	}
	// 再从舞蹈链中移除
	for node := range allNodesSet {
		node.Up.Down = node.Down
		node.Down.Up = node.Up
		node.Left.Right = node.Right
		node.Right.Left = node.Left
		danceLink.Headers[node.ColNum].arg-- //header计数更新
	}
	return nodesDirectBackup
}

// 依靠备份恢复元素
func (danceLink *DanceLink) resumeNodesByBackup(nodesDirectBackup []nodeDirectBackup) {
	for _, backup := range nodesDirectBackup {
		//依照本身标记恢复
		backup.RawNodeUp.Down = backup.RawNode
		backup.RawNodeDown.Up = backup.RawNode
		backup.RawNodeLeft.Right = backup.RawNode
		backup.RawNodeRight.Left = backup.RawNode

		//恢复header计数
		danceLink.Headers[backup.RawNode.ColNum].arg++
	}

}

// 原始舞蹈链算法,solvedNum可指定需要的解个数，当=-1时，计算所有的解；当有限解个数<solvedNum时，仅返回有限解长度(无解时为0)
func BaseDanceLinkXSolver(data [][]int, solvedNum int) [][]int {
	danceLink := new(DanceLink)
	if solvedNum < -1 {
		panic("solvedNum必须大于等于-1，当=-1时，计算所有的解；当有限解个数<solvedNum时，仅返回有限解长度(无解时为0)")
	}
	danceLink.needSolvedNum = solvedNum // 设置解个数
	//根据列数创建

	dataRowLength := len(data)
	dataColLength := len(data[0])

	// 构建RowFirstNode
	for rowIdx := 0; rowIdx <= dataRowLength; rowIdx++ {
		danceLink.RowFirstNode = append(danceLink.RowFirstNode, nil)
	}

	head := new(node) //创建辅助节点
	danceLink.Headers = append(danceLink.Headers, head)
	danceLink.RowFirstNode[0] = head
	for colNum := 1; colNum <= dataColLength; colNum++ {
		hNode := new(node) //创建头部节点

		hNode.Up = hNode
		hNode.Down = hNode
		hNode.arg = 1 // 计数置1

		danceLink.Headers[colNum-1].Right = hNode // 左节点 -> this
		hNode.Left = danceLink.Headers[colNum-1]  // 左节点 <- this

		hNode.ColNum = colNum
		danceLink.Headers = append(danceLink.Headers, hNode)
	}
	//头部节点首尾相连
	danceLink.Headers[dataColLength].Right = head
	head.Left = danceLink.Headers[dataColLength]

	//	构建交叉十字循环双向链
	for dataRowNum, _rows := range data {
		for dataColNum, val := range _rows {
			if val != 0 {
				// 创建body节点
				bNode := new(node)
				bNode.RowNum = dataRowNum + 1
				bNode.ColNum = dataColNum + 1
				bNode.Left = bNode
				bNode.Right = bNode

				danceLink.Headers[bNode.ColNum].arg++
				// 创建四个方向的link
				preNode := danceLink.Headers[bNode.ColNum] //  创建临时指针node,从上之下查找
				// 纵向插入
				for {
					nextRowNum := preNode.Down.RowNum
					if nextRowNum == 0 { // 已经找到最后
						nextRowNum = dataRowLength + 1
					}
					if preNode.RowNum < bNode.RowNum && bNode.RowNum < nextRowNum { //找到插入位置
						// 在pNode后面插入bNode
						bNode.Up = preNode
						bNode.Down = preNode.Down
						bNode.Down.Up = bNode
						preNode.Down = bNode
						break
					}
					preNode = preNode.Down
				}

				//横向插入
				preNode = danceLink.RowFirstNode[bNode.RowNum]
				if preNode == nil {
					danceLink.RowFirstNode[bNode.RowNum] = bNode // 因为从左至右遍历，先遇到的为firstNode
				} else {
					for {
						nextColNum := preNode.Right.ColNum
						if nextColNum <= preNode.ColNum { // 已找到最后的位置
							nextColNum = dataColLength + 1
						}
						if preNode.ColNum < bNode.ColNum && bNode.ColNum < nextColNum {
							bNode.Left = preNode
							bNode.Right = preNode.Right
							bNode.Right.Left = bNode
							preNode.Right = bNode
							break
						}
						preNode = preNode.Right
					}
				}

				danceLink.Nodes = append(danceLink.Nodes, bNode)
			}
		}
	}

	// 递归求解
	dancing(danceLink)
	return danceLink.AllAns
}

// 总入口函数
func DanceLinkSolver(sudoku *Sudoku) bool {
	/*第一步  优先处理唯一单元格*/
	FillAllOnlyCells(sudoku)

	/*第二步 约束条件转换为精确覆盖模型*/
	var data [][]int
	//约束条件1：每个格子只能填一个数字
	//转换公式：(以0为起始)(第consCol列定义成：(row，col)填一个数字)
	// row = consCol / 9
	// col = consCol % 9
	// consCol  = row * 9 + col
	// 0 <= consCol < 81, 0 <= row < 9, 0 <= col < 9
	cons1CalcForward := func(row, col uint8) int {
		return int(row)*9 + int(col)
	}
	cons1CalcBack := func(consCol int) (uint8, uint8) {
		return uint8(consCol / 9), uint8(consCol % 9)
	}

	//约束条件2：每行1-9的这9个数字都得填一遍
	//转换公式：(以0为起始)(第consCol列定义成：在第row行填入数字val)
	// row = (consCol - 81) / 9
	// val = (consCol - 81) % 9 + 1
	// consCol  = row * 9  + val - 1 + 81
	// 81 <= consCol < 162, 0 <= row < 9, 1<= val <= 9
	cons2CalcForward := func(row, val uint8) int {
		return int(row)*9 + int(val) - 1 + 81
	}
	cons2CalcBack := func(consCol int) (uint8, uint8) {
		return uint8((consCol - 81) / 9), uint8((consCol-81)%9 + 1)
	}

	//约束条件3：每列1-9的这9个数字都得填一遍
	//转换公式：(以0为起始)(第consCol列定义成：在第col列填入数字val)
	// col = (consCol - 162) / 9
	// val = (consCol - 162) % 9 + 1
	// consCol  = col * 9  + val - 1 + 162
	// 162 <= consCol < 243, 0 <= col < 9, 1<= val <= 9

	cons3CalcForward := func(col, val uint8) int {
		return int(col)*9 + int(val) - 1 + 162
	}
	cons3CalcBack := func(consCol int) (uint8, uint8) {
		return uint8((consCol - 162) / 9), uint8((consCol-162)%9 + 1)
	}

	//约束条件4：每宫1-9的这9个数字都得填一遍
	//转换公式：(以0为起始)(第consCol列定义成：在第boxIdx宫填入数字val)
	// boxIdx = (consCol - 243) / 9
	// val = (consCol - 243) % 9 + 1
	// consCol  = boxIdx * 9  + val - 1 + 243
	// 243 <= consCol < 324, 0 <= boxIdx < 9, 1<= val <= 9

	cons4CalcForward := func(boxIdx, val uint8) int {
		return int(boxIdx)*9 + int(val) - 1 + 243
	}
	cons4CalcBack := func(consCol int) (uint8, uint8) {
		return uint8((consCol - 243) / 9), uint8((consCol-243)%9 + 1)
	}

	// 未使用约束3、约束4的反向计算
	_ = cons3CalcBack
	_ = cons4CalcBack

	var row, col uint8
	for row = 0; row < 9; row++ {
		for col = 0; col < 9; col++ {
			targetCell := sudoku.Rows[row].Cells[col]
			if targetCell.Val != 0 { //有数字的情况(一行约束)
				consRow := make([]int, 9*9*4)
				consRow[cons1CalcForward(row, col)] = 1                              //约束1
				consRow[cons2CalcForward(row, targetCell.Val)] = 1                   // 约束2
				consRow[cons3CalcForward(col, targetCell.Val)] = 1                   // 约束3
				consRow[cons4CalcForward(targetCell.Box.BoxIdx, targetCell.Val)] = 1 // 约束4
				data = append(data, consRow)
			}
		}
	}

	// 优化二 先把有数字的格子转换为行，插入到矩阵中，便于计算时优先选中
	for row = 0; row < 9; row++ {
		for col = 0; col < 9; col++ {
			targetCell := sudoku.Rows[row].Cells[col]
			if targetCell.Val == 0 { //没有数字的情况（一般情况九行约束）
				cellCountResult := getCellUsedCount(targetCell)
				for val := 1; val <= 9; val++ {
					// 优化二 仅插入规则合法行，以便减少迭代次数
					if cellCountResult[val] == 0 { // 该数字可用，未被其他cell占用
						consRow := make([]int, 9*9*4)
						consRow[cons1CalcForward(row, col)] = 1                          //约束1
						consRow[cons2CalcForward(row, uint8(val))] = 1                   // 约束2
						consRow[cons3CalcForward(col, uint8(val))] = 1                   // 约束3
						consRow[cons4CalcForward(targetCell.Box.BoxIdx, uint8(val))] = 1 // 约束4
						data = append(data, consRow)
					}
				}
			}
		}
	}

	//仅需一个解
	AllAns := BaseDanceLinkXSolver(data, 1)

	/*第三步 转换答案到数独*/
	if len(AllAns) > 0 && data != nil {
		for _, rowIdx := range AllAns[0] {
			rowData := data[rowIdx] // 必有四个数字为1，其余为0
			var row, col, val uint8
			timer := 0
			for colIdx, num := range rowData {
				if num == 1 {
					timer++
					switch timer {
					case 1:
						row, col = cons1CalcBack(colIdx) //条件1
					case 2:
						row, val = cons2CalcBack(colIdx) //条件2
					default:
						break
					}
				}
			}
			sudoku.Rows[row].Cells[col].Val = val
		}
		return true
	} else {
		return false
	}

}

// 舞蹈链递归函数
func dancing(danceLink *DanceLink) {
	/*
		1、dancing函数的入口
		2、判断Head.Right=Head？，若是，输出答案，返回True，退出函数。
		3、获得Head.Right的列首元素C
		4、标示列首元素C（标示元素C，指的是标示C、和C所在列的所有元素、以及该元素所在行的元素，并从双向链中移除这些元素）
		5、获得元素C所在列的一个body元素
		6、标示该body元素同行的其余body元素所在的列首元素
		7、获得一个简化的问题，递归调用dancing函数，若返回的True，则返回True，退出函数。
		8、若返回的是False，则回标该元素同行的其余元素所在的列首元素，回标的顺序和之前标示的顺序相反
		9、获得元素C所在列的下一个元素，若有，跳转到步骤6
		10、若没有，回标元素C，返回False，退出函数。
	*/
	//log.Print("入口合法性检查", checkDanceLinkLegal(danceLink))
	if danceLink.Headers[0].Right == danceLink.Headers[0] {
		//找到解,记录
		if danceLink.needSolvedNum > 0 {
			danceLink.needSolvedNum--
		}
		ans := make([]int, len(danceLink.AnsStack))
		copy(ans, danceLink.AnsStack)
		danceLink.AllAns = append(danceLink.AllAns, ans)
		return
	}

	hNode := danceLink.Headers[0].Right
	pNode := hNode
	for pNode != danceLink.Headers[0] {
		if hNode.arg > pNode.arg { // 优化一， 从最小可能列先查找
			hNode = pNode
		}
		pNode = pNode.Right
	}

	markedNodesSet, rowNumSet, rowNumLinkHeadersSet := danceLink.markOneHeaderNode(hNode)

	//log.Print("标识前删除前合法性检查", checkDanceLinkLegal(danceLink))
	for idx, rowNum := range rowNumSet {
		// 深copy markedNodesSet到allMarkedNodesSet
		allMarkedNodesSet := make(map[*node]bool)
		for node := range markedNodesSet {
			allMarkedNodesSet[node] = true
		}
		// 标示该同行的其余body元素所在的列首元素
		for header := range rowNumLinkHeadersSet[idx] {
			linkMarkedNodesSet, _, _ := danceLink.markOneHeaderNode(header)
			for node := range linkMarkedNodesSet {
				allMarkedNodesSet[node] = true
			}
		}
		//log.Print("标识后删除前合法性检查", checkDanceLinkLegal(danceLink))
		// 删除这一行关联的其他列首元素
		//danceLink.removeNodes(allMarkedNodesSet)  //method 1
		nodesBackup := danceLink.removeNodesReturnBackup(allMarkedNodesSet) //method 2

		//行号加入答案栈,此处应该-1，去掉header
		danceLink.AnsStack = append(danceLink.AnsStack, rowNum-1)

		//log.Print("删除后合法性检查", checkDanceLinkLegal(danceLink))
		// 递归
		dancing(danceLink)
		// 如果还有解需要找
		if danceLink.needSolvedNum > 0 || danceLink.needSolvedNum == -1 {
			// 回滚
			//danceLink.resumeNodes(allMarkedNodesSet) //method 1
			danceLink.resumeNodesByBackup(nodesBackup) //method 2

			danceLink.AnsStack = danceLink.AnsStack[0 : len(danceLink.AnsStack)-1]
			//log.Print("恢复后合法性检查", checkDanceLinkLegal(danceLink))
		} else {
			return
		}

	}
	//所有的情况均找完
	return

}

/* github.com/smilelc3/sudoku-solver/Sudoku/drop_algorithm.go */

//摒弃法 https://www.cnblogs.com/grenet/p/3138654.html

// 空白单元格 blankCell
// 唯一数单元格  onlyCell
// 无解单元格 noSolutionCell
// 无唯一数单元格 notOnlyCell

// 补全唯一单元格，便于其他算法复用
func FillAllOnlyCells(sudoku *Sudoku) {
	cell := findBlankCellFromIdx(sudoku, 0)
	if cell == nil { // 已补全所有
		return
	}
	var hasOnlyCell = false
	var availableNums []uint8
	var startIdx uint8 = 0
	for { //遍历所有空白单元格，找唯一单元格
		cell = findBlankCellFromIdx(sudoku, startIdx)
		if cell == nil {
			break // 找完所有cell
		}
		hasOnlyCell, availableNums = isOnlyCell(cell)
		if hasOnlyCell {
			// 找到唯一数
			break
		}
		startIdx = cell.Idx + 1
	}
	if hasOnlyCell && len(availableNums) > 0 && cell != nil { // 找到唯一单元格，填数
		cell.Val = availableNums[0]
		FillAllOnlyCells(sudoku)
	} else {
		return
	}

}

// 判断cell是否是唯一单元格
func isOnlyCell(cell *Cell) (bool, []uint8) {
	cellCountResult := getCellUsedCount(cell)
	notFillCount := 0
	var availableNums []uint8
	for idx, val := range cellCountResult[1:] {
		if val == 0 {
			notFillCount++
			availableNums = append(availableNums, uint8(idx+1))
		}
	}
	return notFillCount == 1, availableNums
}

// 从 startIdx位置开始寻找第一个空白单元格
func findBlankCellFromIdx(sudoku *Sudoku, startIdx uint8) *Cell {
	if startIdx >= 81 {
		return nil
	}
	for _, cell := range sudoku.Cells[startIdx:] {
		if cell.Val == 0 { // 找到空白单元格
			return cell
		}
	}
	return nil
}

// 获取给定单元格所关联的其他单元格，所占用数字的信息(不重复)  便于其他算法复用
func getCellUsedCount(cell *Cell) [10]uint8 {
	result := [10]uint8{}
	//标记已用数
	nearCells := cell.GetCellAffectedCellsSet()
	for nearCell := range nearCells {
		if nearCell.Val != 0 {
			result[nearCell.Val]++
		}
	}
	return result
}
