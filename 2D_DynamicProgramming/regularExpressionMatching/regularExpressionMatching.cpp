#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given string & pattern, implement RegEx matching
    '.' -> matches any single character
    '*' -> matches zero or more of the preceding element
    Matching should cover the entire input string (not partial)
    Ex. s = "aa", p = "a" -> false, "a" doesn't match entire string "aa"

    DFS + memo, 2 choices at a *: either use it, or don't use it

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0);
    }
private:
    map<pair<int, int>, bool> dp; // (i,j) => bool -> will it result in a match
    
    bool dfs(string& s, string& p, int i, int j) {
        if (dp.find({i, j}) != dp.end()) {
            return dp[{i, j}];
        }
        
        if (i >= s.size() && j >= p.size()) { // if reached end of both string
            return true;
        }
        if (j >= p.size()) {    // if reached end of pattern before given string end
            return false;
        }
        
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.'); // if chars at curr positions match or '.' @ pattern pos
        if (j + 1 < p.size() && p[j + 1] == '*') {                  // if there is '*' next to curr pattern pos
            // choices: either (1) don't use *,
            //              or (2) use *
            dp[{i, j}] = dfs(s, p, i, j + 2) ||
                         (match && dfs(s, p, i + 1, j)); // incr 'i' if matched // stay at curr 'j' ->may have to use curr patter char multiple times
            return dp[{i, j}]; // result of going down both paths
        }
        
        if (match) { // in normal case, incr both i and j if matched
            dp[{i, j}] = dfs(s, p, i + 1, j + 1);
            return dp[{i, j}];
        }
        
        dp[{i, j}] = false; // if not matching chars and next char in pattern not '*'
        return dp[{i, j}];
    }
}; 

int main(){
    
    return 0;
}