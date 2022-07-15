#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given array of distinct integers, return all the possible permutations
    Ex. nums = [1,2,3] -> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    Permute by swapping i/start, DFS from this point, backtrack to undo swap
    Time: O(n x n!)
    Space: O(n!)
    https://leetcode.com/problems/permutations

    https://medium.com/@guguru/permutation-algorithm-via-backtracking-39fc1bf07a33
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            // swap current element with all next elements
            swap(nums[i], nums[start]);
            dfs(nums, start + 1, result);
            // backTrack the earlier swap and use to swap 
            // current with next iteration element
            swap(nums[i], nums[start]);
        }
    }
}; 

int main(){
    
    return 0;
}