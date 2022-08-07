#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

// O(2^n) DFS - Recurrence Soln
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false; // if Odd
        sum>>=1; // targetSum = sum/2
        return dfs(0,sum,nums);
    }
    bool dfs(int p, int sum, vector<int>& nums) {
        if(!sum) return true;
        if(sum<0 || p==nums.size()) return false;
        return dfs(p+1,sum,nums)||dfs(p+1,sum-nums[p],nums); // take or not-take current value at p
    }

// O(ns) DFS with Memoization. if there is no constraint on the array size and number size,
//  I would say this is the overall best solution.
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return 0;
        vector<unordered_map<int,bool> > mem(nums.size()); // rows->numsArrEl , cols->map->sum|bool
        return dfs(0,sum>>1,nums,mem);
    }
    bool dfs(int p, int sum, vector<int>& nums, vector<unordered_map<int,bool>>& mem) {
        if(!sum) return true; // reached 0 sum -> was able to form target sum with array elements
        if(sum<0 || p==nums.size()) return false;
        auto it = mem[p].find(sum);
        if(it!=mem[p].end()) return it->second; // if for current idx p, possibility of sum is already computed
        // take or not-take current value at p and reduce sum and dfs to next elem
        return mem[p][sum]=dfs(p+1,sum,nums,mem)||dfs(p+1,sum-nums[p],nums,mem); 
    }
// O(ns) time, O(ns) space DP/BFS. Starting with 0, we add the next number to the current level sum
//  and generate next level sums. The problem asks if there exist one solution. For this kind of problem,
//  BFS might waste some time while DFS which just goes for one solution could be better. This is similar to word break.
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0), n = nums.size();
        if(sum&1) return 0;
        vector<unordered_set<int>> dp(n+1);
        dp[0].insert(0);
        for(int i=0;i<n;i++)
            for(int s:dp[i]) {
                if(s==sum/2) return true;
                if(s>sum/2) continue; // if greater than required target sum, no need to further add the same or its combination
                dp[i+1].insert(s);
                dp[i+1].insert(s+nums[i]);
            }
        return 0;
    }
// O(ns) time, O(s) space dp. We only need to cache the current level and the next level.
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return 0;
        unordered_set<int> cur, nxt({0});
        for(int n:nums) {
            cur = nxt;
            for(int s:cur) {
                if(s==sum/2) return 1;
                if(s+n<=sum/2) nxt.insert(s+n);
            }
        }
        return 0;
    }
// O(ns) DP. Due to the small input data, we can use a 'bit vector' to represent all sums. 
// This saves the overhead of hashtable. The dp/BFS approach just expands the current sums, 
// so if they are in order, we can just update the current level.
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return 0;
        vector<bool> dp(1+(sum>>=1));
        dp[0]=1;
        for(int n:nums) {
            for(int i=sum-1;i>=0;i--) {
                if(!dp[i]) continue;
                if(i+n<=sum) dp[i+n]=1;
            }
            if(dp[sum]) return 1;
        }
        return 0;
    }
// What if the input numbers are arbitrary? Then it becomes similar to target sum. Assuming no overflow, then we need to generate all possible sums. I think #2 should do better than #5 

int main(){
    
    return 0;
}