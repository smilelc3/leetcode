package rotate_image

import (
	"fmt"
	"math"
)

/*
   1. 先把原点（左上角）移动到中心点，并且Y轴翻转
                         ⌈  1     0    0 ⌉
   [X1 Y1 1] = [X0 Y0 1] |  0    -1    0 |
                         ⌊ -0.5W 0.5H  1 ⌋

   2. 图像旋转角度为θ
                         ⌈  cos(θ)  -sin(θ)   0 ⌉
   [X2 Y2 1] = [X1 Y1 1] |  sin(θ)   cos(θ)   0 |
                         ⌊  0         0        1 ⌋

   3. 旋转后的图像宽度为W'，高度为H',由中心原点变换到左上角
                         ⌈  1      0      0 ⌉
   [X3 Y3 1] = [X2 Y2 1] |  0     -1      0 |
                         ⌊  0.5W'  0.5H'  1 ⌋

   综上，(X0,Y0)旋转θ后，对应的(X3,Y3)转换公式为：
                         ⌈  1     0    0 ⌉ ⌈  cos(θ)  -sin(θ)   0 ⌉  ⌈  1      0      0 ⌉
   [X3 Y3 1] = [X0 Y0 1] |  0    -1    0 | |  sin(θ)   cos(θ)   0 | |  0     -1      0 |
                         ⌊ -0.5W 0.5H  1 ⌋ ⌊  0         0        1 ⌋  ⌊  0.5W'  0.5H'  1 ⌋

*/
func rotate(matrix [][]int) {
	if matrix == nil {
		return
	}

	// method 1: rotate  Any angle. space O(m*n)
	//rotateImg(matrix, 90)

	// method 2: rotate square Img 90 angle O(1)
	rotateSquareImg90(matrix)
}

func rotateSquareImg90(matrix [][]int) {
	degree := 90 / 360.0 * 2 * math.Pi
	if len(matrix)-1 != len(matrix[0])-1 {
		fmt.Println("非正方形矩阵")
		return
	}
	A := len(matrix) - 1
	newA := A
	// 3个转换矩阵
	M1 := [][]float64{
		{1, 0, 0},
		{0, -1, 0},
		{-0.5 * float64(A), 0.5 * float64(A), 1}}
	M2 := [][]float64{
		{math.Cos(degree), -math.Sin(degree), 0},
		{math.Sin(degree), math.Cos(degree), 0},
		{0, 0, 1}}
	M3 := [][]float64{
		{1, 0, 0},
		{0, -1, 0},
		{0.5 * float64(newA), 0.5 * float64(newA), 1}}
	transM := matrixMul(matrixMul(M1, M2), M3)

	// 提取右上1/4部分
	for X0 := int(math.Ceil(float64(A) / 2)); X0 <= A; X0++ {
		for Y0 := 0; Y0 <= int(math.Floor(float64(A-1)/2)); Y0++ {
			// 计算(X0,Y0) (X1,Y1) (X2,Y2) (X3,Y3)
			newCoord := matrixMul([][]float64{{float64(X0), float64(Y0), 1}}, transM)
			X1 := int(math.Round(newCoord[0][0]))
			Y1 := int(math.Round(newCoord[0][1]))

			newCoord = matrixMul([][]float64{{float64(X1), float64(Y1), 1}}, transM)
			X2 := int(math.Round(newCoord[0][0]))
			Y2 := int(math.Round(newCoord[0][1]))

			newCoord = matrixMul([][]float64{{float64(X2), float64(Y2), 1}}, transM)
			X3 := int(math.Round(newCoord[0][0]))
			Y3 := int(math.Round(newCoord[0][1]))

			matrix[Y0][X0], matrix[Y1][X1], matrix[Y2][X2], matrix[Y3][X3] = matrix[Y3][X3], matrix[Y0][X0], matrix[Y1][X1], matrix[Y2][X2]
		}
	}
}

func rotateImg(matrix [][]int, angle int) {
	// 旋转的角度[0,360)

	angle %= 360
	if angle < 0 {
		angle += 360
	}

	// 转换为[0,2Pi)
	degree := float64(angle) / 360 * 2 * math.Pi

	// 原始图片的尺寸
	H := len(matrix) - 1
	W := len(matrix[0]) - 1

	// 优先计算出旋转后的图片大小
	newH := int(math.Round(math.Abs(float64(H)*math.Cos(degree)) + math.Abs(float64(W)*math.Sin(degree))))
	newW := int(math.Round(math.Abs(float64(W)*math.Cos(degree)) + math.Abs(float64(H)*math.Sin(degree))))

	// 3个转换矩阵
	M1 := [][]float64{
		{1, 0, 0},
		{0, -1, 0},
		{-0.5 * float64(W), 0.5 * float64(H), 1}}

	M2 := [][]float64{
		{math.Cos(degree), -math.Sin(degree), 0},
		{math.Sin(degree), math.Cos(degree), 0},
		{0, 0, 1}}

	M3 := [][]float64{
		{1, 0, 0},
		{0, -1, 0},
		{0.5 * float64(newW), 0.5 * float64(newH), 1}}

	transM := matrixMul(matrixMul(M1, M2), M3)

	newMatrix := make([][]int, newH+1)
	for idx := 0; idx <= newH; idx++ {
		newMatrix[idx] = make([]int, newW+1)
	}

	for i := 0; i <= W; i++ {
		for j := 0; j <= H; j++ {
			newCoord := matrixMul([][]float64{{float64(i), float64(j), 1}}, transM)
			col := int(math.Round(newCoord[0][0]))
			row := int(math.Round(newCoord[0][1]))
			newMatrix[row][col] = matrix[j][i]
		}
	}

	for i := 0; i < len(matrix[0]); i++ {
		for j := 0; j < len(matrix); j++ {
			matrix[i][j] = newMatrix[i][j]
		}
	}
}

// 矩阵乘法
func matrixMul(a [][]float64, b [][]float64) [][]float64 {
	if a == nil || b == nil {
		fmt.Println("存在空矩阵")
		return [][]float64{}
	}
	aRow := len(a)
	aCol := len(a[0])
	bRow := len(b)
	bCol := len(b[0])
	if aCol != bRow {
		fmt.Println("两矩阵无法进行相乘运算")
		return [][]float64{}
	}

	var ans [][]float64
	for i := 0; i < aRow; i++ {
		var row []float64
		for j := 0; j < bCol; j++ {
			var val float64
			for k := 0; k < aCol; k++ {
				val += a[i][k] * b[k][j]
			}
			row = append(row, val)
		}
		ans = append(ans, row)
	}
	return ans
}
