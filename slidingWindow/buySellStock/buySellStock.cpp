#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given array prices, return max profit w/ 1 buy & 1 sell
    Ex. prices = [7,1,5,3,6,4] -> 5 (buy at $1, sell at $6)
    For each, get diff b/w that & min value before, store max
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = prices[0];
        int maxDiff = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            minValue = min(minValue, prices[i]);
            maxDiff = max(maxDiff, prices[i] - minValue);
        }
        
        return maxDiff;
    }
}; 

int main(){
    
    vector<int> stockPrices {7,1,5,3,6,4};
    Solution s;
    int maxProfit = s.maxProfit(stockPrices);
    cout<<"maxProfit is: " <<maxProfit<<endl;
    return 0;
}