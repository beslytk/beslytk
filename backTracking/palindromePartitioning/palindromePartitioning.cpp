#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given a string, partition such that every substring is a palindrome, return all possible ones
    Ex. s = "aab" -> [["a","a","b"],["aa","b"]], s = "a" -> [["a"]]

    Generate all possible substrings at idx, if palindrome potential candidate, backtrack after

    Time: O(n x 2^n)
    Space: O(n)
*/

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<string> curr;
        vector<vector<string>> result;
        dfs(s, 0, curr, result);
        return result;
    }
private:
    void dfs(string s, int start, vector<string>& curr, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(curr);
            return;
        }
        // search for palindromic substr starting from index 'start'
        for (int i = start; i < s.size(); i++) {
            // only go for next partitions (dfs (i+1)) tree if current substring is palindrome
            // else loop will iterate and terminate without reaching base case
            if (isPalindrome(s, start, i)) {
                // start,i      st i    st  i  <- start = 0
                // |             | |    |   |
                // a a b         a a b  a a b
                // a             aa      aab
                string str = s.substr(start, i - start + 1); // a, aa,aab
                curr.push_back(str); // save current palindromic substring
                // next partition, after current substring
                dfs(s, i + 1, curr, result);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
}; 

int main(){
    
    return 0;
}