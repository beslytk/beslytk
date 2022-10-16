#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given a string s, return the longest palindromic substring in s
    Ex. s = "babad" -> "bab", s = "cbbd" -> "bb"

    Expand around center, extend as far as possible, store max length

    Time: O(n^2)
    Space: O(1)
*/
// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int maxStart  = 0;
        int maxLength = 1;
        
        for (int i = 0; i < s.size() - 1; i++) {
            middleOut(s, i, i, maxStart, maxLength);      // odd length substring
            middleOut(s, i, i + 1, maxStart, maxLength);  // even length substring
        }
        
        return s.substr(maxStart, maxLength);
    }
private:
    void middleOut(string s, int i, int j, int& maxStart, int& maxLength) {
        while (i >= 0 && j <= s.size() - 1  // check if within bounds
                && s[i] == s[j]) {          // check if ith and jth char are equal
            // expand out
            i--;
            j++;
        }
        if (j - i - 1 > maxLength) {
            maxStart = i + 1;
            maxLength = j - i - 1;
        }
    }
}; 


// Solution 2: Using DP

// P(i, j) == P(i+1, j-1) && s[i] == s[j];
// Base cases :
// One character
// P(i, i) = true;
// Two character
// P(i, i+1) = s[i] == s[i+1];
// Time Complexity - O(N^2), Space Complexity - O(N^2) (caching all substring)
// dp[i][j] will be 'true' if the string from index i to j is a palindrome.
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];
        //Initialize with false
        memset(dp, 0, sizeof(dp));

        //Every Single character is palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // two consecutive same letters are palindrome
        for ( int i = 0 ; i <= s.length() - 2 ; i ++) {
            if ( s[i] == s[i + 1] ) {
                dp[i][i + 1] = true ;
            }
        }
        string ans = "";
        ans += s[0];
        for (int i = n - 1; i >= 0; i--){
            for (int j = i + 1; j < n; j++){ // substring starting at i and ending at j
                if (s[i] == s[j]){
                    //If it is of two character OR if its susbtring is palindrome.
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        //Then it will also a palindrome substring
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}