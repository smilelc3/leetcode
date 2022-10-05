import unittest
from typing import List
from range_sum_query_2d_immutable import NumMatrix


class isPowerOfTwoTest(unittest.TestCase):
    def test_example1(self):
        matrix: List[List[int]] = [[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]
        obj = NumMatrix(matrix)
        row1, col1, row2, col2 = 2, 1, 4, 3
        self.assertEqual(8, obj.sumRegion(row1, col1, row2, col2))
        row1, col1, row2, col2 = 1, 1, 2, 2
        self.assertEqual(11, obj.sumRegion(row1, col1, row2, col2))
        row1, col1, row2, col2 = 1, 2, 2, 4
        self.assertEqual(12, obj.sumRegion(row1, col1, row2, col2))

    def test_test0(self):
        matrix: List[List[int]] = [[-4, -5]]
        obj = NumMatrix(matrix)
        row1, col1, row2, col2 = 0, 0, 0, 0
        self.assertEqual(-4, obj.sumRegion(row1, col1, row2, col2))
        row1, col1, row2, col2 = 0, 0, 0, 1
        self.assertEqual(-9, obj.sumRegion(row1, col1, row2, col2))
        row1, col1, row2, col2 = 0, 1, 0, 1
        self.assertEqual(-5, obj.sumRegion(row1, col1, row2, col2))


if __name__ == '__main__':
    unittest.main()
