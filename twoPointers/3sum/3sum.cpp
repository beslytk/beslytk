/**
 * @file 3sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * https://leetcode.com/problems/3sum/
 * 
 */
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // list of all possible solns
        vector<vector<int> > result; 
        //sort to avoid repeating solutions
        sort(nums.begin(), nums.end());
        
        for (size_t i = 0; i < nums.size() - 2; i++){
            int a =  nums[i];
            // avoid repeating solution by making 1st number unique
            if(a == nums[i-1]){
                continue;
            }

            int l = i+1;
            int r = nums.size() - 1;
            // since sorted, two pointers can be used to easily arrive at soln
            while (l<r)
            {
                int threeSum = a + nums[l] + nums[r];

                if(threeSum < 0){
                    l++;
                }else if(threeSum > 0){
                    r--;
                }else{
                    result.push_back({a, nums[l], nums[r]});
                    l++;
                    // avoid repeating solution by making 2nd number unique
                    while((nums[l] == nums[l-1]) && l<r){
                        l++;
                    }
                }

            }
            
        }
        return result;
    }
};

int main(){
    vector<int> nums {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int> > solList = s.threeSum(nums);

    for (auto &&v : solList)
    {
        cout<<"{ ";
        for (auto &&n : v)
        {
            cout<<n<<", ";
        }
        cout<<"}";
        
    }
    
    return 0;
}