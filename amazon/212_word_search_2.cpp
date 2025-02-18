
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};


class Solution{
public:

    int dir[5] = {-1, 0,1,0,-1};
    //func to add a word to the Trie
    void addWord(TrieNode* root, const string& word){
        TrieNode* node = root;
        for(char ch: word){
            if(!node-> children[ch])
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isWord = true;
    }

    void dfs(vector<string>& result, TrieNode* node, vector<vector<char>>& board, int i, int j, string& currentWord){
        char ch = board[i][j];
        if(!node->children[ch])return;

        node = node->children[ch];
        currentWord.push_back(ch);
        
        if(node->isWord){
            result.push_back(currentWord);
            node->isWord = false;
        }
        //mark the board position as visited by replacing it with a special character
        board[i][j] = '#';

        for(int k =0;k<4;k++){
            int n_i = i + dir[k];
            int n_j = j + dir[k+1];
            if(n_i >=0 && n_j >= 0 && n_i < board.size() && n_j < board[0].size() && board[n_i][n_j] != '#'){
                dfs(result, node, board, n_i, n_j, currentWord);
            }
        }
        board[i][j] = ch;
        currentWord.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        TrieNode* root = new TrieNode();
        for(const string& word: words){
            addWord(root, word);
        }
        vector<string> result;
        string currentWord;

        for(int i =0; i < board.size();i++){
            for(int j = 0; j < board[0].size(); j++){
                if(root->children[board[i][j]]){
                    dfs(result, root, board, i, j, currentWord);
                }
            }
        }
        return result;
        
    }
};