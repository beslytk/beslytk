#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given cost array, ith step is cost[i], can climb 1 or 2 steps
    Return min cost to reach top floor, can start at index 0 or 1
    Ex. cost = [10,15,20] -> 15, start at idx 1, pay 15, climb 2
*/

// We start at either step 0 or step 1. The target is to 'reach either last or second last step', whichever is 'minimum'.

// Step 1 - ~~Identify a recurrence relation between subproblems~~.
// In this problem,
// Recurrence Relation:
// mincost(i) = cost[i]+min(mincost(i-1), mincost(i-2))
// Base cases:
// mincost(0) = cost[0]
// mincost(1) = cost[1]

// Step 2 - Covert the recurrence relation to recursion
// Recursive Top Down - O(2^n) Time Limit Exceeded
class Solution_TD_Rec{

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(minCost(cost, n-1), minCost(cost, n-2)); // min of last or second last step
    }
    int minCost(vector<int>& cost, int n) {
        if (n < 0) return 0;              // invalid case
        if (n==0 || n==1) return cost[n]; // base case - return value from array
        return cost[n] + min(minCost(cost, n-1), minCost(cost, n-2));
    }
};

// Step 3 - Optimization 1 - Top Down DP - Add memoization to recursion - From exponential to linear.
// Top Down Memoization - O(n) 1ms
class Solution_TD_Mem{
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n + 1];              // array for memoization
	    memset(dp, -1, sizeof dp);  // set to invalid value to identify if mincost computed
        return min(minCost(cost, n-1, dp), minCost(cost, n-2, dp)); // min of last or second last step
    }
    int minCost(vector<int>& cost, int n, int dp[]) {
        if (n < 0) return 0;              // invalid case
        if (n==0 || n==1) return cost[n]; // base case - return value from array
        if (dp[n] != -1) return dp[n];    // return memoized values if already computed
        dp[n] = cost[n] + min(minCost(cost, n-1, dp), minCost(cost, n-2, dp)); // memmoize
        return dp[n];
    }

};

// Step 4 - Optimization 2 -Bottom Up DP -> Convert 'recursion to iteration'- Getting rid of recursive stack
// Bottom up tabulation - O(n) 1ms
class Solution_BU_Tab{
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int* dp = new int[n];
        for (int i=0; i<n; i++) {
            if (i<2) dp[i] = cost[i]; // base case
            else dp[i] = cost[i] + min(dp[i-1], dp[i-2]); // mincost to reach ith step
        }
        return min(dp[n-1], dp[n-2]);
    }
};

// Step 5 - Optimization 3 - Fine Tuning - Reduce O(n) space to O(1).
// Bottom up computation - O(n) time, O(1) space
// Only need to memoize previous 2 step minCost
class Solution_BU_Opt{
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int downTwo = cost[0];
        int downOne = cost[1];
        if (n<=2) return min(downTwo, downOne);
        // take the best minCost along the way from beginning till destination
        for (int i=2; i<n; i++) {
            int curr = cost[i] + min(downTwo, downOne);
            downTwo = downOne;
            downOne = curr;
        }
        return min(downTwo, downOne);
    }
};
/*
    Given cost array, ith step is cost[i], can climb 1 or 2 steps
    Return min cost to reach top floor, can start at index 0 or 1
    Ex. cost = [10,15,20] -> 15, start at idx 1, pay 15, climb 2

    Recursion w/ memoization -> DP, min cost to reach 1/2 steps below curr step
    Recurrence relation: minCost[i] = min(minCost[i-1] + cost[i-1], minCost[i-2] + cost[i-2])

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int downOne = 0;
        int downTwo = 0;
        // remembering downOne and downTwo for memoization
        for (int i = 2; i <= cost.size(); i++) {
            int temp = downOne;
            downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
            downTwo = temp;
        }
        
        return downOne;
    }
}; 

int main(){
    
    return 0;
}