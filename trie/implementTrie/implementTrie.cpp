#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
/*
    Implement trie (store/retrieve keys in dataset of strings)
    Each node contains pointer to next letter & is word flag
    Time: O(n) insert, O(n) search, O(n) startsWith
    Space: O(n) insert, O(1) search, O(1) startsWith
*/
class TrieNode{
public:
    TrieNode* children[26];
    bool isWordEnd;
    TrieNode(){
        for (size_t i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    
        isWordEnd = false;
    }
};

class Trie {

    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word) {
        
        TrieNode* curr = root;
        for (auto &&c : word)
        {
            int idx = c- 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
                curr = curr->children[idx];
            }

        }
        curr->isWordEnd = true;
        
    }

    bool search(string word) {
        
        TrieNode* curr = root;
        for (auto &&c : word)
        {
            int idx = c-'a';
            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isWordEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto &&c : prefix)
        {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }

};

int main(){
    string word = "apple";
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    cout<<"search for word returned: "<< param_2<<endl;
    string prefix = "app";
    bool param_3 = obj->startsWith(prefix);
    cout<<"search for prefix returned: "<< param_3<<endl;
 
    return 0;
}