from typing import List
# Dynamic Programming Unbounded Knapsack - Leetcode 518
#         5   4   3   2   1   0      <-amount
#     __________________________
# c 1  |  4   3   2   2   1    1
# o    |------------------------                       1
# i 2  |  1   1   0   1   0    1
# n    |------------------------
# s 5  |  1   0   0   0   0    1
# |
# v
# Any cell value-> indicates whats the numOfWays to create amount(col) when you have coins (row, row +1.. etc)
# 
class Solution:
    def change_rec(self, amount: int, coins: List[int]) -> int:
        # MEMOIZATION
        # Time: O(n*m)
        # Memory: O(n*m)
        cache = {}  # <coin_index, amount> => # of combos that make up this amount

        def dfs(i, a):
            if a == amount:
                return 1
            if a > amount:
                return 0
            if i == len(coins):
                return 0
            if (i, a) in cache:
                return cache[(i, a)]
            # walk down the rec tree
            cache[(i, a)] = dfs(i, a + coins[i]) + dfs(i + 1, a) # choose curr coin + ignore curr coin
            return cache[(i, a)]

        return dfs(0, 0)

        # DYNAMIC PROGRAMMING
        # Time: O(n*m)
        # Memory: O(n*m) => 2d grid of  amount X coins
        # filling grid amount X coins each col at a time
        # dp[a][i] => number of ways of getting amount 'a' with coins from ith index to n-1 index
    def change_DP(self, amount: int, coins: List[int]) -> int:    
        dp = [[0] * (len(coins) + 1) for i in range(amount + 1)] # <= 2D  grid amount X coins 
        dp[0] = [1] * (len(coins) + 1) # amount 0 can be obtained by 1 way for each coin i.e by not selecting it
        for a in range(1, amount + 1): # building dp from small amt to given amount
            for i in range(len(coins) - 1, -1, -1):
                dp[a][i] = dp[a][i + 1] # not selecting coin 'i'
                if a - coins[i] >= 0:
                    dp[a][i] += dp[a - coins[i]][i]  # selecting coin 'i' if it fits within current amount 'a'
        return dp[amount][0] # no. of ways of obtaining 'amount' with all given coins

        # DYNAMIC PROGRAMMING
        # Time: O(n*m)
        # Memory: O(n) where n = amount
        #  dp     [ 5   4   3   2   1   0 ]     <-amount
        #                            1
        # nextDP  [ 5   4   3   2   1   0 ]     <-amount
        #                            1
    def change_DP_opt(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for i in range(len(coins) - 1, -1, -1): # looping over coins first
            nextDP = [0] * (amount + 1)
            nextDP[0] = 1

            for a in range(1, amount + 1):
                nextDP[a] = dp[a] # equivalent to 'ignoring current coin' when you have current and all prev processed coins
                if a - coins[i] >= 0:
                    nextDP[a] += nextDP[a - coins[i]] # taking current coin
            dp = nextDP
        return dp[amount]