
#tw passes with auxiliary arrays
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [1] * n 
        right = [1] * n 
        result = [1] * n
        #build  the left products array
        for i in range (1, n):
            left[i] = left[i-1] * nums[i-1]
        #build the right products array
        for i in range(n - 2, -1, -1):
            right[i] = right[i+1]*nums[i+1]
        #build the result by multiplying the left and right products
        for i in range(n):
            result[i] = left[i]*right[i]

        return result
        

#Single passe 
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1]*n
        #first pass: calculate products of elemts before each index
        prefix = 1
        for i in range(n):
            result[i] = prefix
            prefix *= nums[i]

        #second pass: calculate products of elemts after each index
        suffix = 1 
        for i in range(n-1, -1, -1):
            result[i] *= suffix
            suffix *= nums[i]

        return result