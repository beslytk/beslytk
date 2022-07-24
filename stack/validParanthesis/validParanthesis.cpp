#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given s w/ '(, ), {, }, [, ]', determine if valid
    Ex. s = "()[]{}" -> true, s = "(]" -> false
    Stack of opens, check for matching closes & validity
    Time: O(n)
    Space: O(n)
    https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        
        for (int i = 0; i < s.size(); i++) {
            // handle char's which are closing paranthesis
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (open.empty()) {
                    return false;
                }
                if (s[i] == ')' && open.top() != '(') {
                    return false;
                }
                if (s[i] == '}' && open.top() != '{') {
                    return false;
                }
                if (s[i] == ']' && open.top() != '[') {
                    return false;
                }
                open.pop();
            } else { 
                // push to stack all open paranthesis
                open.push(s[i]);
            }
        }
        
        if (!open.empty()) {
            return false;
        }
        return true;
    }
}; 

int main(){
    Solution sol;
    string s= "()[]{}";
    bool ret = sol.isValid(s);
    cout<< "given string is "<< (ret?"Valid":"not Valid");
    return 0;
}