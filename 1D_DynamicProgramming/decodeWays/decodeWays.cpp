#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given a string w/ only digits, return # ways to decode it (letter -> digit)
    Ex. s = "12" -> 2 (AB 1, 2 or L 12), s = "226" -> 3 (2 26 or 22 6 or 2 2 6)

    DP: At each digit, check validity of ones & tens, if valid add to # ways
    Recurrence relation: dp[i] += dp[i-1] (if valid) + dp[i-2] (if valid)

    Time: O(n)
    Space: O(n)
*/
// A char may be decoded alone or by pairing with the next char.
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int n = s.size();
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        // dp[i] will store -> numWays for sub-string till i (excluded)
        for (int i = 2; i <= n; i++) {
            int ones = stoi(s.substr(i - 1, 1));
            if (ones >= 1 && ones <= 9) {
                dp[i] += dp[i - 1]; // subproblem for sub-string till i-1
            }
            int tens = stoi(s.substr(i - 2, 2));
            if (tens >= 10 && tens <= 26) {
                dp[i] += dp[i - 2]; // subproblem for sub-string till i-2
            }
        }
        
        return dp[n];
    }
}; 

int main(){
    
    return 0;
}