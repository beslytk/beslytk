#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given a string & dictionary, return true if:
    Can segment string into 1 or more dictionary words

    DP, at each loop, substring, check if in dict, & store
        0---------------->i
        <--------j
        ~~~~W1~~~|````W2```
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
        // dp cell values indicate true if the substring (0, index) is a word found dictionary
        for (int i = 1; i <= n; i++) { // iterate forward along given string (1 more than substring end idx)
            for (int j = i - 1; j >= 0; j--) {  // substring start index position
                if (dp[j]) {                    // ! word ending at j should be found in words dict
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

// https://www.educative.io/m/string-segmentation
bool can_segment_string(string s, unordered_set <string> & dictonary) {
  for (int i = 1; i <= s.length(); ++i) {
    string first = s.substr(0, i);
    if (dictonary.find(first) != dictonary.end()) {
      string second = s.substr(i);
      if (second.empty() || dictonary.find(second) != dictonary.end() || can_segment_string(second, dictonary)) {
        return true;
      }
    }
  }
  return false;
}

int main(){
    
    return 0;
}