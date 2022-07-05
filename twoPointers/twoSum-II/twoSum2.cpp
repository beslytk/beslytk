#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007


/*
    Given a 1-indexed sorted int array & target:
    Return indices (added by 1) of 2 nums that add to target

    2 pointers, outside in, iterate i/j if sum is too low/high

    Time: O(n)
    Space: O(1)
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        
        vector<int> result;
        
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
            }
        }
        
        return result;
    }
};

 

int main(){


    vector<int> nums {2,7,11,15};
    Solution s;
    int target = 9;
    vector<int> numComb = s.twoSum(nums, target);
    for (auto &&n : numComb)
    {
        cout<< n<<", ";
    }
    
    return 0;
}