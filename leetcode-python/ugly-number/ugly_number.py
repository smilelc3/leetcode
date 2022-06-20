class Solution:
    def isUgly(self, n: int) -> bool:
        if n == 0:
            return False
        while n & 1 == 0:
            n >>= 1
        while n % 3 == 0:
            n //= 3
        while n % 5 == 0:
            n //= 5
        return n == 1
