#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Array of stock prices, find max profit
    After a sell cooldown of 1 day, can't engage in multiple transactions
    Ex. prices = [1,2,3,0,2] -> 3, transactions = [buy,sell,cd,buy,sell]

    DP + state machine: held ---> sold ---> reset ---> held
                             sell      rest       buy

    Time: O(n)
    Space: O(1) -> optimized from O(n) since only need i - 1 prev state
*/
// We have three states:
//             - s0: starting state, no stock, can rest or buy
//             - s1: just bought stock, can rest or sell
//             - s2: just sold stock, must rest
//         The reason state s2 exists is that we want to force a rest between leaving s1 (previous sell) and s0 (next buy).
//         Each state has the following actions:
//             - s0:
//                 - s0 -> s0: no stock, rest
//                 - s0 -> s1: buy new stock
//             - s1:
//                 - s1 -> s1: hold stock, rest
//                 - s1 -> s2: sell stock
//             - s2:
//                 - s2 -> s0: forced rest
//         Let sk[j], k = {0, 1, 2}, j = {0, 1, ..., n}, denote the profit at state sk on day j
//         (e.g., s1[2] is the profit on day 2 if we happened to be there).
//         ~~~>We have the following ways to enter each state:
//             - Entering s0[i]:
//                 - From s0[i-1]: rest on day i, so profit remains the same as s0[i-1]
//                 - From s2[i-1]: forced rest on day i, so profit remains the same as s2[i-1]
//             - Entering s1[i]:
//                 - From s1[i-1]: rest on day i, so profit remains the same as s1[i-1]
//                 - From s0[i-1]: bought stocks on day i, so profit is updated to (s0[i-1]-profits[i])
//             - Entering s2[i]:
//                 - From s1[i-1]: sold stock on day i, so profit is updated to (s1[i-1]+profits[i])
//         Initial states:
//             - s[0] = 0: you start with 0 profit on day 0
//             - s1[0] = -prices[0]: if you bought stock on day 0, ur profit is -prices[0] 
//             - s2[0] = X: dummy state as you need two days to buy and sell
        
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //initialise two vector for storing the value after buying and selling stock...
        vector<int> s0(n, 0);
        vector<int> s1(n, 0);
        vector<int> s2(n, 0);
        s0[0] = 0; // profit is 0 for resting state
        s1[0] = -prices[0];//we bought first stock 0n very first day, and profit is -ve
        s2[0] = INT_MIN;
        for (int i = 1; i < n; i++) {
            s0[i] = max(s0[i - 1], s2[i - 1]);  // rest
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]); // buy
            s2[i] = s1[i - 1] + prices[i];      // sell
        }
        return max(s0[n - 1], s2[n - 1]);
    }
};
// Mem Optimization
// for each index, keep track of the 3 states in the previous index
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;
        int hold = INT_MIN;
        int rest = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            int prevSold = sold;
            sold = hold + prices[i]; // increment profit from holding stock in last day, by selling @ todays price
            hold = max(hold, rest - prices[i]);// rest curr day therefore hold profit from prev (OR) consider buying todays stock, when yesterday was rest
            rest = max(rest, prevSold);// rest on day i, so profit remains the same as prev rest OR forced rest on day i, so profit remains the same as prevSold
        }
        
        return max(sold, rest);
    }
};

// The recursion state is simple, here we decide whether to buy or sell stock on ith day or just ignore the current day for stock trading.
// This makes two different recursive calls and we take maximum among them. If you want to sell the stock then skip the next day (currIndex+2) for trading. 
// Also for n day cooldown period just make (currIndex+n) in (!buyIt) recursive call.
// This base recursive solution will give you tle, then apply memoization (by looking at the parameters that you are changing in recursive calls).
// For applying memoization I used map of pair which is slightly slower as compared to a 2d array that can be used in this case (int dp[n][2]).

class Solution {

    map<pair<int,bool>,int> mp; // pair<index, buy?> => profit  
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n == 0 || n == 1)    return 0; // not enough days list to buy and then sell
        
        mp.clear();
        return earnMaxProfit(prices,0,n,true);
        
    }

    int earnMaxProfit(vector<int>& prices,int currIndex,int n,bool buyIt){
        
        if(currIndex >= n)  return 0;
        
        if(mp.find(make_pair(currIndex,buyIt)) != mp.end()) return mp[make_pair(currIndex,buyIt)];
        
        int opt1 = 0;
        int opt2 = 0;
        
        if(buyIt){
            opt1 = -1*prices[currIndex] + earnMaxProfit(prices,currIndex+1,n,false);    
        }else{
            opt1 = prices[currIndex] + earnMaxProfit(prices,currIndex+2,n,true); 
        }    
            
        opt2 = earnMaxProfit(prices,currIndex+1,n,buyIt); // cooldown
            
        
        return mp[make_pair(currIndex,buyIt)] = max(opt1,opt2);
    }
};

int main(){
    
    return 0;
}