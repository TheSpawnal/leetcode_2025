from collections import defaultdict
from collections import deque
from typing import List
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0
        L = len(beginWord)
        all_combo_dict = defaultdict(list)
        for word in wordList:
            for i in range(L):
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word) 
        queue = deque([(beginWord, 1)])
        visited = set()
        visited.add(beginWord)
        while queue:
            current_word, level = queue.popleft()
            for i in range(L):
                intermediate_word = current_word[:i] + "*" + current_word[i+1:]
                for word in all_combo_dict[intermediate_word]:
                    if word == endWord:
                        return level + 1
                    if word not in visited:
                        visited.add(word)
                        queue.append((word, level + 1))
        return 0

def main():
    beginWord = input("Enter beginWord: ")
    endWord = input("Enter endWord: ")
    n = int(input("Enter number of words in wordList: "))

    wordList = []
    print("Enter words in wordList: ")
    for _ in range(n):
        wordList.append(input())

    solution = Solution()
    result = solution.ladderLength(beginWord, endWord, wordList)
    print("Output:", result)

if __name__ == "__main__":
    main()