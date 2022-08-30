#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

//  https://leetcode.com/problems/count-vowels-permutation/

class Solution {
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        long a2, e2, i2, o2, u2; 
        
        for (int j = 2; j <= n; j++) {
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = i;
            u2 = (o + i) % mod;
            
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        return (a + e + i + o + u) % mod;
    }
};


//Brute-Force
// We can start with any of the 5 vowels and thereafter we have the choice to choose next vowel depending on what's allowed after the previous vowel in the given mappings. The given mappings state what vowels are allowed after a given vowel -

// start   =>  a / e / i / o / u   # start denotes 1st character of string which can be any vowel
// a       =>  e
// e       =>  a / i
// i       =>  a / e / o / u
// o       =>  i / u
// u       =>  a
// So, we will follow this approach. At each index, we will try choosing all vowels allowed after the previous one. The start will be denoted by s (any vowel is allowed after it).

class Solution {
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings{ {'s', {'a', 'e', 'i', 'o', 'u'} }, // start
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
public:
    int countVowelPermutation(int n) {
        return solve(n, 's');                         // start with s
    }
    int solve(int rem, char prev) {
        if(rem == 0) return 1;                        // no need to pick further. We have formed 1 string of length = n.
        int ans = 0;
        for(auto c : mappings.at(prev))               // try each vowel allowed after prev character
            ans = (ans + solve(rem - 1, c)) % MOD;  
        return ans;
    }
};

//Top-Down Memoization
class Solution {
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings{ {'s', {'a', 'e', 'i', 'o', 'u'} }, // start
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
    unordered_map<char, vector<int>> dp;
public:
    int countVowelPermutation(int n) {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);
        return solve(n, 's');                         // start with s
    }
    int solve(int rem, char prev) {
        if(rem == 0) return 1;                        // no need to pick further. We have formed 1 string of length = n.
        if(dp[prev][rem]) return dp[prev][rem];       // if result already calculated for current state, directly return it
        for(auto c : mappings.at(prev))               // try each vowel allowed after prev character
            dp[prev][rem] = (dp[prev][rem] + solve(rem - 1, c)) % MOD;  
        return dp[prev][rem];
    }
};

// Bottom-up Itertive:
// Each time, we use the stored number of strings possible for length i-1 to calculate for length i. We will use only those state for dp[k] from which it is allowed to use kth vowel at next position.

class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        long dp[5][n+1], ans = 0;
        dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[0][i] =  (dp[1][i-1] + dp[4][i-1] + dp[2][i-1])%mod;   // words ending with 'a'
            dp[1][i] = (dp[0][i-1] + dp[2][i-1])%mod;   // words ending with 'e'
            dp[2][i] =  (dp[1][i-1] + dp[3][i-1])%mod;   // words ending with 'i'
            dp[3][i] = (dp[2][i-1])%mod ;               // words ending with 'o'
            dp[4][i] =  (dp[3][i-1] + dp[2][i-1])%mod;   // words ending with 'u'
        }
        for(int i=0; i < 5; i++) 
            ans = (ans + dp[i][n]) % MOD;
        return ans;
    }
};

int main(){
    
    return 0;
}