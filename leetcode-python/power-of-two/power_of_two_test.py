import unittest
from power_of_two import Solution


class isPowerOfTwoTest(unittest.TestCase):
    def test_example1(self):
        self.assertTrue(Solution().isPowerOfTwo(1))

    def test_example2(self):
        self.assertTrue(Solution().isPowerOfTwo(16))

    def test_example3(self):
        self.assertFalse(Solution().isPowerOfTwo(3))

    def test_test0(self):
        self.assertFalse(Solution().isPowerOfTwo(0))


if __name__ == '__main__':
    unittest.main()
