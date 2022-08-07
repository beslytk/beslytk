
# A char may be decoded alone or by pairing with the next char.

class Solution:
    def numDecodings_mem(self, s: str) -> int:
        # Memoization
        dp = {len(s): 1} # base case

        def dfs(i):
            # if already cached or i is the last position in the string
            if i in dp:
                return dp[i]

            # string starting with 0 is invalid
            if s[i] == "0":
                return 0
            # if ith char is valid, res = subproblem(dfs of substring starting from i+1)
            res = dfs(i + 1) 
            if i + 1 < len(s) and (
                s[i] == "1" or s[i] == "2" and s[i + 1] in "0123456"):
                #if doubleDigit(ith char, i+1th char) is valid, add to res, subproblem(dfs of substring starting from i+2)
                res += dfs(i + 2) 
            dp[i] = res
            return res

        return dfs(0)

    def numDecodings_dp(self, s: str) -> int:
        # Dynamic Programming
        dp = {len(s): 1}
        for i in range(len(s) - 1, -1, -1):
            if s[i] == "0":
                dp[i] = 0
            else:
                dp[i] = dp[i + 1]

            if i + 1 < len(s) and (
                s[i] == "1" or s[i] == "2" and s[i + 1] in "0123456"):
                dp[i] += dp[i + 2]
        return dp[0]