# Seven different symbols represent Roman numerals with the following values:
# Symbol	Value
# I	1
# V	5
# X	10
# L	50
# C	100
# D	500
# M	1000

# Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

#     If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
#     If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
#     Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.

# Given an integer, convert it to a Roman numeral.

 

# Example 1:

# Input: num = 3749

# Output: "MMMDCCXLIX"

# Explanation:

# 3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
#  700 = DCC as 500 (D) + 100 (C) + 100 (C)
#   40 = XL as 10 (X) less of 50 (L)
#    9 = IX as 1 (I) less of 10 (X)
# Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

# Example 2:

# Input: num = 58

# Output: "LVIII"

# Explanation:

# 50 = L
#  8 = VIII

# Example 3:

# Input: num = 1994

# Output: "MCMXCIV"

# Explanation:

# 1000 = M
#  900 = CM
#   90 = XC
#    4 = IV

 

# Constraints:

#     1 <= num <= 3999

class Solution:
    def intToRoman(self, num: int) -> str:
        value_symbols = [
            (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
            (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'), (10, 'X'),
            (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
        ]
        
        res = []

        for value, symbol in value_symbols:
            if num == 0:
                break
            count = num // value
            res.append(symbol * count)
            num -= count * value

        return ''.join(res)     

#alternative
class Solution:
    def intToRoman(self, num: int) -> str:
        roman = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        n = num
        ans = ""
        while n != 0:
            if n >= 1000:
                ans += "M"*(int(n/1000))
                n = n%1000
            
            if n >= 900:
                ans += "CM"*(int(n/900))
                n = n%900

            if n >= 500:
                ans +="D"*int(n/500)
                n = n%500
            
            if n >= 400:
                ans += "CD"*(int(n/400))
                n = n%400
            
            if n >= 100:
                ans +="C"*(int(n/100))
                n = n%100
            
            if n >= 90:
                ans +="XC"*(int(n/90))
                n = n%90

            if n >= 50:
                ans +="L"*(int(n/50))
                n = n%50
            
            if n >= 40:
                ans += "XL"*(int(n/40))
                n = n%40
            
            if n >= 10:
                ans += "X"*(int(n/10))
                n = n%10
            
            if n >= 9:
                ans += "IX"*(int(n/9))
                n = n%9
            
            if n >= 5:
                ans += "V"*(int(n/5))
                n = n%5

            if n >= 4:
                ans += "IV"*(int(n/4))
                n = n%4
            
            if n >= 1:
                ans += "I"*(int(n/1))
                n = n%1
            
        return ans
                




