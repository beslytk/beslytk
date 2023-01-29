#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

char lowerToUpper(char ch){
    return char(ch & '_');
}

char upperToLower(char ch){
    return char(ch | ' ');
} 

char invertCase(char ch){
    return char(ch ^ ' ');
} 

//case insensitive
int getLetterIndex(char ch){
    return int(ch & 31);
} 

int main(){

    cout<<"when converting a to upper: "<<lowerToUpper('a')<<endl; 
    cout<<"when converting A to lower: "<<upperToLower('A')<<endl; 
    cout<<"when inverting case of A: "<<invertCase('A')<<endl; 
    cout<<"when inverting case of a: "<<invertCase('a')<<endl; 

    cout<<"char a is the "<<getLetterIndex('a')<< " th alphabet"<<endl; 
    cout<<"char C is the "<<getLetterIndex('C')<< " th alphabet"<<endl; 

    return 0;
}
// ->the ASCI code of space ' '      is 00100000. 32
// ->the ASCI code of underscore '_' is 01011111
// Bitwise OR of an uppercase character with " " will set the third
// significant bit and we will get lowercase character.
// -> Bitwise AND of a lowercase character with '_' will unset /clear
// the third bit and we will get uppercase character.
// -> Bitwise XOR of an uppercase or lowercase characters with a ' '
// (space), will toggle the third significant bit.
// Uppercase becomes lowercase and vice versa