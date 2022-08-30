#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

 /*
    Given 2 strings s & t:
    Return # of distinct subsequences of s which equals t
    Ex. s = "rabbbit", t = "rabbit" -> 3, RABBbIT, RAbBBIT, RABbBIT

    DFS + memo, cache on i & j indices to the # of distinct subseq
    2 choices: if chars equal, look at remainder of both s & t
               if chars not equal, only look at remainder of s

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        return dfs(s, t, 0, 0);
    }
private:
    // {(i, j) -> # of distinct subsequences}
    map<pair<int, int>, int> dp;
    
    int dfs(string& s, string& t, int i, int j) {
        if (j == t.size()) {   // if reached end of string t => all char matched = > valid
            return 1;
        }
        if (i == s.size()) {   // if reached end of s w/o matching all t chars => invalid
            return 0;
        }
        if (dp.find({i, j}) != dp.end()) {
            return dp[{i, j}];
        }
        
        if (s[i] == t[j]) {
            dp[{i, j}] = dfs(s, t, i + 1, j + 1) + dfs(s, t, i + 1, j); // ith char of s taken + not taken
        } else {
            dp[{i, j}] = dfs(s, t, i + 1, j); // ith char of s not taken, Hence jth char of t is not yet matched
        }
        return dp[{i, j}];
    }
};

// For string S and T, we can use a matrix dp[m+1][n+1] to store all the intermediate results where m = T.size() and n = S.size(). 
//! The value of dp[i][j] is the number of distinct subsequences of substring S(0... j-1) which equals T(0...i-1). 
// So we need to update dp based on following conditions:

// (1) initialize all the numbers in dp as 0, and modify all the numbers in the first row as 1,
// 	in order to unify the following calculation formulas of dp[i][j]

// (2) if i > j, we just skip because i > j means that substring T(0...i-1) is longer than S(0...j-1)

// (3) if S[j-1] == T[i-1], then dp[i][j] = dp[i][j-1] + dp[i-1][j-1];  else , dp[i][j] = dp[i][j-1]
// 	Explanation:  dp[i][j-1] is the number of distinct subsequences of S(0...j-2) which equals T(0...i-1),
// 	and now if we know S[j-1] == T[i-1], then we need to add dp[i-1][j-1] ---- the number of distinct 
// 	subsequences of S(0...j-2) which equals T(0...i-2) 
// i.e.  S = "babgbag", T = "bag"   
// 	        0  b  a  b  g  b  a  g (S)
// 	        ______________________
// 	   0  | 1  1  1  1  1  1  1  1]
// (T) b  | 0  1  1  2  2  3  3  3]    <----- dp
// 	   a  | 0  0  1  1  1  1  4  4]
// 	   g  | 0  0  0  0  1  1  1  5]
	   
//    To update dp[2][6], we can know from dp[2][5] that "babgb" already has 1 distinct subsequence 
//    which equals "ba", so dp[2][6] at least equals to dp[2][5]
//    also, we know S[5] == T[1],  so we need to add dp[1][5] to dp[2][6],  because "babgb" has 3 distinct
//    subsequences which equals "b",  and we can conclude that "babgba" has another 3 distinct subsequences
//    which equals "ba"
// Here are the detailed codes, hope my explanation works.
class Solution_DP {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return 0;
        int m = t.size();
        int n= s.size();
        vector<vector<long>> dp (m, vector<long> (n+1, 0));
        dp.insert (dp.begin(), vector<long> (n+1, 1));  // to unify the calculation formula
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i > j) continue;
                if (t[i-1] == s[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
int main(){
    
    return 0;
}