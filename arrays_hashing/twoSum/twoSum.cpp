#include<bits/stdc++.h>
#include <iterator>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9
    At each num, calculate complement, if exists in hash map then return
    Time: O(n)
    Space: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                result.push_back(m[complement]);
                result.push_back(i);
                break;
            } else {
                m.insert({nums[i], i});
            }
        }
        
        return result;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i=0;i<nums.size(); i++){
            auto compIdx = s.find(target-nums[i]);
            if(compIdx != s.end()){
                int compId = std::distance(nums.begin(), compIdx);
                res.push_back(i);res.push_back(compId);
                return res;
            }    
        }
         return res;
    }
  
};

int main(){
    
    return 0;
}