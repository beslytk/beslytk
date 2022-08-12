from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {}  # (index, total) -> # of ways to get at target when starting @ 'index' and 'total' so far

        def backtrack(i, total):
            if i == len(nums):
                return 1 if total == target else 0  # if able to reach target with prev set of decisions ret 1 else 0
            if (i, total) in dp:
                return dp[(i, total)]
            # 2 decisions: add current num or subtract current num
            dp[(i, total)] = backtrack(i + 1, total + nums[i]) + backtrack(i + 1, total - nums[i])
            
            return dp[(i, total)]

        return backtrack(0, 0)