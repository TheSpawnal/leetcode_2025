
// Given an integer array nums, return an array answer such that answer[i] 
// is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in 
// a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without 
// using the division operation.

 

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:
// 2 <= nums.length <= 10^5
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//two passes with auxiliary arrays
class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        vector<int> left(n, 1), right(n,1), result(n, 1);
        //calculate left products
        for(int i = 1; i < n; i++){
            left[i] = left[i - 1] * nums[i - 1];
        }
        //right prod
        for(int i = n -2; i >= 0 ; i--){
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i =0; i < n; i++){
            result[i] = left[i] * right[i];
        }
        return result;
    }
};

//single pass with o(1) sapce(excluding the result array)
class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        vector<int> result(n, 1);
        //first pass to calculate products of elements before each index
        int prefix = 1;
        for(int i =0; i < n; i++){
            result[i] = prefix;
            prefix *= nums[i];
        }
        //second pass to calculate products of elements after each index
        int suffix = 1;
        for(int i = n -1; i >= 0 ; i--){
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};