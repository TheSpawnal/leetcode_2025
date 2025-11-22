'''You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

    For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.

Return an array of the starting indices of all the concatenated substrings in s. 
You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] 
which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] 
which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". 
It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". I
t is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". 
It is the concatenation of ["the","foo","bar"].

 

Constraints:

    1 <= s.length <= 104
    1 <= words.length <= 5000
    1 <= words[i].length <= 30
    s and words[i] consist of lowercase English letters.


'''



class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        count = {}
        for i in words:
            count[i] = count.get(i, 0) + 1
        length = len(words[0]) *len(words)
        single = len(words[0])
        res = []
        for offsets in range(single):
            left = offsets
            curr = {}
            window = 0
            for right in range(offsets, len(s), single):
                slices = s[right:right+single]
                if slices in count:
                    curr[slices] = curr.get(slices, 0) + 1
                    window += 1
                    while curr[slices] > count[slices]:
                        left_word = s[left:left + single]
                        curr[left_word] -= 1
                        if curr[left_word] == 0:
                            del curr[left_word]
                        left += single
                        window -= 1
                    if window * single == length:
                        if count == curr:
                            res.append(left)
                else:
                    left = right + single
                    curr.clear()
                    window = 0

        return res
