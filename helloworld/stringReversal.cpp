// reverse a string
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void reverseString(string& s){

    int l = s.length();
    for(int i=0; i< l/2;i++){
        swap(s[i], s[l-i-1]);
    }
}
void reverseStrRec(string &s, int b, int e){
    if(e<b)
        return;
    swap(s[b], s[e]);
    reverseStrRec(s, b+1, e-1);
}

void getreverse(string &str, int i)
{
    if (i > (str.length() - 1 - i))
    {
        return;
    }
    swap(str[i], str[str.length() - i - 1]);
    i++;
    getreverse(str, i);
}


int main() {

    string s1 = "abcd";
    string s2 = "({[]}]";
    // reverseString(s1);
    // reverseStrRec(s1, 0, s1.length()-1);
    getreverse(s1,0);
    cout<<"reverseString in s1:"<< s1 <<endl;
    return 0;
}