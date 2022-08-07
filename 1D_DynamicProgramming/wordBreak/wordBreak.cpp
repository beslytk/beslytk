#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given a string & dictionary, return true if:
    Can segment string into 1 or more dictionary words

    DP, at each loop, substring, check if in dict, & store

    Time: O(n^3)
    Space: O(n)
*/
// https://leetcode.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;  // to use find() fn
        for (int i = 0; i < wordDict.size(); i++) {
            words.insert(wordDict[i]);
        }
        
        int n = s.size();
        vector<bool> dp(n + 1); // +1 to include base case
        dp[0] = true;           // base case
        
        for (int i = 1; i <= n; i++) { // iterate forward along given string (1 more than substring end idx)
            for (int j = i - 1; j >= 0; j--) {  // substring start index position
                if (dp[j]) {
                    string word = s.substr(j, i - j); // substring size (i-j)
                    if (words.find(word) != words.end()) {
                        dp[i] = true;  // dp for susbtring ending at ith idx is true if dp at jth idx also true
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
}; 

int main(){
    
    return 0;
}