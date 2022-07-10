#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
/*
    Given int array & sliding window size k, return max sliding window
    Ex. nums = [1,3,-1,-3,5,3,6,7] k = 3 -> [3,3,5,5,6,7]
    Sliding window deque, ensure monotonic decr, leftmost largest
    Time: O(n)
    Space: O(n)
*/
class Solution{

public:
    vector<int> findMaxInWindow(vector<int>& numArr, int k){

        vector<int> result;
        deque<int> dq;

        int l=0, r=0;

        while(r< numArr.size()){
            // ensure the deque is always in decreasing order
            // if the newly added element is bigger, remove the rightmost element
            while(!dq.empty() && numArr[dq.back()]<numArr[r]){
                dq.pop_back();
            }
            // queue the index of elements from in array
            dq.push_back(r);
            // remove elements from left as window slides right
            if(l> dq.front()){
                dq.pop_front();
            }

            if((r+1) >= k){
                result.push_back(numArr[dq.front()]);
                l++; // increment left boundary from when the window size is reached for first time
            }
            r++;
        }
        return result;
    }

};

int main(){

    vector<int> numArr {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sol;
    vector<int> res = sol.findMaxInWindow(numArr, k);
    for (auto &&num : res)
    {
        cout<<num<<", ";
    }
    
    return 0;
}