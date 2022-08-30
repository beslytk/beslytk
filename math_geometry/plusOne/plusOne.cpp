#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            //first digit<9 should be able to add 1(or carried forward number from previous digit) without generating carry. Then return already
            if (digits[i] < 9) { 
                digits[i]++;
                return digits; 
            }
            digits[i] = 0;
        }
        // if not already returned, the MSB digit is 9, therefore
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
}; 

int main(){

    Solution sol;
    vector<int> in{9,1, 9};
    vector<int>res = sol.plusOne(in);

    for (auto &&i : res)    
    {
        cout<<i<<",";
    }
    
    
    return 0;
}