import unittest
from ugly_number import Solution


class isUglyTest(unittest.TestCase):
    def test_example1(self):
        n = 6
        self.assertTrue(Solution().isUgly(n))

    def test_example2(self):
        n = 1
        self.assertTrue(Solution().isUgly(n))

    def test_example3(self):
        n = 14
        self.assertFalse(Solution().isUgly(n))

    def test_test0(self):
        n = 0
        self.assertFalse(Solution().isUgly(n))

    def test_test1(self):
        n = -2147483648
        self.assertFalse(Solution().isUgly(n))


if __name__ == '__main__':
    unittest.main()
