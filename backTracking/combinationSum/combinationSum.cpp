#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given distinct int array & a target, return list of all unique combos that sum to target
    Ex. candidates = [2,3,6,7] target = 7 -> [[2,2,3],[7]]
    Backtracking, generate all combo sums, push/pop + index checking to explore new combos
    Time: O(n^target)
    Space: O(target)
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> curr;
        vector<vector<int>> result;
        
        // dfs(candidates, target, 0, 0, curr, result);
        dfs_w_bound(candidates, target, 0, 0, curr, result);
        return result;
    }
private:
    void dfs(vector<int>& candidates, int target, int sum, int start, vector<int>& curr, vector<vector<int>>& result) {
        if ((sum > target) || (start > candidates.size()))   {
            return;
        }
        
        if (sum == target) {
            result.push_back(curr);
            return;
        }

        curr.push_back(candidates[start]);
        // current element (start) could be used in next iteration, as repetition is allowed
        dfs(candidates, target, sum + candidates[start], start, curr, result);
        curr.pop_back();
        // iteration without the current element
        dfs(candidates, target, sum, start + 1, curr, result);

    }

    void dfs_w_bound(vector<int>& candidates, int target, int sum, int start, vector<int>& curr, vector<vector<int>>& result) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            // same i could be used again
            dfs_w_bound(candidates, target, sum + candidates[i], i, curr, result);
            curr.pop_back();
        }
    }
}; 

int main(){
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    for (auto &&vec : res)
    {
        cout<<"{";
        for (auto &&num : vec)
        {
            cout<<num<<", ";
        }
        cout<<"},";
    }
    
    return 0;
}