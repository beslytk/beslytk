#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class encodeDecode
{
private:
    /* data */
public:
    string encode(vector<string>& strList){
        
        string s = "";
        for (auto str : strList)
        {
            s += to_string(str.size()) + "#" + str;
        }
        return s;
    }

    vector<string> decode(string& st);
};

vector<string> encodeDecode::decode(string& enStr)
{
    int i=0;
    vector<string> decStrList;
    while (i<enStr.size())
    {
        int j=i;
        //In C++ the single quote is used to identify the single character, 
        //and double quotes are used for string literals. A string literal “x” is a string, 
        //it is containing character ‘x’ and a null terminator ‘\0’.
        while (enStr[j] != '#') 
        {
            j++;
        }
        int decStrLen = stoi(enStr.substr(i, j-i));
        string decStr = enStr.substr(j+1, decStrLen );
        decStrList.push_back(decStr);
        i = j+1+decStrLen;
    }
    return decStrList;
}

int main(){
    
    encodeDecode enDe;
    vector<string> strL {"leet", "co#de"};
    string enStr = enDe.encode(strL);
    vector<string> deStr = enDe.decode(enStr);
    for (auto &&str : deStr)
    {
        cout<<str<<", ";
    }
    return 0;
}