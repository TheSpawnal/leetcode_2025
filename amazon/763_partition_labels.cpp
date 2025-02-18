
//single pass
class Solution{
public:
    vector<int> partitionLabels(string s){
        vector<int> ans;
        int pos;
        int len = 0;
        for(int i =0; i< s.length();i++){
            pos = s.find_last_of(s[i]);
            len = pos-i+1;
            for(int j = i + 1; j  <pos; j++){
                if(s.find_last_of(s[j])>pos)
                    pos=s.find_last_of(s[j]);
                len = pos - i + 1;
            }
            i = pos;
            ans.push_back(len);
        }
        return ans;
    }
};

//could have use unordered_map
class Solution{
public:
    vector<int> partitionLabels(string s){
        unordered_map<char, int> idx;
        for (int i =0;i < s.size(); i++){
            idx[s[i]] = i;
        }
        vector<int> res;
        int start = 0;
        int end = 0 ;
        for (int i = 0; i < s.size(); i++){
            end = max(end, idx[s[i]]);
            if(i == end){
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
};