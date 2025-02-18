
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numDict = {}
        n = len(nums)
        for i in range(n) :
            result = target - nums[i]
            if result in numDict :
                return [numDict[result], i]
            if nums[i] not in numDict :
                numDict[nums[i]] = i
        return []