

from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List [List[str]]:
        col = set()
        posDiag = set() # (r + c)
        negDiag = set() # (r - c)

        res = []

        board = [["."] * n for i in range (n)]

        def backTrack(r):
            if r == n:
                copy = ["".join(row) for row in board]
                res.append(copy)
                return
            # find which colum to place the queen based on current board setting
            for c in range(n):
                if c in col or (r + c) in posDiag or (r - c) in negDiag:
                    continue

                col.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c)
                board[r][c] = "Q"

                backTrack(r + 1)

                col.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)
                board[r][c] = "."

        backTrack(0)
        return res


sol = Solution()
board = sol.solveNQueens(4)
print(board)