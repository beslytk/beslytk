#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given int array in a circle, return max amount can rob (can't rob adj houses)
    Ex. nums = [2,3,2] -> 3, can't rob house 1 & 3 b/c circular adj, so rob 2

    Recursion w/ memo -> DP, rob either 2 away + here, or 1 away, try both ranges
    Recurrence relation: robFrom[i] = max(robFrom[i-2] + nums[i], robFrom[i-1])

    Time: O(n)
    Space: O(1)
    https://leetcode.com/problems/house-robber-ii/
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // to handle circular adjacency consider 2 subarrays including 1st and last separately
        int range1 = robber(nums, 0, n - 2); // subArray 0 to n-2
        int range2 = robber(nums, 1, n - 1); // subArray 1 to n-1
        
        return max(range1, range2);
    }
private:
    int robber(vector<int>& nums, int start, int end) {
        int prev = 0;
        int prev2 = 0;
        int curr = 0;
        
        for (int i = start; i <= end; i++) {
            curr = max(prev + nums[i], prev2);
            prev = prev2;
            prev2 = curr;
        }
        
        return prev2;
    } 
};
int main(){
    
    return 0;
}