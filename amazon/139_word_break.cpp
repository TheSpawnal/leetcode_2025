

// Given a string s and a dictionary of strings wordDict, 
// return true if s can be segmented into a space-separated 
// sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple 
// times in the segmentation.

 

// Example 1:
// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.size();i++)
            for (int j = 0; j < i ; j++)
                if((dp[j]) && (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())){
                    dp[i] = true;
                    break;
                    
                }
            return dp.back();

    }
};

//memoized dp 
class Solution{
private:
    class Tmort{
    public:
        char data;
        Tmort *child[26];
        bool point_end;

        Tmort(char ch){
            this->data = ch;
            for(int i =0 ; i < 26; i++){
                child[i] = NULL;
            }
            this->point_end = false;
        }
    };
    void addNodeT(string word, Tmort* root, int idx){
        if(idx >= word.length()){
            root->point_end = true;
            return;
        }
        char ch = word[idx]; 
        int index = ch - 'a';
        if(root->child[index] == NULL){
            root->child[index] = new Tmort(ch);
        }
        root = root->child[index];
        addNodeT(word, root, idx + 1); 
    }
    Tmort *org = NULL;
    unordered_map<int, bool> memo;
    bool solve(Tmort* root, string s , int start){
        if(start >= s.length()){
            return true;
        }
        if(memo.find(start) != memo.end()){
            return memo[start];
        }
        for(int i = start; i < s.length(); i++){
            char ch = s[i];
            int idx = ch - 'a';

            if(root->child[idx]==NULL){
                memo[start]= false;
                return false;
            }
            root = root->child[idx];
            if(root->point_end){
                bool x = solve(org, s ,i+1);
                if(x){
                    memo[start] = true;
                    return true;
                }
            }
        }
        memo[start] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict){
        Tmort *root = new Tmort('*');
        org = root;
        bool ans = false;
        for (auto it : wordDict){
            addNodeT(it, root, 0);
        }
        ans = solve(root, s, 0);
        return ans;
    }
};