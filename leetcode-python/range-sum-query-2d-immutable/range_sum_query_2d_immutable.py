from typing import List


class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        self.row = len(matrix)
        self.col = len(matrix[0])
        self.matrixSum = [[0] * (self.col + 1) for _ in range(self.row + 1)]
        self.__init_matrix_sum(matrix)

    def __init_matrix_sum(self, matrix: List[List[int]]):
        for i in range(0, self.row):
            for j in range(0, self.col):
                self.matrixSum[i + 1][j + 1] = self.matrixSum[i][j + 1] + self.matrixSum[i + 1][j] - \
                                               self.matrixSum[i][j] + matrix[i][j]
        return

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.matrixSum[row2 + 1][col2 + 1] - self.matrixSum[row2 + 1][col1] - self.matrixSum[row1][col2 + 1] + \
               self.matrixSum[row1][col1]
