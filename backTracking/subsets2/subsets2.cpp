#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given an integer array of unique elements, return all possible subsets (the power set)
    Ex. nums = [1,2,2] -> [[],[1],[1,2],[1,2,2],[2],[2,2]]
    Backtracking, generate all combos, push/pop + to explore new combos, skip duplicates
    Time: O(n x 2^n)
    Space: O(n)

    Strategy: To avoid duplicates in result, make sure left subtree can include repeating number
    from array, But right subtree should skip repeating numbers
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // important step to identify duplicates
        sort(nums.begin(), nums.end());
        
        vector<int> curr;
        vector<vector<int> > result;
        
        dfs(nums, 0, curr, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int> >& result) {
        // each recursion, subsets with new element appended will be pushed to result
        result.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            // make sure, the current num is not same as the previous ignored num
            // wont affect the left subtree which can include duplicates,
            // as condition (i > start) wont be true in first iteration i.e fresh recursion
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
}; 

int main(){
    Solution sol;

    vector<int> nums = {1,2,2};
    
    vector<vector<int> > result = sol.subsetsWithDup(nums);
    for (auto &&subsetIt : result)
    {
        cout<<"{ ";
        for (auto &&num : subsetIt) 
        {
            cout<<num<<", ";
        }
        cout<<"}, ";
    }
    return 0;
}