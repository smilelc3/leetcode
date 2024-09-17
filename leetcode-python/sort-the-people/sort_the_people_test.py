import unittest
from sort_the_people import Solution


class sortPeopleTest(unittest.TestCase):
    def test_example1(self):
        names = ["Mary", "John", "Emma"]
        heights = [180, 165, 170]
        self.assertEqual(Solution().sortPeople(names, heights), ["Mary","Emma","John"])

    def test_example2(self):
        names = ["Alice", "Bob", "Bob"]
        heights = [155, 185, 150]
        self.assertEqual(Solution().sortPeople(names, heights), ["Bob","Alice","Bob"])

if __name__ == '__main__':
    unittest.main()
