#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given 3 strings, find if s3 is formed by interleaving of s1 & s2
    Ex. s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac" -> true

    DFS + memo, cache on s1 & s2 indices i & j
    2 choices: either take s1 & iterate i, or take s2 & iterate j

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        return dfs(s1, s2, s3, 0, 0);
    }
private:
    map<pair<int, int>, bool> dp;
    
    bool dfs(string s1, string s2, string s3, int i, int j) {
        if (i == s1.size() && j == s2.size()) {  // base case
            return true;
        }
        if (dp.find({i, j}) != dp.end()) {  // if cached already
            return dp[{i, j}];
        }
        //  recurrence relation -> both i,j could match s3[i+j] or either i or j could be mtach
        if (i < s1.size() && s1[i] == s3[i + j] && dfs(s1, s2, s3, i + 1, j)) { // char till ith idx of s1 are matched in s3, now process i+1->
            return true;
        }
        if (j < s2.size() && s2[j] == s3[i + j] && dfs(s1, s2, s3, i, j + 1)) {// char till jth idx of s2 are matched in s3, now process j+1->
            return true;
        }
        
        dp[{i, j}] = false; // if i or J didnt match s3[i+j] => set false for this combo
        return dp[{i, j}];
    }
}; 

int main(){
    
    return 0;
}