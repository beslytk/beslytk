#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
/**
 * @brief https://leetcode.com/problems/generate-parentheses/
 *  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
    Example 1:
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]

    Strategy:  Backtracking, keep valid, favor trying opens, then try closes if still valid
*/
class Solution{

public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        backTrack(n, 0, 0, "", result);
        return result;
    }
private:
    void backTrack(int n, int openCount, int closeCount, string currStr, vector<string>& result) { 
        if((openCount == n) && (closeCount == n)){
            result.push_back(currStr);
            return;
        }

        if(openCount < n){

            backTrack(n, openCount +1, closeCount, currStr+"(", result);
        }
        if(closeCount < openCount){ //!imp to make sure, close bracket is only used if open braces are there

            backTrack(n, openCount, closeCount + 1, currStr+")", result);
        }

    }
};

int main(){
    Solution sol;
    
    vector<string> res = sol.generateParenthesis(3);
    for (auto &&s : res)
    {
        cout<<s<<", ";
    }
    
    return 0;
}