#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
/*
    Given int array, determine min jumps to reach last index
    Ex. nums = [2,3,1,1,4] -> 2, index 0 to 1 to last

    Greedy: At each point, determine furthest reachable, jump to it
    Move as in BFS. For each position find its farthest reachable position
    Iteratively, consider all positions in that level and find one that reaches farthest
    
    Time: O(n)
    Space: O(1)
*/
// Greedy Soln
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int l =0;
        int r =0;
        int farthest =0;
        int res =0;
        while(r<nums.size()-1){
            // iterate throught items in current level
            for(int i=l;i<=r;i++){
                farthest = max(farthest, i+nums[i]); // farthest you can reach from current level
            }
            l=r+1;      // start of next level
            r=farthest; // end of next level
            res++;      // count no: of levels which is equivalent to number of steps taken to reach target
        }
        return res;
    }
};

//DP soln
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        vector<int> dp(nums.size(), -1);
        dp[nums.size() - 1] = 0; // goal require 0 jump from itself to reach goal
        
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] == 0) continue;
            // reset to MAX for each position
            int min = INT_MAX;
            
            for(int j = 1; j <= nums[i] && j + i < nums.size(); j++) // all steps possible from current position (current value)
            {
                if(dp[j + i] != -1 && dp[j + i] < min) // if the jumped-to position has minimum no: steps to reach target
                    min = dp[j + i];
            }
            // 1 jump to get to that min non -ve valued position within curr positions range + min_jump required from there to goal
            if(min != INT_MAX) dp[i] = min + 1;
        }
        
        return dp[0];
        
    }
}; 
// ==================================================================================================

// Solution - III (Iterative Dynamic Programming - Tabulation) [Accepted]

// We can solve this iteratively as well. For this, we start from the last index. We need 0 jumps from nums[n-1] to reach the end. We store this as dp[n - 1] = 0 and then iteratively solve this for each previous index till the 0th index. Here dp[i] denotes minimum jumps required from current index to reach till the end.

// For each index, we explore all the possible jump sizes available with us.
// The minimum jumps required to reach the end from the current index would be - min(dp[jumpLen]), where 1 <= jumpLen <= nums[currentPostion]
int jump(vector<int>& nums) {
	int n = size(nums);
	vector<int> dp(n, 10001);
	dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here
	// same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end
	for(int i = n - 2; i >= 0; i--) 
		for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
			dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);  // min(n-1, i + jumpLen) for bounds handling
	return dp[0];
}
// Time Complexity : O(N^2)
// Space Complexity : O(N)
// ==================================================================================================
// Solution - II (Recursive Dynamic Programming - Memoization) [Accepted]

// We can see that for a given position, we are repeatedly calculating the same answer over and over again. The jumps required to reach for a given index on the path remains fixed and can be stored in dp array to avoid re-calculations.

// The solution is similar as the brute force with just the change that we are storing the solutions for each pos and returning it if it is already calculated.

int jump(vector<int>& nums) {
	vector<int> dp(size(nums), 10001); // initialise all to max possible jumps + 1 denoting dp[i] hasn't been computed yet
	return solve(nums, dp, 0);
}
// recursive solver to find min jumps to reach end
int solve(vector<int>& nums, vector<int>& dp, int pos) {
	if(pos >= size(nums) - 1) return 0;    // when we reach end, return 0 denoting no more jumps required
	if(dp[pos] != 10001) return dp[pos];    // number of jumps from pos to end is already calculated, so just return it
	// explore all possible jump sizes from current position. Store & return min jumps required
	for(int j = 1; j <= nums[pos]; j++)
		dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));        
	return dp[pos];
}
// Time Complexity : O(N^2)
// Space Complexity : O(N)
// ==================================================================================================

int main(){
    
    return 0;
}