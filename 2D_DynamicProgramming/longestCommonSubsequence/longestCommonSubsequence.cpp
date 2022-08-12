#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
// https://leetcode.com/problems/longest-common-subsequence
/*
    Given 2 strings, return length of longest common subsequence
    Ex. text1 = "abcde", text2 = "ace" -> 3, "ace" is LCS

            <- j    
             a   c   e  ""
        __________________    
    ^   a |  3           0
    |   b |      2       0 --> visualization of below, build DP bottom-up
    i   c |      2       0
        d |          1   0
        e |          1   0
        ""| 0    0   0   0
    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(); // rows of 2d grid
        int n = text2.size(); // cols of 2d grid
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // +1 for base case // all dp init to 0
        
        // compute values for each row backwards
        for (int i = m - 1; i >= 0; i--) {     
            for (int j = n - 1; j >= 0; j--) { // compute values for each cell in a row, then move up to proces next row
                if (text1[i] == text2[j]) {           // move diagonally up (to process next char in each string)
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);  // fill with max of curr cells right and bottom values
                }
            }
        }
        
        return dp[0][0];  // first cell should have count for LCommSeq for both words
    }
};

int longestCommonSubsequence(string &a, string &b) {
    short m[1001][1001] = {};
    for (auto i = 0; i < a.size(); ++i)
        for (auto j = 0; j < b.size(); ++j)
            m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
    return m[a.size()][b.size()];
}

// Memory-Optimized Solution
// You may notice that we are only looking one row up in the solution. So, we just need to store two rows.
int longestCommonSubsequence(string &a, string &b) {
    short m[2][1000] = {};
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            m[!(i % 2)][j + 1] = a[i] == b[j] ? (m[i % 2][j] + 1) : max(m[i % 2][j + 1], m[!(i % 2)][j]);
    return m[a.size() % 2][b.size()];
}
// Complexity Analysis

// Time: O(nm), where n and m are the string sizes.
// Memory: O(min(n,m)), assuming that we will use a smaller string for the column dimension.

int main(){
    
    return 0;
}