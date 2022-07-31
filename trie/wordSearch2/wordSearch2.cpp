#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/**
 * @brief 
 * 
 * https://leetcode.com/problems/word-search-ii/
 */

/*
    Given a board of characters & a list of words, return all words on the board
    Implement trie, for search: iterate thru children until isWord, add to result
    Time: O(m x (4 x 3^(l - 1))) -> m = # of cells, l = max length of words
    Space: O(n) -> n = total number of letters in dictionary (no overlap in Trie)
*/

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
        
        int m = board.size();
        int n = board[0].size();
        
        TrieNode* node = root;
        vector<string> result;
        // start from each cell and search for word using dfs
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, i, j, m, n, node, "", result);
            }
        }
        
        return result;
    }
private:
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        
        node->isWord = true;
    }

    void search(vector<vector<char>>& board, int i, int j, int m, int n, TrieNode* node, string word, vector<string>& result) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') {
        return;
    }
    
    char c = board[i][j];
    
    node = node->children[c - 'a'];
    if (node == NULL) {
        return;
    }
    
    word += c;
    if (node->isWord) {
        result.push_back(word);
        node->isWord = false;
    }
    
    board[i][j] = '#';
    
    search(board, i - 1, j, m, n, node, word, result);
    search(board, i + 1, j, m, n, node, word, result);
    search(board, i, j - 1, m, n, node, word, result);
    search(board, i, j + 1, m, n, node, word, result);
    // backtrack once this dfs search is done
    board[i][j] = c;
}
    
};

int main(){

    vector<vector<char> > board{{'o','a','a','n'},
                                {'e','t','a','e'},
                                {'i','h','k','r'},
                                {'i','f','l','v'}};

    vector<string> words = {"oath","pea","eat","rain"};
    Solution sol;
    vector<string> result = sol.findWords(board, words);

    for (auto &&st : words)
    {
        cout<< st <<", ";
    }
     
    return 0;
}