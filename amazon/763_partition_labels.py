
"""
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 
"""


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        #determine the last occurence of each character:
        last_occurence = [0]*26
        for i in range(len(s)):
            last_occurence[ord(s[i])-ord('a')]=i
        #traverse the string and find partitions
        partitions = []
        start = 0
        end = 0
        for i in range(len(s)):
            end = max(end, last_occurence[ord(s[i]) -ord('a')])
            if i == end:
                partitions.append(i - start + 1)
                start = i + 1

        return partitions


#30ms
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastIndexMap = {}

        for i, c in enumerate(s):
            lastIndexMap[c] = i

        LastEnd, size = 0, 0
        result = []
        for i, c in enumerate(s):
            size += 1
            lastEnd = max(LastIndexMap[c], lastEnd)
            if i == lastEnd:
                result.append(size)
                size =0
                lastEnd=0

        return result