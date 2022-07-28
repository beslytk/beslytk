from collections import deque
from typing import List
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0   
        count = 0
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] =='1' and visited[i][j]== False:
                    count += 1
                    self.bfs(grid,visited,i,j)
        return count       
    def bfs(self,grid,visited,i,j):
        qu = deque([(i,j)])
        while qu:
            i, j = qu.popleft() # use deque.pop to convert this to dfs algo
            if 0<=i<len(grid) and 0<=j<len(grid[0]) and grid[i][j]=='1' and visited[i][j]==False:
                visited[i][j] = True
                qu.extend([(i-1,j),(i+1,j),(i,j-1),(i,j+1)]) # all 4 directions