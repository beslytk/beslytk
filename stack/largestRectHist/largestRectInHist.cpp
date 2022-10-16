#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    https://leetcode.com/problems/largest-rectangle-in-histogram/

    Given array of heights, return area of largest rectangle
    Ex. heights = [2,1,5,6,2,3] -> 10 (5 x 2 at index 2 and 3)

    Strategy: Maintain a 'Monotonic increasing stack',
            if curr height lower extend back,
            find max area

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int> > stk; // pair: [index, height]
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            // pop from stack if current element height is lower compared to that of element at stack top 
            while (!stk.empty() && stk.top().second > heights[i]) {
                int prevStart  = stk.top().first;
                int width      = i - prevStart;
                int prevHeight = stk.top().second;
                stk.pop(); // pop prev higher entries to maintain monotonic increasing stack
                result = max(result, prevHeight * width);   // update max height till now
                // start of new element can begin from the index of popped element from stack
                start  = prevStart;  // extending back to start of popped element
            }
            
            stk.push({start, heights[i]});
        }
        // handle the remaining heights, that didnt have lower height ahead & could be extended all the way to end
        // for each remaining elements in stack() i.e each didnt have a lower height to its right
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

// add bars to stack as long as we encounter increasing heights ahead.
// first try to extend the current height bar backwards (only possible as long as prev bars are higher or same height)
// When encounter smaller bar, pop all higher bars to left  and calculate area
// For the bars remaining in the stack,
// compute area as it can reach till end of the input array