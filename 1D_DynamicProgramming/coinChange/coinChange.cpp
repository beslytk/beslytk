#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given array of coins & an amount, return fewest coins to make that amount
    Ex. coins = [1,2,5], amount = 11 -> 3, $11 = $5 + $5 + $1

    Compute all min counts for amounts up to i, "simulate" use of a coin

    Time: O(m x n) -> m = # of coins, n = amount
    Space: O(n)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // default to max amount
        dp[0] = 0;
        
        for (int i = 1; i < amount + 1; i++) {  // compute min number of coins for each amountVal from 1 to amount
            for (int j = 0; j < coins.size(); j++) { // consider each coin
                if (i - coins[j] >= 0) {             // if the coin has lesser/equal value to current amount
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);  // 1 for coin selected + minWays for amount <i - coins[j]>
                }
            }
        }
        
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
}; 

int main(){
    
    return 0;
}