package rotate_image

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
	// space O(1)
}

func rotateImg(matrix [][]int, degree int) {

}
