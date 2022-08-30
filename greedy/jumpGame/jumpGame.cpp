#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given int array, return true if can reach last index
    Ex. nums = [2,3,1,1,4] -> true, index 0 to 1 to last

    Greedy: At each point, determine furthest reachable index

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        
        for (int i = 0; i < n; i++) {
            if (i > reachable) { // if previous values couldnt reach to current index
                return false;
            }
            reachable = max(reachable, i + nums[i]);
            if (reachable >= n - 1) { //if reached goal, exit and ret true
                break;
            }
        }
        
        return true;
    }
}; 

int main(){
    
    return 0;
}