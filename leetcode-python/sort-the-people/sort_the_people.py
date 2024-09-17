from typing import List


class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        peoples: List[People] = []
        for idx, name in enumerate(names):
            peoples.append(People(name=name, height=heights[idx]))
        peoples.sort()

        return [iter.name for iter in peoples]

class People:
    def __init__(self, name, height):
        self.name = name
        self.height = height

    def __lt__(self, other):
        return self.height > other.height