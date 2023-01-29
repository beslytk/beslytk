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
                subs.push_back(subs[i]);   // push a copy of existing subset from prev Iter // add the existing el from prev iteration of nums arr
                subs.back().push_back(num); // push to subset copied in prev step, the curr num  // insert to 'existing el from prev iteration of nums arr', the new num and add as new entry in subs
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

// ============================================================================
// n = size of given integer set
// subsets_count = 2^n
// for i = 0 to subsets_count
//     form a subset using the value of 'i' as following:
//         bits in number 'i' represent index of elements to choose from original set,
//         if a specific bit is 1 choose that number from original set and add it to current subset,
//         e.g. if i = 6 i.e 110 in binary means that 1st and 2nd elements in original array need to be picked.
//     add current subset to list of all subsets

int get_bit(int num, int bit) {
	int temp = (1 << bit);
	temp = temp & num;
	if (temp == 0) {
		return 0;
	}
	return 1;
}

void get_all_subsets(vector<int>& v, vector<unordered_set<int>>& sets) {	
	int subsets_count = pow((double)2, (double)v.size());
	for (int i = 0; i < subsets_count; ++i) {
		unordered_set<int> set;
		for (int j = 0; j < v.size(); ++j) {
			if (get_bit(i, j)) {
				set.insert(v[j]);
			}
		}
		sets.push_back(set);
	}
}

int main() {
  int myints[] = {8,13,3,22, 17, 39, 87, 45, 36};
	std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
	vector<unordered_set<int>> subsets;

	get_all_subsets(v, subsets);
	cout << "****Total*****" << subsets.size() << endl;
	for (int i = 0; i < subsets.size(); ++i) {
		cout << "{";
		for (unordered_set<int>::iterator it = subsets[i].begin(); it != subsets[i].end(); ++it) {
			cout << *it << ",";
		}
		cout << "}" << endl;
	}
	cout << "****Total***** = " << subsets.size() << endl;
	return 0;
}