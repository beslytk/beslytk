#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Implement data structure that gets the median from a data stream

    Max heap of lower values & min heap of higher values, access to mids

    Time: O(log n) + O(1)
    Space: O(n)
    https://leetcode.com/problems/find-median-from-data-stream/
*/

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lower.empty()) {
            lower.push(num);
            return;
        }
        // if 'lower' is bigger in size, insert 'num' to 'higher'
        // but also compare 'num' with top of 'lower'
        if (lower.size() > higher.size()) {
            if (lower.top() > num) {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            } else {
                higher.push(num);
            }
        } else {
            if (num > higher.top()) {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            } else {
                lower.push(num);
            }
        }
    }
    
    double findMedian() {
        double result = 0.0;
        
        if (lower.size() == higher.size()) {
            result = lower.top() + (higher.top() - lower.top()) / 2.0;
        } else {
            if (lower.size() > higher.size()) {
                result = lower.top();
            } else {
                result = higher.top();
            }
        }
        
        return result;
    }
private:
    priority_queue<int> lower; // max-heap
    priority_queue<int, vector<int>, greater<int> > higher; // min heap
};



int main(){
    
    /**Your MedianFinder object will be instantiated and called as such:*/
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double param_2 = obj->findMedian();
    cout<< "current median is: "<< param_2<<endl;
    obj->addNum(3);
    cout<< "current median is: "<< obj->findMedian()<<endl;
    return 0;
}