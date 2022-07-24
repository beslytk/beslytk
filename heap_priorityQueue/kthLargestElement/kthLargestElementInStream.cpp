#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

 /*
    Design a class to find the kth largest element in a stream

    Min heap & maintain only k elements, top will always be kth largest
    Ex. nums = [6,2,3,1,7], k = 3 -> [1,2,3,6,7] -> [3,6,7]

    Time: O(n log n + m log k) -> n = length of nums, m = add calls
    Space: O(n)
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        // pop will delete the smallest element
        while (pq.size() > this->k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        // top will hold kth largest, since pQue size is limited to k
        return pq.top();
    }
private:
    int k;
    // signature for a min Heap
    priority_queue<int, vector<int>, greater<int> > pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){
    
    return 0;
}