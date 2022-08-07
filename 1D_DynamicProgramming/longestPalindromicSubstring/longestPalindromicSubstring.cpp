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

int main(){
    
    return 0;
}