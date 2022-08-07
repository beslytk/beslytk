#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

// https://leetcode.com/problems/longest-increasing-subsequence/
/*
    Given int array, return length of longest increasing subsequence
    Ex. nums = [10,9,2,5,3,7,101,18] -> 4, [2,3,7,101]

    Why DP? 
    1) Max/min of smth,
    2) make decisions based on prev decisions
    "Decision": is it worth it to consider this number?
    If use may contribute to better LIS, but may also eliminate an even better LIS

    Framework to solve DP:
    1) Need some function or array that represents ans to the problem (dp array)
    2) Way to transition b/w states (recurrence relation), depends on question
    3) Need a base case (initial solution for every subproblem)

    Recurrence relation: dp[i] = max(dp[i], dp[j] + 1)
    Base case: dp[i] = 1, since every element on its own has an LIS of 1

    Time: O(n^2)
    Space: O(n)
*/
// For each element nums[i], if there's an smaller element nums[j] before it, 
// the result will be maximum of current LIS length ending at i: dp[i],
//  and 'LIS ending at that j' + 1: dp[j] + 1. => +1 because we are including
//  the current element and extending the LIS ending at j.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // every element on its own has an LIS of '1'
        
        int result = 1;
        // for every i-th dp, consider all previous dp's
        for (int i = 1; i < n; i++) { 
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {            // satisfying criteria -> prev el < curr el
                    dp[i] = max(dp[i], dp[j] + 1); // 'dp[i] denotes the LIS ending at index i'
                }
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
}; 

int main(){
    
    return 0;
}