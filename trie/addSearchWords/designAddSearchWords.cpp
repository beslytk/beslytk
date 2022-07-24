#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
/*
    Design add & search words data structure
    Implement trie, handle wildcards: traverse all children & search substrings
    Time: O(m x 26^n) -> m = # of words, n = length of words
    Space: O(n)
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

class WordDictionary {

 
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {

        TrieNode* curr = root;

        for (auto &&c : word)
        {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWordEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        return searchInNode(word, 0, curr);
    }
private:
    // recursive search required, since we have wildcard support in input entry
    bool searchInNode(string& word, int index, TrieNode* node){
        if(!node){
            // if node not present, word cant be formed with this branch
            return false;
        }
        // if index reached word-end, return if the currNode is marked as word-end
        if( index == word.size()){
            return node->isWordEnd;
        }

        // if the index points to wildcard, recursively try all 26 char nodes
        if(word[index] == '.'){
            for (size_t alph = 0; alph < 26; alph++){
                // if any node,returned true after full recursion, return true at this level
                if(searchInNode(word, index+1, node->children[alph])){
                    return true;
                }
            }
            
        }else{
            // check if the child corresponding to char at index of word is present
            // first thing checked in recursive call is if the passd node is present
            return searchInNode(word, index+1, node->children[word[index] - 'a']);
        }
        return false;
    }
   
    TrieNode* root;
};

int main(){
    WordDictionary wordDictionary = WordDictionary();
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout<<"search for 'pad' returned: " <<wordDictionary.search("pad")<<endl; // return False
    cout<<"search for 'bad' returned: " <<wordDictionary.search("bad")<<endl; // return True
    cout<<"search for '.ad' returned: " <<wordDictionary.search(".ad")<<endl; // return True
    cout<<"search for 'b..' returned: " <<wordDictionary.search("b..")<<endl; // return True
    return 0;
}