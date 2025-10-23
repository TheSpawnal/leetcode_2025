# Given a string s, return the longest palindromic substring in s.
# Example 1:
# Input: s = "babad"
# Output: "bab"
# Explanation: "aba" is also a valid answer.
# Example 2:
# Input: s = "cbbd"
# Output: "bb"
# Constraints:
# 1 <= s.length <= 1000
# s consist of only digits and English letters.
#expand around the center
    
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <=1:
            return s
        def expand_from_center(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1:right]

        max_str = s[0]

        for i in range(len(s) -1):
            odd = expand_from_center(i, i)
            even = expand_from_center(i, i + 1)

            if len(odd) > len(max_str):
                max_str = odd 
            if len(even) > len(max_str):
                max_str = even

        return max_str

#memory friendly improvement
class Solution:
    def longestPalindrome(self, s: str)-> str:
        if s == s[::-1]:
            return s
        max_size = len(s)
        window_size = max_size -1
        while window_size > 1:
            for i in range(max_size - window_size +1):
                sub_str = s[i:window_size+i]
                if sub_str == sub_str[::-1]:
                    return sub_str
            window_size -= 1
    return s[0]


        
