from collections import deque, defaultdict
from typing import List

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return []

        adj = defaultdict(list)
        visited = set()
        queue = deque([beginWord])
        visited.add(beginWord)
        found = False

        while queue and not found:
            currentLevelVisited = set()
            for _ in range(len(queue)):
                currentWord = queue.popleft()

                for j in range(len(currentWord)):
                    tempWordList = list(currentWord)  # Convert string to list for mutation
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        tempWordList[j] = c
                        tempWord = ''.join(tempWordList)
                        if tempWord in wordSet and tempWord != currentWord:
                            if tempWord == endWord:
                                found = True
                            if tempWord not in visited:
                                if tempWord not in currentLevelVisited:
                                    queue.append(tempWord)
                                    currentLevelVisited.add(tempWord)
                                adj[tempWord].append(currentWord)
            visited.update(currentLevelVisited)

        results = []
        if found:
            path = [endWord]
            self.backtrack(endWord, beginWord, adj, path, results)
        return results

    def backtrack(self, currentWord: str, beginWord: str, adj: dict, path: List[str], results: List[List[str]]):
        if currentWord == beginWord:
            results.append(list(reversed(path)))
            return
        for nextWord in adj[currentWord]:
            path.append(nextWord)
            self.backtrack(nextWord, beginWord, adj, path, results)
            path.pop()

