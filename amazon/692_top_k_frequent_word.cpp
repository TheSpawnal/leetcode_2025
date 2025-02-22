
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Frequency map to count occurrences of each word
        unordered_map<string, int> freq;
        
        // Count frequency of each word
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
            const string& word = *it;
            freq[word]++;
        }
        
        // Custom comparator for the priority queue
        struct Comparator {
            bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
                if (a.first == b.first) {
                    return a.second > b.second; // Sort lexicographically if frequencies are equal
                }
                return a.first < b.first; // Sort by frequency in descending order
            }
        };
        
        // Declare the priority queue with the custom comparator
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> pq;
        
        // Push elements into the priority queue
        for (unordered_map<string, int>::const_iterator it = freq.begin(); it != freq.end(); ++it) {
            pq.emplace(it->second, it->first);
        }
        
        // Extract the top k elements
        vector<string> result;
        while (k-- > 0 && !pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};