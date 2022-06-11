import unittest
from power_of_three import *


class MyTestCase(unittest.TestCase):
    def test_example1(self):
        self.assertTrue(Solution().isPowerOfThree(27))

    def test_example2(self):
        self.assertFalse(Solution().isPowerOfThree(0))

    def test_example3(self):
        self.assertTrue(Solution().isPowerOfThree(9))


if __name__ == '__main__':
    unittest.main()
