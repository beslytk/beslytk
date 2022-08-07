from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        rob1, rob2 = 0, 0
        # [rob1, rob2, n, n+1, ...]
        for n in nums:
            # max b/w including nth house and max-till-rob1 (or)
            # discard nth house and consider max till rob2
            # since adjacent houses cant be robbed
            temp = max(n + rob1, rob2) # max we can rob up until n
            rob1 = rob2
            rob2 = temp
        return rob2