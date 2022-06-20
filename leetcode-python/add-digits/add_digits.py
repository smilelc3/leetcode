class Solution:
    def addDigits(self, num: int) -> int:
        # 因为 n = a_0 * 10^1 + a_1 * 10^2 + ... + a_k * 10^k
        # 又因为 (a * 10^k) % 9 = (a * (9 * 111...111  + 1)) % 9 = a
        # 所以 (a_0 + a_1 + ... a_n) % 9 = n % 9
        if num == 0:
            return 0
        return (num - 1) % 9 + 1
