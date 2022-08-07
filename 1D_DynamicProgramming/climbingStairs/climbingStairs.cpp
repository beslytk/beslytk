#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Climbing stairs, either 1 or 2 steps, distinct ways to reach top
    Ex. n = 2 -> 2 (1 + 1, 2), n = 3 -> 3 (1 + 1 + 1, 1 + 2, 2 + 1)

    Recursion w/ memoization -> DP, why DP? Optimal substructure
    Recurrence relation: dp[i] = dp[i - 1] + dp[i - 2]
    
    **Reach ith step in 2 ways: 1) 1 step from i-1, 2) 2 steps from i-2

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        int first = 1;  // only one way
        int second = 2; // two ways 1->1 or directly 2
        
        int result = 0;
        // For each step i, the number of ways to get to it is:
        // either the last step was of 1 step, jump from second, 
        // or it was a 2 step, a jump from first,
        // so all together the number of ways to get to our current step is first + second
        // from n = 3 ==> calculate from last two steps
        for (int i = 3; i <= n; i++) {
            result = first + second;
            first = second;  // shift to 2nd
            second = result; // shift to current step
        }
        
        return result;
    }
}; 

int main(){
    
    int n = 4;
    Solution sol;
	cout << "Number of ways = " << sol.climbStairs(n);
    return 0;
}