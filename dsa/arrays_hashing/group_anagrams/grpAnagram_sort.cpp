/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Strategy:
    sort each word since after sorting, anagrams will have same representation

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        string temp;
        
        for(auto x:strs)
        {
            temp=x; // preserving the original string
            sort(x.begin(),x.end()); // sorting each string because all anagrams after sorting will result in same string
            
            mp[x].push_back(temp); //grouping each string according to sorted string
        }
        
        for(auto x:mp)
            ans.push_back(x.second); // pushing the answer in vector to return 
        
        return ans;
    }
};

int main(){

    Solution s;
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string> > outArrArr = s.groupAnagrams(strs);
    for(auto outArr: outArrArr){
        for(auto wrd: outArr){
            cout<<wrd<<" ";
        }
        cout<<"\n-----------"<<endl;
    }
    return 0;
}