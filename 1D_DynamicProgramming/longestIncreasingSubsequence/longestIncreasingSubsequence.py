from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        LIS = [1] * len(nums)

        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[i] < nums[j]:
                    # longest inreasing subseq 'starting' @ index i
                    LIS[i] = max(LIS[i], 1 + LIS[j]) # take the best among all subseq start from later indices and including current el
        return max(LIS)