#include <bits/stdc++.h>
using namespace std;

/*
    Dijkstra's Algorithm - Leetcode 778 
    Given an integer elevation matrix, rain falls, at time t, depth everywhere is t
    Can swim iff elevation at most t, return least time get from top left to bottom right

    Shortest path w/ min heap: at every step, find lowest water level to move forward

    Time: O(n^2 log n)
    Space: O(n^2)
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) {
            return 0;
        }
        // nxn grid for visited check
        vector<vector<bool>> visited(n, vector<bool>(n));
        visited[0][0] = true;
        
        int result = max(grid[0][0], grid[n - 1][n - 1]);
        // min sort based on 1st item in vector i.e max height along way
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({result, 0, 0});
        
        while (!pq.empty()) {
            // always process the min object
            vector<int> curr = pq.top();
            pq.pop();
            
            result = max(result, curr[0]);
            
            for (int i = 0; i < 4; i++) {
                int x = curr[1] + dirs[i][0];
                int y = curr[2] + dirs[i][1];
                // if out-of-bounds or visited cell -> skip
                if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) {
                    continue;
                }
                // if reached bottom-right
                if (x == n - 1 && y == n - 1) {
                    return result;
                }

                pq.push({grid[x][y], x, y});
                visited[x][y] = true;
            }
        }
        
        return -1;
    }
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
 
int main(){
    vector<vector<int>> grid = {{0,1,3},
                                {2,4,1},
                                {1,2,1}
                               };
    Solution sol;
    cout<<"least time get from top left to bottom right is: "<<sol.swimInWater(grid)<<endl;               

    vector<vector<int>> grid2 = {{0,1,2,3,4},
                                {24,23,22,21,5},
                                {12,13,14,15,16},
                                {11,17,18,19,20},
                                {10,9,8,7,6}};             
    cout<<"grid2: least time get from top left to bottom right is: "<<sol.swimInWater(grid2)<<endl;               

    return 0;
}