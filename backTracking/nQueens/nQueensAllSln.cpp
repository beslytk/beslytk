#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    N-Queens: place n queens such that no 2 queens atk each other, return all soln's

    Place queens per row, try all possibilities & validate for further rows, backtrack

    Time: O(n!)
    Space: O(n^2)
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        dfs(n, 0, board, result);
        return result;
    }
private:
    void dfs(int n, int row, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isValid(n, row, col, board)) {
                board[row][col] = 'Q';
                dfs(n, row + 1, board, result);
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(int n, int row, int col, vector<string>& board) {
        // check if any Q in same column for all rows until current row
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // check if any Q in same negative diagonal for all rows until current row
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // check if any Q in same positive diagonal for all rows until current row
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
}; 

int main(){
    
    return 0;
}