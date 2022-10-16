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

int main(){
    
    return 0;
}