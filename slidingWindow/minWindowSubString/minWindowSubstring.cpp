#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
/*
    Given 2 strings s & t, return min window substring
    of s such that all chars in t are included in window
    Ex. s = "ADOBECODEBANC" t = "ABC" -> "BANC"
    Sliding window + hash map {char -> count}
    Move j until valid, move i to find smaller
    Time: O(m + n)
    Space: O(m + n)
*/
class Solution{

public:
    string minWindowSubstr(string s, string t){

        unordered_map<char, int> charCountMap;

        int l =0;int r =0;
        
        // update the map with char count
        for (size_t i = 0; i < t.length(); i++)
        {
            charCountMap[t[i]]++;
        }

        int counter = t.size();
        int minStart = 0;
        int minLength =  INT32_MAX;
        while (r<s.length())
        {
            if(charCountMap[s[r]] > 0){ // found a char from t
                counter--;
            }
            charCountMap[s[r]]--;
            // as long as t is present in  window range
            while (counter == 0)
            {
                if((r - l + 1) < minLength){
                    minStart =l;
                    minLength = r-l+1;
                }
                //move left pointer to shorten window
                charCountMap[s[l]]++;

                if(charCountMap[s[l]] > 0){
                    counter++;
                }
                l++;
            }
            r++;
            
        }
        
        if(minLength != INT32_MAX){
            return s.substr(minStart, minLength);
        }
        return " ";
    }

}; 

int main(){

    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    string minSubstring = sol.minWindowSubstr(s, t);
    cout << "minSubstring for s, t is: "<< minSubstring<<endl;;

    string s1 = "a", t1 = "a";
    string minSubstringS1T1 = sol.minWindowSubstr(s1, t1);
    cout << "minSubstring for s1, t1 is: "<< minSubstringS1T1<<endl;

    string  s2 = "a", t2 = "aa";
    string minSubstringS2T2 = sol.minWindowSubstr(s2, t2);
    cout << "minSubstring for s2, t2 is: "<< minSubstringS2T2<<endl;

    string  s3 = "ab", t3 = "a";
    string minSubstringS3T3 = sol.minWindowSubstr(s3, t3);
    cout << "minSubstring for s3, t3 is: "<< minSubstringS3T3<<endl;
    return 0;
}