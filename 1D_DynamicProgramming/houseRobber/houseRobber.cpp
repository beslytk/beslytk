#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given int array, return max amount can rob (can't rob adjacent houses)
    Ex. nums = [1,2,3,1] -> 4, rob house 1 then house 3: 1 + 3 = 4

    Recursion w/ memoization -> DP, rob either (2 away + curr), or (1 away discarding curr)
    Recurrence relation: robFrom[i] = max(robFrom[i-2] + nums[i], robFrom[i-1])

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;
        int curr = 0;
        // {prev2, prev1, curr, ...}
        for (int i = 0; i < nums.size(); i++) {
            curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
}; 

int main(){
    
    return 0;
}