
/* 
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
Constraints:
1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//struct to hold word-frequency pairs
typedef struct {
    int freq;
    char word[11];//assuming max word length is 10
} WordFreq;

//comparator function qsort
int compare(const void *a, const void *b){
    WordFreq *wf1 = (WordFreq *)a;
    WordFreq *wf2 = (WordFreq *)b;

    if(wf1->freq != wf2->freq){
        return wf2->freq - wf1->freq; //sort by frequency in desc order
    }else{
        return strcmp(wf1->word, wf2->word);
    }
}
//func to find the k most frequent words;
char** topKFrequent(char** words, int wordsSize, int k, int* returnSize){
    //create frequency map
    WordFreq* freqMap = (WordFreq*) malloc(wordsSize * sizeof(WordFreq));
    int uniqueCount = 0;
    //count the freq of each word
    for(int i = 0; i < wordsSize; i++){
        int found = 0;
        for(int j = 0; j < uniqueCount; j++){
            if(strcmp(words[i], freqMap[j].word) == 0){
                freqMap[j].freq++;
                found = 1;
                break;
            }
        }
        if(!found){
            strcpy(freqMap[uniqueCount].word, words[i]);
            freqMap[uniqueCount].freq = 1;
            uniqueCount++;
        }
    }
    qsort(freqMap, uniqueCount, sizeof(WordFreq), compare);
    char** result = (char**)malloc(k * sizeof(char*));
    for(int i = 0; i < k; i++){
        result[i] = (char*)malloc(11 * sizeof(char));
        strcpy(result[i], freqMap[i].word);
    }
    *returnSize = k;
    free(freqMap);
    return result;

}