
'''
Given a string containing just the characters '(' and ')', 
return the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 
Constraints:
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
'''

# #DP
# Track length of valid sustring ending at each position
# time: O(n), Space: O(n)

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        
        dp = [0] * n
        max_len = 0
        
        for i in range(1,n):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = (dp[i- 2] if i >= 2 else 0) + 2
                elif i - dp[i - 1]> 0 and s[i - dp[i - 1] - 1] == '(':
                    dp[i] = dp[i - 1] + 2 + (dp[i - dp[i - 1] - 2] if i - dp[i - 1] >= 2 else 0)
                
                max_len = max(max_len, dp[i])
        
        return max_len

'''
DP Logic:
dp[i] = length of longest valid substring ending at index i

Case 1: s[i-1:i+1] = "()"
  dp[i] = dp[i-2] + 2

Case 2: s[i-1:i+1] = "))" and matching '(' exists
  j = i - dp[i-1] - 1  (position before valid substring ending at i-1)
  if s[j] == '(':
    dp[i] = dp[i-1] + 2 + dp[j-1]
    '''

""" Stack-Based
Concept: Track indices of unmatched parentheses
Time: O(n), Space: O(n)"""
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        max_len = 0
        
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    max_len = max(max_len, i - stack[-1])
        
        return max_len

'''
Stack Logic:
Initialize: stack = [-1]  (base for calculating length)
For '(':
  - Push index onto stack

For ')':
  - Pop from stack
  - If stack empty: push current index (new base)
  - Else: current_length = i - stack[-1]
  
Stack bottom always holds index of last unmatched ')'
'''

# Strategy 3: Two-Pass Scan (Optimal Space)
# Concept: Count balance left-to-right, then right-to-left
# Time: O(n), Space: O(1)
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        left = right = max_len = 0
        
        for char in s:
            if char == '(':
                left += 1
            else:
                right += 1
            
            if left == right:
                max_len = max(max_len, 2 * right)
            elif right > left:
                left = right = 0
        
        left = right = 0
        
        for char in reversed(s):
            if char == '(':
                left += 1
            else:
                right += 1
            
            if left == right:
                max_len = max(max_len, 2 * left)
            elif left > right:
                left = right = 0
        
        return max_len

'''
Two-Pass Logic:
Left-to-right:
  - Count '(' and ')'
  - When balanced (left == right): valid substring
  - When right > left: reset (cannot match extra ')')

Right-to-left:
  - Handles cases like "(()" where left > right
  - Catches valid substrings missed in first pass
'''  
