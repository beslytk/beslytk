#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
// https://leetcode.com/problems/number-complement/


class Solution{
public:
    int findComplement(int num) {
        if (num==0) return 1;
        int numBits = log2(num) + 1;
        int mask = (1<<numBits) - 1;
        return num ^ mask;           // x^0 = x; x^1 = !x 
    }

};


class Solution {
public:
    int findComplement(int num) {
        if (num==0) return 1;
        int ans = 0;
        int multiplier =1;
        while(num){
            int currentBit = num&1;
            num>>=1;
            ans += multiplier*(1- currentBit);
            multiplier <<=1;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}