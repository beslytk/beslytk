#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
/**
 * @brief   https://leetcode.com/problems/find-the-duplicate-number
 * Strategy:Perform Binary Search on range 1 to n;
            low = 1, high = nums.size() - 1;
            While the value of high is greater than or equal to low.
            calculate mid.
            count elements <= to mid.
            if count is less than equal to mid.
            low = mid + 1 (binary search on right half)
            else high = mid + 1 (binary search on left half)
            Return low which will point to duplicate.
 */

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
    }
	// for github repository link go to my profile.
}; 

/*
    Given int array, return the one repeated number
    Ex. nums = [1,3,4,2,2] -> 2, nums = [3,1,3,4,2] -> 3
    If there's duplicate, must be a cycle, find meeting point
    Take 1 back to start, they'll intersect at the duplicate
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        // treat node value as pointer to next node
        // detect node where slow and fast intersect
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        slow = 0;
        // distance to traveerse to cycle start node
        // from intersect nodewill be same as that from head node.
        // floyd's cycle detection:
        // the begin of cycle will be the duplicate
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){

    Solution1 sol1;
    vector<int> nums {1,3,4,2,2};
    cout<<"the duplicate value is: " <<sol1.findDuplicate(nums);  
    cout<<endl;
    Solution sol;
    cout<<"the duplicate value is: " <<sol.findDuplicate(nums);  
    return 0;
}