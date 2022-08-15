
# Bottom-Up DP
#               t                           x<----- R  
#          a   b   i  ""                      \
#     __________________                       \  BR Diag
#     a |  X         | 1
#       |            |   --> visualization of below, build DP bottom-up
# s   b |            | 1
#       |            |  
#     b |            | 1    if same, take from bottom diag cell.
#       |            |               Also consider possibility of ignoring current s[i] and try complete traversal(distinct subseq),
#     i |          2 | 1                Maybe s[i+1] can also match t[j]
#       |------------|               
#     ""| 0    0   0 | 1    if diff, ignore current s[i] and try to complete traversal(distinct subseq)
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        cache = {}
        # base cases:
        # if both s="" & t=""       -> distinctSubseq =1 
        # if both s=nonEmpty & t="" -> distinctSubseq =1 => means went through every char in t and matched them
        # if both s="" & t=nonEmpty -> distinctSubseq =0
        for i in range(len(s) + 1):
            cache[(i, len(t))] = 1
        for j in range(len(t)):
            cache[(len(s), j)] = 0

        for i in range(len(s) - 1, -1, -1):
            for j in range(len(t) - 1, -1, -1):
                if s[i] == t[j]:
                    cache[(i, j)] = cache[(i + 1, j + 1)] + cache[(i + 1, j)]
                else:
                    cache[(i, j)] = cache[(i + 1, j)]
        return cache[(0, 0)]