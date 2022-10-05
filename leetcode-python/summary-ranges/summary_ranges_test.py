import unittest
from summary_ranges import Solution


class summaryRangesTest(unittest.TestCase):
    def test_example1(self):
        nums = [0, 1, 2, 4, 5, 7]
        ans = Solution().summaryRanges(nums)
        correctAns = ["0->2", "4->5", "7"]
        self.assertEqual(ans, correctAns)

    def test_example2(self):
        nums = [0, 2, 3, 4, 6, 8, 9]
        ans = Solution().summaryRanges(nums)
        correctAns = ["0", "2->4", "6", "8->9"]
        self.assertEqual(ans, correctAns)


if __name__ == '__main__':
    unittest.main()
