
# Thought process:
# Given two strings, we're tasked with finding the minimum number of transformations we need to make to arrive with equivalent strings.
#  From the get-go, there doesn't seem to be any way around trying all possibilities, and in this, possibilities refers to
#  inserting, deleting, or replacing a character. Recursion is usually a good choice for trying all possilbilities.

# Whenever we write recursive functions, we'll need some way to terminate, or else we'll end up overflowing the stack 
# via infinite recursion. With strings, the natural state to keep track of is the index. We'll need two indexes, one for word1 and 
# one for word2. Now we just need to handle our base cases, and recursive cases.
# What happens when we're done with either word? 
# Some thought will tell you that the minimum number of transformations is simply to insert the rest of the other word. 
# This is our base case.
# What about when we're not done with either string? We'll either match the currently indexed characters in both strings, or mismatch. 
# In the first case, we don't incur any penalty, and we can continue to compare the rest of the strings by recursing on the rest of both strings. 
# In the case of a mismatch, we either insert, delete, or replace. 
# To recap:
# base case: word1 = "" or word2 = "" => return length of other string
# recursive case: word1[0] == word2[0] => recurse on word1[1:] and word2[1:]
# recursive case: word1[0] != word2[0] => recurse by inserting, deleting, or replacing
# And in Python:

class Solution:
    def minDistance(self, word1, word2):
        """Naive recursive solution"""
        if not word1 and not word2:  # base case: empty strings
            return 0
        if not word1:
            return len(word2)
        if not word2:
            return len(word1)
        if word1[0] == word2[0]:
            return self.minDistance(word1[1:], word2[1:])
        insert  = 1 + self.minDistance(word1, word2[1:])
        delete  = 1 + self.minDistance(word1[1:], word2)
        replace = 1 + self.minDistance(word1[1:], word2[1:])
        return min(insert, replace, delete)

# With a solution in hand, we're ecstatic and we go to submit our code. All is well until we see the dreaded red text... 
# TIME LIMIT EXCEEDED. What did we do wrong? Let's look at a simple example, and for sake of brevity I'll annotate the minDistance function as md.

# word1 = "horse"
# word2 = "hello"

# The tree of recursive calls, 3 levels deep, looks like the following. I've highlighted recursive calls with multiple invocations. 
# So now we see that we're repeating work. I'm not going to try and analyze the runtime of this solution, but it's exponential.

# md("horse", "hello")
# 	md("orse", "ello")
# 		md("orse", "llo")     # insert
# 			md("orse", "lo")     
# 			md("rse", "llo") <- 
# 			md("rse", "lo")
# 		md("rse", "ello")     # delete
# 			md("rse", "llo") <-
# 			md("se", "ello")
# 			md("se", "llo") <<-
# 		md("rse", "llo")      # replace
# 			md("rse", "llo") <-
# 			md("se", "llo") <<-
# 			md("se", "lo")
# The way we fix this is by caching. We save intermediate computations in a dictionary and if we recur on the same subproblem, 
# instead of doing the same work again, we return the saved value. 
# Here is the memoized solution, where we build from bigger subproblems to smaller subproblems (top-down).

class Solution_TD:
    def minDistance(self, word1, word2, i, j, memo):
        """Memoized solution"""
        if i == len(word1) and j == len(word2):
            return 0
        if i == len(word1):
            return len(word2) - j
        if j == len(word2):
            return len(word1) - i

        if (i, j) not in memo:
            if word1[i] == word2[j]:
                ans = self.minDistance(word1, word2, i + 1, j + 1, memo)
            else: 
                insert  = 1 + self.minDistance(word1, word2, i, j + 1, memo)
                delete  = 1 + self.minDistance(word1, word2, i + 1, j, memo)
                replace = 1 + self.minDistance(word1, word2, i + 1, j + 1, memo)
                ans = min(insert, delete, replace)
            memo[(i, j)] = ans # memoization
        return memo[(i, j)]
sol = Solution_TD()
word1 = 'intention'
word2 = 'execution'
print(f'minDistance required for {word1} and {word2} is: ' + str(sol.minDistance( word1, word2, 0, 0, {}) ) )

# Of course, an interative implementation is usually better than its recursive counterpart because we don't risk blowing up our stack 
# in case the number of recursive calls is very deep. 
# We can also use a 2D array to do essentially the same thing as the dictionary of cached values. 
# When we do this, we build up solutions from smaller subproblems to bigger subproblems (bottom-up). 

# In this case, since we are no longer "recurring" in the traditional sense, we initialize our 2D table with base constraints. 
# The first row and column of the table has known values since if one string is empty, we simply add the length of the non-empty string
# since that is the minimum number of edits necessary to arrive at equivalent strings. 
# For both the memoized and dynamic programming solutions, the runtime is O(mn) and the space complexity is O(mn) 
# where m and n are the lengths of word1 and word2, respectively.
    #          s2     j ->    
    #          ""  a   c   d                             j->
    #     __________________                            \|
    #     ""|  0   1   2   3                       i  -->V
    #       |    |---------- 
    # s1  a |  1 | 0   1   2  
    #       |                    --> visualization of below, build DP bottom-up
    # i   b |  2 | 1   1   2   
    # |     |              
    # v   d |  3 | 2   2   X    if same, take from top-left diag cell
    #                 X = 1     if diff, take min(left, top, top-left diag) + 1
class Solution_BU:
    def minDistance(self, word1, word2):
        """Dynamic programming solution"""
        m = len(word1)
        n = len(word2)
        table = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m + 1): # base case when word2 is empty and for each subproblems in word1
            table[i][0] = i
        for j in range(n + 1): # base case when word1 is empty and for each subproblems in word2
            table[0][j] = j

        for i in range(1, m + 1):                # substr from word1 till index i
            for j in range(1, n + 1):            # substr from word2 till index j
                if word1[i - 1] == word2[j - 1]:
                    table[i][j] = table[i - 1][j - 1]
                else:
                    # on replace i & j can be moved by 1 place
                    # on insert, j can be moved right                                           j->    
                    # on deletion, i can be moved down to next index                           \|
                    # min(delete, insert, replace) + 1 <-- since an op was needed         i  -->V
                    table[i][j] = 1 + min(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1])
        return table[-1][-1]

    #         <- j                              ^<-----   
    #          a   c   d  ""                    | \
    #     __________________                    |  \  
    # ^   a |  X         | 3
    # |     |      2     |   --> visualization of below, build DP bottom-up
    # i   b |      2     | 2
    #       |          1 |  
    #     d |      1   0 | 1    if same, take from bottom diag cell
    #       |------------|
    #     ""| 3    2   1 | 0    if diff, take min(right, bottom, bottom-right diag) + 1
class Solution_BU2:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = [[float("inf")] * (len(word2) + 1) for i in range(len(word1) + 1)]

        for j in range(len(word2) + 1):
            dp[len(word1)][j] = len(word2) - j
        for i in range(len(word1) + 1):
            dp[i][len(word2)] = len(word1) - i

        for i in range(len(word1) - 1, -1, -1):     # substr from index i  till word1 end
            for j in range(len(word2) - 1, -1, -1): # substr from index j  till word2 end
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i + 1][j + 1]
                else:
                    dp[i][j] = 1 + min(dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1])
        return dp[0][0]