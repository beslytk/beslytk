#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given an integer array of unique elements, return all possible subsets (the power set)
    Ex. nums = [1,2,3] -> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    Backtracking, generate all combinations, push/pop + index checking to explore new combos
    Time: O(n x 2^n)
    Space: O(n)
*/

class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        dfs(nums, 0, curr, result);
        return result;
    }
private:
    // each level choose to select a number or not select it
    void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result) {
        result.push_back(curr);
        // loop run for pending numbers in list
        for (int currNum = start; currNum < nums.size(); currNum++) {
            curr.push_back(nums[currNum]);
            dfs(nums, currNum + 1, curr, result); //go to next num, including curren num
            curr.pop_back(); //go to next num, ignoring curren num
        }
    }
}; 

// Iterative
// Using [1, 2, 3] as an example, the iterative process is like:
// Initially, one empty subset [[]]
// Adding 1 to []: [[], [1]];
// Adding 2 to [] and [1]: [[], [2], [1], [1, 2]];
// Adding 3 to [], [1], [2] and [1, 2]: [[], [3], [1], [1, 3], [2], [2, 3], [1, 2], [1, 2, 3]].
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        // loop over each number in the list
        for (int num : nums) {
            int n = subs.size();
            // to each existing subset, append the current number
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]);     // add the existing el from prev iteration of nums arr
                subs.back().push_back(num);  // insert to 'existing el from prev iteration of nums arr', the new num and add as new entry in subs
            }
        }
        return subs;
    }
};

// Bit Manipulation
// To give all the possible subsets, we just need to exhaust all the possible combinations of the numbers. 
// And each number has only two possibilities: either in or not in a subset. And this can be represented using a bit.
// Using [1, 2, 3] as an example,
//  1 appears once in every two consecutive subsets,
//  2 appears twice in every four consecutive subsets,
//  and 3 appears four times in every eight subsets (initially all subsets are empty):
// [], [ ], [ ], [    ], [ ], [    ], [    ], [       ]
// [], [1], [ ], [1   ], [ ], [1   ], [    ], [1      ]
// [], [1], [2], [1, 2], [ ], [1   ], [2   ], [1, 2   ]
// [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
// idx 0 element-> subIdx with 1 at bit0 (1,3,5,7)
// idx 1 element-> subIdx with 1 at bit1 (2,3,6,7)
// idx 2 element-> subIdx with 1 at bit2 (4,5,6,7)

class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), numSubsets = 1 << n;
        vector<vector<int> > subs(numSubsets);
        for (int subIdx = 0; subIdx < numSubsets; subIdx++) {
            for (int idx = 0; idx < n; idx++) {
                if ((subIdx >> idx) & 1) {
                    subs[subIdx].push_back(nums[idx]);
                }
            }
        }
        return subs;
    }
};

int main(){
    // Solution1 sol;
    // Solution2 sol;
    Solution3 sol;

    vector<int> nums = {1,2,3};
    
    vector<vector<int> > result = sol.subsets(nums);
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