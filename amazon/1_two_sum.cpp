
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> m1;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(m1.count(target-nums[i])){
                ans.push_back(m1[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            m1[nums[i]] = i;
        }
        return nums;
    }
};