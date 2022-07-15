/*
    https://leetcode.com/problems/word-search/

    Given a char board & a word, return true if word exists in the grid
    DFS traversal, set visited cells to '#', search in 4 directions, backtrack
    Time: O(n x 3^l) -> n = # of cells, l = length of word
    Space: O(l)
              Strategy :
                As the word in matrix can start at any position so we have to check for all
                positions whether each position can be a starting point!!
                
                Now the logic is simple for every call we have index variable which shows how
                much chars of word are already found in current dfs call 
                if at any point we found a mismatch between word[index] and baord[x][y] then that branch becomes invalid for us
                
                We use backtracking to make sure that each position/block of matrix 
                is visited once in a branch!!![important][visited check]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word,
        int index, int i, int j, int m, int n) {
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }
        
        board[i][j] = '#'; // marking it visited with non-alphabet

        // check if we can go all the way to end of string 
        if (dfs(board, word, index + 1, i - 1, j, m, n)       // up
            || dfs(board, word, index + 1, i + 1, j, m, n)    // down
            || dfs(board, word, index + 1, i, j - 1, m, n)    // left
            || dfs(board, word, index + 1, i, j + 1, m, n)) { // right
            return true;
        }
        // if the above path didnt succeed, backtrack to reverse
        // markings of visited positions
        board[i][j] = word[index]; // backtrack step
        return false;
    }
};

int main(){

    Solution s;

    vector<vector<char> > board {   {'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}};

    string word = "ABCCED";                                
    bool retVal = s.exist(board, word);
    cout<<"status of word search: "<<(retVal?"True":"False");
    return 0;
}