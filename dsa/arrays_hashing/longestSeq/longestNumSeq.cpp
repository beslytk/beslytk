#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

int longestSeq(vector<int>& numArr){

    unordered_set<int> s(numArr.begin(),numArr.end());

    int longest = 0;
    for(auto it = s.begin();it !=s.end(); it++)
    {
        int currNum = *it;
        if(s.find(currNum - 1) != s.end()){
            continue;
        }
        int currLenght = 1;
        while (s.find(currNum + 1) != s.end())
        {
            currLenght++;
            currNum++;
        }
        longest = max(longest, currLenght);

    }
    return longest;
} 

int main(){
    
    vector<int> numVec {100,4,200,1,3,2};
    int longestSeqL = longestSeq(numVec);
    cout<<longestSeqL<<endl;
    return 0;
}