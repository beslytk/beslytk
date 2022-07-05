#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007


/*
    Given elevation map array, compute trapped water
    Ex. height = [0,1,0,2,1,0,1,3,2,1,2,1] -> 6
    2 pointers, outside in, track max left/right
    For lower max, curr only dependent on that one
    Compute height of these, iterate lower one
    Time: O(n)
    Space: O(1)

    https://leetcode.com/problems/trapping-rain-water/
    Note:
    for any position(i), the trapped water = min( heights[i-1], heights[i+1] ) - heights[i]
*/

class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int totalTrapped = 0;
        int leftMaxHt = heights[l];
        int rightMaxHt = heights[r];

        while(l < r){

            if(leftMaxHt < rightMaxHt){
                l++; 
                totalTrapped += (leftMaxHt - heights[l])>0?(leftMaxHt - heights[l]) :0;
                leftMaxHt = max(leftMaxHt, heights[l]);
            }else{
                r--; 
                totalTrapped += (rightMaxHt - heights[r])>0?(rightMaxHt - heights[r]):0;
                rightMaxHt = max(rightMaxHt, heights[r]);
            }

        }
        return totalTrapped;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> heightsIn {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    int trappedWater = s.trap(heightsIn);
    cout<< trappedWater <<endl;
    return 0;
}

