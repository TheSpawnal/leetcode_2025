

from itertools import zip_longest

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        #split the version strings by '.' and map each part to an integer
        v1 = map(int, version1.split('.'))
        v2 = map(int, version2.split('.'))

        #use zip_longest to iterate trhough both lists, filling missing values with 0
        for rev1, rev2 in zip_longest(v1, v2, fillvalue =0):
            if rev1 < rev2:
                return -1
            if rev1 > rev2:
                return 1
            
        return 0
        

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # Split the version strings into lists of integers
        v1 = list(map(int, version1.split('.')))
        v2 = list(map(int, version2.split('.')))
        
        # Determine the maximum length between the two lists
        max_length = max(len(v1), len(v2))
        
        # Iterate through the revisions and compare them
        for i in range(max_length):
            # Use 0 for missing revisions in shorter list
            rev1 = v1[i] if i < len(v1) else 0
            rev2 = v2[i] if i < len(v2) else 0
            
            if rev1 < rev2:
                return -1
            if rev1 > rev2:
                return 1
        
        # If all revisions are equal
        return 0
