#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    https://leetcode.com/problems/largest-rectangle-in-histogram/

    Given array of heights, return area of largest rectangle
    Ex. heights = [2,1,5,6,2,3] -> 10 (5 x 2 at index 2 and 3)

    Strategy: Maintain a Monotonic increasing stack,
            if curr height lower extend back,
            find max area

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // pair: [index, height]
        stack<pair<int, int> > stk;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            // pop from stack if current element height is lower 
            // compared to that of element at stack top 
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int width = i - index;
                int height = stk.top().second;
                stk.pop();
                // update max height till now
                result = max(result, height * width);
                // start of new element can begin from 
                // the index of popped element from stack
                start = index;
            }
            
            stk.push({start, heights[i]});
        }
        
        // for each remaining elements in stack()
        // i.e each didnt have a lower height to its right
        while (!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            
            result = max(result, height * width);
        }
                          
        return result;
    }
}; 

int main(){
    
    return 0;
}