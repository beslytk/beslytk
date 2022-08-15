#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

// https://leetcode.com/problems/burst-balloons/
/*
    Given array of balloons w/ coins, if burst ith, get (i-1) + i + (i+1) coins
    Return max coins can collect by bursting the balloons 'wisely'

    DP to return max coins obtainable in each interval [left, right]
    Divide & conquer left & right depends on previous bursts, so think backwards
    Instead of which one to burst first, //?need to think which one to burst last

    Time: O(n^3) -> O(n^2) states, for each states, determining max coins is O(n)
    Space: O(n^2) -> O(n^2) to store all states
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 before & after nums for implicit multiplication
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        
        // cache results of dp
        vector<vector<int>> memo(n, vector<int>(n, 0));
        
        // 1 & n - 2 since we can't burst our fake balloons
        return dp(nums, memo, 1, n - 2);
    }
private:
    int dp(vector<int>& nums, vector<vector<int>>& memo, int left, int right) {
        // base case-> interval is empty, yields 0 coins
        if (right - left < 0) {
            return 0;
        }
        
        // we've already seen this, return from cache
        if (memo[left][right] > 0) {
            return memo[left][right];
        }
        
        // find the last burst in nums[left]...nums[right]
        int result = 0;
        for (int i = left; i <= right; i++) {  // last burst balloon could be any among the balloons btw left and right
            // nums[i] is the last burst
            int curr = nums[left - 1] * nums[i] * nums[right + 1];
            // nums[i] is fixed, recursively call left & right sides
            int remaining = dp(nums, memo, left, i - 1) + dp(nums, memo, i + 1, right); // left and right subArray to fixed balloon
            result = max(result, curr + remaining);
        }
        // add to cache
        memo[left][right] = result;
        return result;
    }
}; 

int main(){
    
    return 0;
}

/**
    Bruteforce: Generate all permutations for the ordering of balloons and check which permutation yields the best profit.
    But it will take O(n!) time.
    We then think can we apply the divide and conquer technique? After all there seems to be many self similar sub problems from the 
    previous analysis.

    Well, the nature way to divide the problem is burst one balloon and separate the balloons into 2 sub sections one on the left and 
    one on the right. However, in this problem the left and right become adjacent and have effects on the maxCoins in the future.

    Then another interesting idea come up. Which is quite often seen in dp problem analysis. That is reverse thinking. Like I said the  
    coins you get for a balloon does not depend on the balloons already burst. Therefore
    instead of divide the problem by the first balloon to burst, we divide the problem by the last balloon to burst.

    Why is that? Because only the first and last balloons we are sure of their adjacent balloons before hand!

    For the first we have nums[i-1]*nums[i]*nums[i+1] for the last we have nums[-1]*nums[i]*nums[n].

    OK. Think about n balloons if i is the last one to burst, what now?

    We can see that the balloons is again separated into 2 sections. But this time since the balloon i is the last balloon of all to burst, 
    the left and right section now has well defined boundary and do not affect each other! Therefore we can do either recursive method with 
    memoization or dp.
 */

// DP Solution: For a DP solution to exist, we need to define the subproblems. Let's define the problem first as:

// solve(nums, i, j)
// by which I mean that we need to burst balloons starting from index i to index j. At the beginning, they'll be 0, nums.size() -1 
// respectively. Let's suppose we burst the kth balloon in the first chance. We will get nums[k-1] * nums[k] * nums[k+1] coins. 
// Now let's define the subproblems as:

// solve(nums, i, k - 1) , solve(nums, k + 1, j)
// As the balloon k is already burst, we solve the subproblems from i to k -1 and k + 1 to j. But wait, what's going wrong here? 
// The subproblem solve(nums, i, k - 1) and solve(nums, k + 1, j) are not independent since after bursting kth balloon, balloon k - 1 and 
// k + 1 have become adjacent and they will need each other in order to calculate the profit.


// So, as we saw that if we choose the kth balloon to be the first one to be burst, we can't make the subproblems independent. 
// Let's try the other way round. We choose the kth balloon as the last one to be burst. Now the subproblems will become independent 
// since (k - 1)th balloon and (k + 1)th balloon won't need each other in order to calculate the answer.

// Now for each k starting from i to j, we choose the kth balloon to be the last one to be burst and calculate the profit by solving 
// the subproblems recursively. Whichever choice of k gives us the best answer, we store it and return.
// Important point to be noted here is that the balloons in the range (i, k - 1) and (k + 1, j) will be burst BEFORE kth balloon. 
// So, when we burst the kth balloon, the profit will be nums[i - 1] * nums[k] * nums[j + 1] PROVIDED that index i - 1 and j + 1 are valid.