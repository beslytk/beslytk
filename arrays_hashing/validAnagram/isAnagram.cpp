#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given 2 strings, return true if anagrams (same letters diff order)
    Ex. s = "anagram" & t = "nagaram" -> true, s = "rat" & t = "car" -> false

    Count chars, strings should have same # of chars if anagram

    Time: O(n)
    Space: O(26)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        vector<int> count(26);
        // keep count of occurences of characters in string
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        // subtract from above count array each character
        // occurences and return early if result in negative
        for (int j = 0; j < t.size(); j++) {
            count[t[j] - 'a']--;
            if (count[t[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
}; 

int main(){

    Solution sol;
    string s1 ="anagram";
    string s2 = "nagaram";
    bool ret = sol.isAnagram(s1, s2);
    
    return 0;
}