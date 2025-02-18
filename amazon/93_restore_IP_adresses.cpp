// A valid IP address consists of exactly four integers separated by single dots. 
// Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, 
// but "0.011.255.245", "192.168.1.312" and "192.168@1.1" 
// are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP 
// addresses that can be formed by inserting dots into s. 
// You are not allowed to reorder or remove any digits in s. 
// You may return the valid IP addresses in any order.

 

// Example 1:
// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]

// Example 2:
// Input: s = "0000"
// Output: ["0.0.0.0"]

// Example 3:
// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

// Constraints:
// 1 <= s.length <= 20
// s consists of digits only.



//recursive backtracking
class Solution{
public: 
    vector<string> restoreIpAddresses(string s){
        vector<string> result;
        backtrack(s,0,0,"",result);
        return result;
    }
private:
    void backtrack(const string &s, int start, int dots, string path, vector<string> &result){
        if(dots == 4 && start == s.size()){
            result.push_back(path.substr(0, path.size()-1)); // remove trailling dots
            return;
        }
        if(dots > 4 || start >= s.size()){
            return;
        }
        for(int len = 1; len <= 3 && start + len <= s.size(); len++){
            string segment = s.substr(start, len);
            if(isValid(segment)){
                backtrack(s,start + len, dots + 1, path + segment + ".", result);
            }
        }
    }
    bool isValid(const string &segment){
        if(segment.size() > 3 || (segment[0] == '0' && segment.size() > 1)) return false;
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }
};

//iterative aaproach using nested loops
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.size();
        for (int i = 1; i <= 3 && i < n - 2; ++i) {
            for (int j = i + 1; j <= i + 3 && j < n - 1; ++j) {
                for (int k = j + 1; k <= j + 3 && k < n; ++k) {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j - i);
                    string s3 = s.substr(j, k - j);
                    string s4 = s.substr(k);
                    if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                        result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return result;
    }

private:
    bool isValid(const string &segment) {
        if (segment.size() > 3 || segment.empty()) return false;
        if (segment[0] == '0' && segment.size() > 1) return false;
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }
};
