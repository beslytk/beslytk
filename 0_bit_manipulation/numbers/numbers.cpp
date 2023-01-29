#include<bits/stdc++.h>
#include <math.h>  // log2
using namespace std;
 
#define ll long long
#define mod 1000000007

// Check if the ith bit is set or not
bool isKthBitSet(int n, int k){
    int mask = 1 << (k-1);
    if(n & mask)
        return true;
    return false;
}

int setKthBit(int n, int k){
    int mask = 1<<(k-1);
    return (mask | n);
}

int clearKthBit(int n, int k){
    int mask = 1<<(k-1);
    mask = ~mask;
    return (mask & n);
}

// Remove the last set bit of a number.
int remLastSetBit(int n){
    return n & (n-1);
}
// find pos of the last set bit of a number.
// return the binary number containing the rightmost set bit as 1.
//  Log of above binary number and we will get position
int posLastSetBit(int n){
    return log2(n & ~(n-1) );
}

bool isOdd(int n){
    return n&1;
}

bool isEven(int n){
    return ((n>>1)<<1 == n);
}

bool isPower2(int n){
    return !(n & (n-1));
}
// If a given number is a power of 2 and its only set bit is present at  
// even position like 0,2,4,6,8, then it will also be power of 4
// for mask, put 0 in bit positions which are powers of 4
// put 1 everywhere else
// A = 1010 : 1 and 4 are powers of 4 :  every even bit will be power of 4
bool isPower4(int n){
    if(n==0)
        return false;
    bool mask = !(n & 0xAAAAAAAA);
    return (mask & isPower2(n));
}
// starting from 0th position, is the power of 8, so
// mask will be
// -
// 1011 0110 1101 1011 0110 1101 1011 0110
//  B    6    D     B   6     D    B    6
bool isPower8(int n){
    if(n==0)
        return false;
    bool mask = !(n & 0xB6DB6DB6);
    return (mask & isPower2(n));
}
void swap(int& a, int& b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
} 
// Count Number of bits to be flipped to convert A to B:
int countFlipBits(int A, int B){
    int n = A ^ B; // res will contain number of set bits to be flipped
    int count = 0;
    while(n){
        n = n& (n-1);
        count++;
    }
    return count;
}

int main(){
    
    int a =5;
    int b =7;
    cout<<"before swap: a = "<< a<< ", b = " << b<<endl;
    swap(a, b);
    cout<<"after swap: a = "<< a<< ", b = " << b<<endl;

    cout<<"isOdd: " << isOdd(1023)<<endl;
    cout<<"isEven: "<< isEven(1024)<<endl;
    return 0;
}