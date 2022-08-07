#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given non-empty, non-negative integer array nums, find if:
    Can be partitionined into 2 subsets such that sums are equal
    Ex. nums = [1,5,11,5] -> true, [1,5,5] & [11], both add to 11

    Maintain DP set, for each num, check if num in set + curr = target
    If not, add curr to every num in set we checked & iterate

    Time: O(n x sum(nums))
    Space: O(sum(nums))
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            target += nums[i];
        }
        if (target % 2 != 0) {
            return false;
        }
        target /= 2;
        
        unordered_set<int> dp;
        dp.insert(0);  // sum 0 can be obtained by not adding any nums
        
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> dpNext;
            for (auto it = dp.begin(); it != dp.end(); it++) {
                if (*it + nums[i] == target) {
                    return true;  
                }
                dpNext.insert(*it + nums[i]); // insert new sum by adding curr(i) num to existing items in dp
                dpNext.insert(*it);           // also retain the existing elements in dp
            }
            dp = dpNext;
        }
        
        return false;
    }
}; 

int main(){
    
    return 0;
}