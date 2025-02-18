// Given a string paragraph and a string array of the banned words banned,
// return the most frequent word that is not banned. It is guaranteed there
// is at least one word that is not banned, and that the answer is unique.
// The words in paragraph are case-insensitive and the answer should be 
// returned in lowercase.
// Example 1:
// Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
// Output: "ball"
// Explanation: 
// "hit" occurs 3 times, but it is a banned word.
// "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
// Note that words in the paragraph are not case sensitive,
// that punctuation is ignored (even if adjacent to words, such as "ball,"), 
// and that "hit" isn't the answer even though it occurs more because it is banned.
// Example 2:
// Input: paragraph = "a.", banned = []
// Output: "a"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <cctype>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Convert paragraph to lowercase and replace punctuation with spaces
        for (int i = 0; i < paragraph.length(); ++i) {
            if (isalpha(paragraph[i])) {
                paragraph[i] = tolower(paragraph[i]);
            } else {
                paragraph[i] = ' ';
            }
        }
        // Split the paragraph into words
        stringstream ss(paragraph);
        string word;
        unordered_map<string, int> wordCount;
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        
        // Count the words, ignoring banned words
        while (ss >> word) {
            if (bannedSet.find(word) == bannedSet.end()) {
                if (wordCount.find(word) == wordCount.end()) {
                    wordCount[word] = 1;
                } else {
                    wordCount[word]++;
                }
            }
        }
        // Find the word with the highest frequency
        string result;
        int maxCount = 0;
        for (unordered_map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) {
            if (it->second > maxCount) {
                maxCount = it->second;
                result = it->first;
            }
        }
        return result;
    }
};

