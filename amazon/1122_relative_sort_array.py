
'''Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]

 

Constraints:

    1 <= arr1.length, arr2.length <= 1000
    0 <= arr1[i], arr2[i] <= 1000
    All the elements of arr2 are distinct.
    Each arr2[i] is in arr1.

'''

#using counting sort
class Solution:
    def relativeSortArray(self, arr1, arr2):
        from collections import defaultdict

        count_map = defaultdict(int)
        remaining = []
        result = []

        # Initialize count map with relative order elements
        for num in arr2:
            count_map[num] = 0

        # Count occurrences of elements in target array
        for num in arr1:
            if num in count_map:
                count_map[num] += 1
            else:
                remaining.append(num)

        # Sort the remaining elements
        remaining.sort()

        # Add elements as per relative order
        for num in arr2:
            result.extend([num] * count_map[num])

        # Add remaining elements
        result.extend(remaining)

        return result


#using hashmap for counting and sorting
class Solution:
    def relativeSortArray(self, arr1, arr2):
        from collections import defaultdict
        
        count_map = defaultdict(int)
        remaining = []
        result = []
        
        for num in arr2:# Initialize count map with relative order elements
            count_map[num] = 0

        
        for num in arr1:# Count occurrences of elements in target array
            if num in count_map:
                count_map[num] += 1
            else:
                remaining.append(num)

        # Sort the remaining elements
        remaining.sort()

        # Add elements as per relative order
        for num in arr2:
            result.extend([num] * count_map[num])

        # Add remaining elements
        result.extend(remaining)

        return result




#0ms

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        i_dict = {}
        for i, num in enumerate(arr2):
            i_dict[num] = i

        res = []
        temp = []

        for num in arr1:
            if num in i_dict:
                res.append((num, i_dict[num]))
            else:
                temp.append(num)

        res = sorted(res, key=lambda x: x[1])
        temp.sort()

        res = [pair[0] for pair in res]
        res.extend(temp)

        return res
