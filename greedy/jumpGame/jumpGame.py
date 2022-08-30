from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1

        for i in range(len(nums) - 2, -1, -1): # start from idx nearest to goal and shift it to idx if reachable from there
            if i + nums[i] >= goal:
                goal = i                # shift goal to curr indec
        return goal == 0 # if goal can be brought to pos 0