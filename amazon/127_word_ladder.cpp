
//BFS two pointers.
#include<string>
#include<vector>
#include <unordered_set>
#include<iostream>

using namespace std;

class Solution{
public: 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail,*phead, *ptail;
        if(dict.find(endWord)==dict.end()){
            return 0;
        }
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;
        while(!head.empty() && !tail.empty()){
            if(head.size() < tail.size()){
                phead = &head;
                ptail = &tail;
            }else{
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for(auto it = phead -> begin(); it != phead -> end();it++){
                string word = *it;
                for(int i =0 ; i< word.size(); i++){
                    char t = word[i];
                    for(int j = 0; j < 26; j++){
                        word[i] = 'a' + j;
                        if(ptail->find(word) != ptail -> end()){
                            return ladder;
                        }
                        if(dict.find(word) != dict.end()){
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i]=t;
                }
            }
            ladder++;
            phead->swap(temp);
        }
        return 0;
    }
};

int main(){
    string beginWord, endWord;
    int n;
    cout << "Enter beginWord: ";
    cin >> beginWord;
    cout << "Enter endWord: ";
    cin >> endWord; 
    cout << "Enter number of words in wordList: ";
    cin >> n;
    vector<string> wordList(n);
    cout << "Enter words in wordList:\n";
    for(int i =0; i < n ; i++){
        cin >> wordList[i];
    }
    Solution my_solution;
    int result = my_solution.ladderLength(beginWord, endWord, wordList);
    cout << "Output: "<< result << endl;
    return 0;
}