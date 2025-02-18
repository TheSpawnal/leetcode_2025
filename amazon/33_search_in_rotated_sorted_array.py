class Solution:
    def search(self, nums, target):
        def find_pivot():
            low, high = 0, len(nums) - 1
            while low < high:
                mid = (low + high) // 2
                if nums[mid] > nums[high]:
                    low = mid + 1
                else:
                    high = mid
            return low
        
        def binary_search(low, high):
            while low <= high:
                mid = (low + high) // 2
                if nums[mid] == target:
                    return mid
                elif nums[mid] < target:
                    low = mid + 1
                else:
                    high = mid - 1
            return -1
        
        n = len(nums)
        if n == 0:
            return -1
        
        pivot = find_pivot()
        
        # If target is the smallest element
        if nums[pivot] == target:
            return pivot
        
        # Decide the search range based on pivot and target
        if pivot == 0:
            return binary_search(0, n - 1)
        elif target < nums[0]:
            return binary_search(pivot, n - 1)
        else:
            return binary_search(0, pivot - 1)
        
        return -1