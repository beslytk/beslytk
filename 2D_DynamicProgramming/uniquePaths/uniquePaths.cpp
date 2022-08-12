#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given grid, return # of unique paths from top-left to bottom-right
    Ex. m = 3, n = 2 -> 3 unique paths (R->D->D, D->D->R, D->R->D)

    DP: border cells have 1 unique path, 
    inner cells unique ways depend on where it comes from (up/left)
    movement : down/right
    Recurrence relation: grid[i][j] = grid[i-1][j] + grid[i][j-1]

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // 1st column cells have only one way to reach there from start i.e. move down 
        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;
        }
        // 1st row cells have only one way to reach there from start i.e. move right 
        for (int j = 0; j < n; j++) {
            grid[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        
        return grid[m - 1][n - 1];
    }
}; 

int main(){
    
    return 0;
}