#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given a string s & an int k, can change any char k times:
    Return length of longest substring containing same letter
    Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4
    Sliding window, expand if can change char, contract if > k
    Time: O(n)
    Space: O(26)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        // vector to keep track of each char freq in string given
        vector<int> count(26);
        int maxCount = 0;
        
        int l= 0;
        int r= 0;
        
        int result = 0;
        
        while (r < s.size()) {
            count[s[r] - 'A']++;
            //keep a maxCount variable to keep track of most freq char in window 
            maxCount = max(maxCount, count[s[r] - 'A']);
            // window length is (r - l + 1)
            // (r - l + 1 - maxCount) => number of replacements required for not-freq chars
            // k => replacements allowed
            if (r - l + 1 - maxCount > k) {
                count[s[l] - 'A']--;
                l++; //window shrinked from left side if enough character replacement not possible
                // maxCount need not be adjusted here as it cant affect the result
            }
            result = max(result, r - l + 1);
            r++;
        }
        
        return result;
    }
}; 

int main(){
    
    string s = "ABAB";
    Solution sol;
    int len = sol.characterReplacement(s, 2);
    cout<< "longest repeating substring after char replacement is of length:"<< len;
    return 0;
}