class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n
        first, second = 2, 3

        for i in range(4, n + 1):
            temp = first + second
            first = second
            second = temp
        return second
sol = Solution()
print(sol.climbStairs(4))