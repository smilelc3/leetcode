import unittest
from add_digits import *


class addDigitsCase(unittest.TestCase):
    def test_example1(self):
        num = 38
        ans = Solution().addDigits(num)
        correctAns = 2
        self.assertEqual(ans, correctAns)

    def test_example2(self):
        num = 0
        ans = Solution().addDigits(num)
        correctAns = 0
        self.assertEqual(ans, correctAns)


if __name__ == '__main__':
    unittest.main()
