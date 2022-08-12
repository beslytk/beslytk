#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

// Dynamic Programming Unbounded Knapsack - Leetcode 518
/*
    Given array of coins & an amount, return # of combos that make up this amount
    Ex. amount = 5, coins = [1,2,5] -> 4 (5, 2+2+1, 2+1+1+1, 1+1+1+1+1)

    DFS + memo, 2 choices: either try coin & stay at idx, or don't try & proceed

    Time: O(m x n)
    Space: O(m x n)
*/

//         5   4   3   2   1   0      <-amount
//     __________________________
// c 1  |  4   3   2   2   1    1
// o    |------------------------                       1
// i 2  |  1   1   0   1   0    1
// n    |------------------------
// s 5  |  1   0   0   0   0    1
// |
// v
// Any cell value-> indicates whats the numOfWays to create amount(col) when you have coins (row, row +1.. etc)
// 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return dfs(amount, coins, 0, 0);
    }
private:
    // {(index, sum) -> # of combos that make up this amount}
    map<pair<int, int>, int> dp;
    
    int dfs(int amount, vector<int>& coins, int i, int sum) {
        if (sum == amount) {
            return 1;
        }
        if (sum > amount) {
            return 0;
        }
        if (i == coins.size()) {
            return 0;
        }
        if (dp.find({i, sum}) != dp.end()) {
            return dp[{i, sum}];
        }
        
        dp[{i, sum}] = dfs(amount, coins, i, sum + coins[i])
                     + dfs(amount, coins, i + 1, sum);
        
        return dp[{i, sum}];
    }
}; 

int main(){
    
    return 0;
}