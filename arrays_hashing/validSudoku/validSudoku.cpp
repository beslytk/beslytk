/*
    Determine if a 9x9 Sudoku board is valid (no repeats)

    Hash set to store seen values, check rows, cols, blocks

    Time: O(n^2)
    Space: O(n^2)

    https://leetcode.com/problems/valid-sudoku/
*/
#include<bits/stdc++.h>
using namespace std;

int isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int rows[9][9]={0}; //rows[5][0] means whether number 1('0'+1) in row 5 has appeared.
	int cols[9][9]={0}; //cols[3][8] means whether number 9('8'+1) in col 3 has appeared.
	int blocks[3][3][9]={0};//blocks[0][2][5] means whether number '6' in block 0,2 (row 0~2,col 6~8) has appeared.
	for(int r=0;r<9;r++)    //traverse board r,c
		for(int c=0;c<9;c++)
			if(board[r][c]!='.'){   //skip all number '.'
				int number=board[r][c]-'1'; //calculate the number's index(board's number minus 1)
				if(rows[r][number]++) return 0; //if the number has already appeared once, return false.
				if(cols[c][number]++) return 0;
				if(blocks[r/3][c/3][number]++) return 0;
			}
	return 1;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        //check each row
        for (int i = 0; i < 9; i++) {        // travelling horizontally
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                auto it = s.find(board[i][j]);
                if (it != s.end()) {
                    return false;
                } else {
                    s.insert(board[i][j]);
                }
            }
            s.clear();  // clear, after reaching end of current row
        }
        //check each column
        for (int i = 0; i < 9; i++) {       // travelling vertically
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                auto it = s.find(board[j][i]);
                if (it != s.end()) {
                    return false;
                } else {
                    s.insert(board[j][i]);
                }
            }
            s.clear();
        }
        
        for (int iCount = 0; iCount < 9; iCount += 3) {
            for (int jCount = 0; jCount < 9; jCount += 3) {
                for (int i = iCount; i < iCount + 3; i++) {
                    for (int j = jCount; j < jCount + 3; j++) {
                        if (board[i][j] == '.') {
                            continue;
                        }
                        auto it = s.find(board[i][j]);
                        if (it != s.end()) {
                            return false;
                        } else {
                            s.insert(board[i][j]);
                        }
                    }
                }
                s.clear();
            }
        }
        
        return true;
    }
};