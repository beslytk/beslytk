#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

 /*
    Design stack that supports push, pop, top, & retriving min element
    
    2 stacks, 1 normal & 1 'monotonic decreasing stack', only push if lower than top
    
    Time: O(1)
    Space: O(n)
    https://leetcode.com/problems/min-stack/
*/

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        
        if (minStk.empty() || val < minStk.top().first) {
            minStk.push({val, 1});
        } else if (val == minStk.top().first) {
            minStk.top().second++;
        }
    }
    
    void pop() {
        if (stk.top() == minStk.top().first) {
            minStk.top().second--;
            if (minStk.top().second == 0) {
                minStk.pop();
            }
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top().first;
    }
private:
    stack<int> stk;
    stack<pair<int, int>> minStk;
};

int main(){

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<< "current min is: "<< minStack.getMin()<<endl; // return -3

    minStack.pop();
    cout<< "current top is: "<< minStack.top()<<endl;    // return 0
    cout<< "current min is: "<< minStack.getMin()<<endl; // return -2
    return 0;
}