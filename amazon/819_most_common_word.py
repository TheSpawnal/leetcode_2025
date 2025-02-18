# Given a string paragraph and a string array of the banned words banned,
# return the most frequent word that is not banned. It is guaranteed there
# is at least one word that is not banned, and that the answer is unique.

# The words in paragraph are case-insensitive and the answer should be 
# returned in lowercase.

# Example 1:
# Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
# Output: "ball"
# Explanation: 
# "hit" occurs 3 times, but it is a banned word.
# "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
# Note that words in the paragraph are not case sensitive,
# that punctuation is ignored (even if adjacent to words, such as "ball,"), 
# and that "hit" isn't the answer even though it occurs more because it is banned.
# Example 2:

# Input: paragraph = "a.", banned = []
# Output: "a"

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        #using max and key function
        dict = {}
        banned = set(banned)
        for c in "!?',;./"":
            paragraph = paragraph.replace(c, " ")
        paragraph = paragraph.lower().split()

        for word in paragraph:
            if word not in banned:
                if word in dict:
                    dict[word] += 1
                else:
                    dict[word] = 1
        #dont need a counter if you use max and key function
        return max(dict, key = dict.get)


# The time complexity of the modified code is O(n), where n is the length of
# the paragraph. This is because we iterate through each character in the
# paragraph to replace punctuation marks and split the paragraph into words. 
# Additionally, we iterate through each word in the paragraph to check 
# if it is banned and update the frequency count in the dictionary.

# The space complexity of the modified code is O(m), where m is the 
# number of unique words in the paragraph. This is because we store 
# the frequency count of each unique word in the dictionary. 
# The space used by the banned set is also O(m), as it contains 
# the unique banned words.



